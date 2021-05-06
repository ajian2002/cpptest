#define PRINTEXIT
#define DEBUGPRINT

#include "mypool.h"
/*TODO
自行完成
*/

ThreadPool *pool_create(int min_thread_count, int max_thread_count, int queue_size_max)
{
    ThreadPool *pool = (ThreadPool *)malloc(sizeof(ThreadPool));
    if (pool == NULL)
    {
        DEBUGPRINT("malloc pool error");
        return NULL;
    }
    else
    {
        memset(pool, 0, sizeof(ThreadPool));
    }

    //pool init
    pthread_mutex_init(&pool->whole_mutex, NULL);
    pthread_mutex_init(&pool->busy_thread_number_mutex, NULL);

    pthread_cond_init(&pool->queue_notfull_cond, NULL);
    pthread_cond_init(&pool->queue_notempty_cond, NULL);

    pool->ordinary_thread_ids = (pthread_t *)malloc(sizeof(pthread_t) * max_thread_count);
    if (pool->ordinary_thread_ids == NULL)
    {
        DEBUGPRINT("malloc treads error");
        pthread_mutex_destroy(&pool->whole_mutex);
        pthread_mutex_destroy(&pool->busy_thread_number_mutex);
        pthread_cond_destroy(&pool->queue_notfull_cond);
        pthread_cond_destroy(&pool->queue_notempty_cond);
        if (pool)
        {
            free(pool);
            pool = NULL;
        }

        return NULL;
    }
    else
    {
        memset(pool->ordinary_thread_ids, 0, sizeof(pthread_t) * max_thread_count);
    }
    pool->management_thread_id = 0;

    pool->task_queue = (Tasks_t *)malloc(sizeof(Tasks_t) * queue_size_max);
    if (pool->task_queue == NULL)
    {
        DEBUGPRINT("malloc queue error");
        pthread_mutex_destroy(&pool->whole_mutex);
        pthread_mutex_destroy(&pool->busy_thread_number_mutex);
        pthread_cond_destroy(&pool->queue_notfull_cond);
        pthread_cond_destroy(&pool->queue_notempty_cond);
        if (pool->ordinary_thread_ids)
        {
            free(pool->ordinary_thread_ids);
            pool->ordinary_thread_ids = NULL;
        }
        if (pool)
        {
            free(pool);
            pool = NULL;
        }

        return NULL;
    }
    else
    {
        memset(pool->task_queue, 0, sizeof(Tasks_t) * queue_size_max);
    }

    pool->min_thread_count = min_thread_count;
    pool->max_thread_count = max_thread_count;
    pool->live_thread_count = 0;
    pool->busy_thread_count = 0;
    pool->wait_exit_thread_count = 0;

    pool->queue_size = 0;
    pool->queue_size_max = queue_size_max;
    pool->queue_front = 0;
    pool->queue_tail = 0;

    pool->if_shall_shutdown = 0;

    //add new thread
    // pthread_attr_t detached_thread_attr;
    // pthread_attr_init(&detached_thread_attr);
    // pthread_attr_setdetachstate(&detached_thread_attr, PTHREAD_CREATE_DETACHED);
    pthread_mutex_lock(&pool->whole_mutex);
    pthread_mutex_lock(&pool->busy_thread_number_mutex);
    for (int i = 0; i < min_thread_count; i++)
    {
        pthread_create(&pool->ordinary_thread_ids[i], NULL, wait_task, (void *)pool);
        pool->live_thread_count++;
        DEBUGPRINT("thread%d :%ld\n", i, pool->ordinary_thread_ids[i]);
    }

    //add adjust thread
    pthread_create(&pool->management_thread_id, NULL, management_task, (void *)pool);
    DEBUGPRINT("memanged:%ld\n", pool->management_thread_id);

    pthread_mutex_unlock(&pool->busy_thread_number_mutex);
    pthread_mutex_unlock(&pool->whole_mutex);
    return pool;
}

void *wait_task(void *ppool)
{
    ThreadPool *pool = (ThreadPool *)ppool;
    while (1)
    {
        pthread_mutex_lock(&pool->whole_mutex);
       
        while (pool->if_shall_shutdown == 0 && pool->queue_size == 0)          //没有任务
            pthread_cond_wait(&pool->queue_notempty_cond, &pool->whole_mutex); //任务不空唤醒
        DEBUGPRINT("get lock\n"); if (pool->wait_exit_thread_count > 0)                                  //准备自尽
        {
            pool->wait_exit_thread_count--;
            if (pool->live_thread_count > pool->min_thread_count)
            { //可以自尽
                pool->live_thread_count--;
                pthread_mutex_unlock(&pool->whole_mutex);
                pthread_exit(NULL);
            }
        }
        if (pool->if_shall_shutdown == 1)
        {
            DEBUGPRINT("pid:%ld exit beause shutdown\n", pthread_self());
            pthread_mutex_unlock(&pool->whole_mutex);
            pthread_exit(NULL); //线程自退出
        }

        //开始干活
        //出任务队列，加忙状态，执行回调，减忙状态

        DEBUGPRINT("pid:%ld weak up\n", pthread_self());
        Tasks_t task;
        task.function = pool->task_queue[pool->queue_front].function;
        task.arg = pool->task_queue[pool->queue_front].arg;
        pool->queue_front = (pool->queue_front + 1) % pool->queue_size_max;
        pool->queue_size--;

        pthread_cond_broadcast(&pool->queue_notfull_cond); //通知任务不满
        pthread_mutex_unlock(&pool->whole_mutex);

        pthread_mutex_lock(&pool->busy_thread_number_mutex);
        pool->busy_thread_count++;
        pthread_mutex_unlock(&pool->busy_thread_number_mutex);

        DEBUGPRINT("pid:%ld do process\n", pthread_self());
        //执行回调
        task.function(task.arg);

        pthread_mutex_lock(&pool->busy_thread_number_mutex);
        pool->busy_thread_count--;
        pthread_mutex_unlock(&pool->busy_thread_number_mutex);
    }
}

void add_task(ThreadPool *pool, void *(*function)(void *arg), void *arg)
{
    pthread_mutex_lock(&pool->whole_mutex);
    while (pool->queue_size == pool->queue_size_max && pool->if_shall_shutdown == 0) //任务满阻塞
        pthread_cond_wait(&pool->queue_notfull_cond, &pool->whole_mutex);

    if (pool->if_shall_shutdown == 1)
    {
        pthread_mutex_unlock(&pool->whole_mutex);
        pthread_exit(NULL); //线程自退出
    }

    pool->task_queue[pool->queue_tail].arg = arg;
    pool->task_queue[pool->queue_tail].function = function;
    pool->queue_tail = (pool->queue_tail + 1) % pool->queue_size_max;
    pool->queue_size++;

    pthread_cond_signal(&pool->queue_notempty_cond);
    pthread_mutex_unlock(&pool->whole_mutex);
}

int is_thread_alive(pthread_t tid)
{
    int kill_rc = pthread_kill(tid, 0); //发0号信号，测试线程是否存活
    if (kill_rc == ESRCH)
    {
        return false;
    }
    return true;
}

void *management_task(void *ppool)
{

    ThreadPool *pool = (ThreadPool *)ppool;
    while (pool->if_shall_shutdown == 0)
    {
        DEBUGPRINT("mang weak up\n");
        sleep(10);
        pthread_mutex_lock(&pool->whole_mutex);
        int queue_size = pool->queue_size;
        int live_thread_count = pool->live_thread_count;
        pthread_mutex_unlock(&pool->whole_mutex);

        pthread_mutex_lock(&pool->busy_thread_number_mutex);
        int busy_thread_count = pool->busy_thread_count;
        pthread_mutex_unlock(&pool->busy_thread_number_mutex);

        /* 创建新线程 算法： 任务数大于最小线程池个数, 且存活的线程数少于最大线程个数时 如：30>=10 && 40<100*/
        int i;
        if (queue_size >= MIN_WAIT_TASK_NUM && live_thread_count < pool->max_thread_count)
        {
            pthread_mutex_lock(&(pool->whole_mutex));
            int add = 0;

            /*一次增加 DEFAULT_THREAD 个线程*/
            for (i = 0; i < pool->max_thread_count && add < DEFAULT_THREAD_VARY && pool->live_thread_count < pool->max_thread_count; i++)
            {
                if (pool->ordinary_thread_ids[i] == 0 || !is_thread_alive(pool->ordinary_thread_ids[i]))
                {
                    pthread_create(&(pool->ordinary_thread_ids[i]), NULL, wait_task, (void *)pool);
                    add++;
                    pool->live_thread_count++;
                }
            }

            pthread_mutex_unlock(&(pool->whole_mutex));
        }

        /* 销毁多余的空闲线程 算法：忙线程X2 小于 存活的线程数 且 存活的线程数 大于 最小线程数时*/
        if ((busy_thread_count * 2) < live_thread_count && live_thread_count > pool->min_thread_count)
        {

            /* 一次销毁DEFAULT_THREAD个线程, 隨機10個即可 */
            pthread_mutex_lock(&(pool->whole_mutex));
            pool->wait_exit_thread_count = DEFAULT_THREAD_VARY; /* 要销毁的线程数 设置为10 */
            pthread_mutex_unlock(&(pool->whole_mutex));

            for (i = 0; i < DEFAULT_THREAD_VARY; i++)
            {
                /* 通知处在空闲状态的线程, 他们会自行终止*/
                pthread_cond_signal(&(pool->queue_notempty_cond));
            }
        }
    }
    return NULL;
}

void *process(void *data)
{
    int c = *(int *)data;
    printf("pid=%ld,data=%d\n", pthread_self(), c);
    //sleep(1);
    return NULL;
}

void pool_destroy(ThreadPool *pool)
{
    pool->if_shall_shutdown = 1;
    pthread_join(pool->management_thread_id, NULL);

    for (int i = 0; i < pool->live_thread_count; i++)
        pthread_cond_broadcast(&pool->queue_notempty_cond);
    for (int i = 0; i < pool->live_thread_count; i++)
        pthread_join(pool->ordinary_thread_ids[i], NULL);

    pthread_mutex_destroy(&pool->whole_mutex);
    pthread_mutex_destroy(&pool->busy_thread_number_mutex);
    pthread_cond_destroy(&pool->queue_notfull_cond);
    pthread_cond_destroy(&pool->queue_notempty_cond);
    if (pool->ordinary_thread_ids)
    {
        free(pool->ordinary_thread_ids);
        pool->ordinary_thread_ids = NULL;
    }
    if (pool->task_queue)
    {
        free(pool->task_queue);
        pool->task_queue = NULL;
    }

    if (pool)
    {
        free(pool);
        pool = NULL;
    }
}
