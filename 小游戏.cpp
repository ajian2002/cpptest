#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 4

void print(int (*map)[ROWS], int rows); //打印地图
char get(void);                         //获取输入
void create(int[][ROWS], int);          //生成新数
void move(int[][ROWS], int, int);       //移动数字
void add(int[][ROWS], int, int);        //相加
void math(int[][ROWS], int, int);       //核心运算
char TorF(int[][ROWS], int);            //检查通关
char create_2or4(void);                 //生成2或4

int main(void)
{
    int map[ROWS][ROWS] = {0};
    int z;    //输入数字
    int x, y; //凑数
    int o;    //判断
    create(map, ROWS);
    do
    {
        print(map, ROWS);
        z = get();
        math(map, ROWS, z - 48);
        create(map, ROWS);
        o = TorF(map, ROWS);
    } while (!o);
    print(map, ROWS);
    if (o == 1)
        printf("\n***WIN***");
    else
        printf("\n***FAIL***");
}

void print(int (*map)[ROWS], int rows)
{
    int a, b;
    printf("\n\n\n\n\n\n\n\n\n");
    for (a = 0; a < rows; a++)
    {
        for (b = 0; b < rows; b++)
        {
            printf("%-6d", map[a][b]);
        }
        printf("\n\n\n");
    }
    printf("\n请输入： 2↑\n 4← 6→\n 8↓\n");
    return;
}

void create(int map[][ROWS], int rows)
{
    int x, y, n, a;
    srand(time(NULL));                //赋值种子
    for (x = 0, n = 0; x < rows; x++) //统计0个数
    {
        for (y = 0; y < ROWS; y++)
        {
            if (map[x][y] == 0)
                n++;
        }
    }
    if (n > 2)
    {
        for (a = 0; a < 2; a++)
        {
            do
            {
                x = (rand() % rows - 1);
                y = (rand() % rows - 1);
            } while (map[x][y] != 0);
            map[x][y] = create_2or4();
        }
    }
    else
    {
        for (x = 0; x < rows; x++)
        {
            for (y = 0; y < ROWS; y++)
            {
                if (map[x][y] == 0)
                    map[x][y] = create_2or4();
            }
        }
    }
    return;
}

char create_2or4(void)
{
    int x = rand() % 2;
    return x ? 4 : 2;
}

char get(void)
{
    char n;
    while ((n = getch()) != '2' && n != '4' && n != '6' && n != '8')
        ;
    printf("***");
    return n;
}

char TorF(int map[][ROWS], int rows)
{
    int x, y, n;
    for (x = 0; x < rows; x++) //判断有无2048
    {
        for (y = 0; y < rows; y++)
        {
            if (map[x][y] == 2048)
                return 1;
        }
    }
    for (x = 0; x < rows; x++) //检测每行有无相同相邻数
    {
        for (y = 0; y < ROWS - 1; y++)
        {
            if (map[x][y] == 0 || map[x][ROWS - 1] == 0 || map[x][y] == map[x][y + 1])
                return 0;
        }
    }
    for (y = 0; y < ROWS; y++) //检测每列有无相同相邻数
    {
        for (x = 0; x < rows - 1; x++)
        {
            if (map[x][y] == map[x + 1][y])
                return 0;
        }
    }
    return 2;
}

void math(int map[][ROWS], int rows, int z)
{
    move(map, rows, z);
    add(map, rows, z);
    move(map, rows, z);
    return;
}

void move(int (*map)[ROWS], int rows, int z)
{
    int *p1, *p2, x, y, k, m;
    (z == 4 || z == 6) ? (p1 = &x, p2 = &y) : (p1 = &y, p2 = &x); //根据输入初始化
    for (*p1 = 0; *p1 < ROWS; (*p1)++)
    {
        m = (z == 2 || z == 4) ? 0 : 3;
        for (*p2 = (z == 2 || z == 4) ? 0 : 3; *p2 < ROWS && *p2 >= 0; (z == 2 || z == 4) ? (*p2)++ : (*p2)--)
        {
            if (map[x][y]) //移动
            {
                k = map[x][y];
                map[x][y] = 0;
                if (p2 == &x)
                {
                    map[m][y] = k;
                    (z == 2 || z == 4) ? m++ : m--;
                }
                else
                {
                    map[x][m] = k;
                    (z == 2 || z == 4) ? m++ : m--;
                }
            }
        }
    }
    return;
}

void add(int map[][ROWS], int rows, int z)
{
    int *p1, *p2, x, y, k;
    (z == 4 || z == 6) ? (p1 = &x, p2 = &y) : (p1 = &y, p2 = &x);
    k = (z == 2 || z == 4) ? 1 : -1; /*初始化*/
    for (*p1 = 0; *p1 < ROWS; (*p1)++)
    {
        for (*p2 = (z == 2 || z == 4) ? 0 : 3; *p2 < ROWS && *p2 >= 0; (*p2) += k)
        {
            if (p2 == &x) //相加
            {
                if (x + k >= 0 && x + k < rows && map[x][y] == map[x + k][y])
                {
                    map[x][y] *= 2;
                    map[x + k][y] = 0;
                    (*p2) += k;
                }
            }
            else if (p2 == &y)
            {
                if (y + k >= 0 && y + k < ROWS && map[x][y] == map[x][y + k])
                {
                    map[x][y] *= 2;
                    map[x][y + k] = 0;
                    (*p2) += k;
                }
            }
        }
    }
    return;
}