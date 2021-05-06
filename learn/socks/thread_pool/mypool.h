#include <my/debug.info.h>


#define DEFAULT_TIME 10                 /*10s检测一次*/
#define MIN_WAIT_TASK_NUM 10            /*如果queue_size > MIN_WAIT_TASK_NUM 添加新的线程到线程池*/ 
#define DEFAULT_THREAD_VARY 10          /*每次创建和销毁线程的个数*/
#define true 1
#define false 0

typedef struct
{
    void *(*function)(void *);
    void *arg;
} Tasks_t;

typedef struct
{
    pthread_mutex_t whole_mutex;
    pthread_mutex_t busy_thread_number_mutex;

    pthread_cond_t queue_notfull_cond;
    pthread_cond_t queue_notempty_cond;

    pthread_t *ordinary_thread_ids;
    pthread_t management_thread_id;

    Tasks_t *task_queue;

    int min_thread_count;
    int max_thread_count;
    int live_thread_count;
    int busy_thread_count;
    int wait_exit_thread_count;

    int queue_size;
    int queue_size_max;
    int queue_front;
    int queue_tail;

    int if_shall_shutdown;
} ThreadPool;

ThreadPool *pool_create(int min_thread_count, int max_thread_count, int queue_size_max);

//普通线程阻塞
void *wait_task(void *pool);

//管理线程
void *management_task(void *pool);

void add_task(ThreadPool *pool, void *(*function)(void *arg), void *arg);

//任务
void process(ThreadPool *pool, void *data);

void pool_destroy(ThreadPool *pool);
