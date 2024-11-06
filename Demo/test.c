#define _CRT_SECURE_NO_WARNINGS 1

#include <Windows.h>
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
#define P_NUM 3
#define P_TIME 50
enum state // 四种状态
{
    ready,// 就绪
    execute,// 执行
    block,// 阻塞
    finish// 完成
};
struct pcb //PCB信息,存储进程的相关信息，如进程名、优先级、CPU时间、所需时间、状态
{
    char name[4];
    int priority;
    int cputime;
    int needtime;
    int count;// 执行次数
    int round;// 轮转次数
    enum state process;// 进程状态
    struct pcb *next;// 下一个进程
};
struct pcb *get_process();//从用户那里获取进程信息，并创建进程控制块链表
struct pcb *get_process()
{
    struct pcb *q = NULL;
    struct pcb *t = NULL;
    struct pcb *p = NULL;
    int i = 0;
    printf("input name and needtime,please input 3 processes\n");
    while (i < P_NUM)
    {
        q = (struct pcb *)malloc(sizeof(struct pcb));
        scanf("%s", &(q->name));
        scanf("%d", &(q->needtime));
        q->cputime = 0;
        q->priority = P_TIME - q->needtime;
        q->process = ready;
        q->next = NULL;
        if (i == 0)
        {
            p = q;
            t = q;
        }
        else
        {
            t->next = q;
            t = q;
        }
        i++;
    } /*while*/
    return p;
}
void display(struct pcb *p)// 打印进程状态
{
    printf("name    cputime    needtime    priority    state\n");
    while (p)
    {
        printf("%s", p->name);
        printf("        ");
        printf("%d", p->cputime);
        printf("        ");
        printf("%d", p->needtime);
        printf("        ");
        printf("%d", p->priority);
        printf("        ");
        switch (p->process)
        {
        case ready:
            printf("ready\n");
            break;
        case execute:
            printf("execute\n");
            break;
        case block:
            printf("block\n");
            break;
        case finish:
            printf("finish\n");
            break;
        }
        p = p->next;
    }
}
int process_finish(struct pcb *q)// 检查所有进程是否结束
{
    int bl = 1;
    while (bl && q)
    {
        bl = bl && q->needtime == 0;
        q = q->next;
    }
    return bl;
}
void cpuexe(struct pcb *q)// 优先级调度算法的核心逻辑
{
    struct pcb *t = q;
    int max_priority = 0;
    while (q)
    {
        if (q->process != finish)
        {
            q->process = ready;
            if (q->needtime == 0)
            {
                q->process = finish;
            }
        }
        if (max_priority < q->priority && q->process != finish)
        {
            max_priority = q->priority;
            t = q;
        }
        q = q->next;
    }
    if (t->needtime != 0)
    {
        t->priority -= 3;
        t->needtime--;
        t->process = execute;
        t->cputime++;
    }
}
void priority_cal()//计算优先级
{
    struct pcb *p;
    int cpu = 0;
    p = get_process();
    while (!process_finish(p))
    {
        cpu++;
        printf("cputime:%d\n", cpu);
        cpuexe(p);
        display(p);
        Sleep(5);
    }
    printf("All processes have finished,press any key to exit");
    _getch();
}
void display_menu()//菜单
{
    printf("CHOOSE THE ALGORITHM:\n");
    printf("1 PRIORITY\n");
    printf("2 ROUNDROBIN\n");
    printf("3 EXIT\n");
}
struct pcb *get_process_round()// 获取适用于时间片轮转调度算法的进程
{
    struct pcb *q = NULL;
    struct pcb *t = NULL;
    struct pcb *p = NULL;
    int i = 0;
    printf("input name and time,please input 3 processes\n");
    while (i < P_NUM)
    {
        q = (struct pcb *)malloc(sizeof(struct pcb));
        scanf("%s", &(q->name));
        scanf("%d", &(q->needtime));
        q->cputime = 0;
        q->round = 0;
        q->count = 0;
        q->process = ready;
        q->next = NULL;
        if (i == 0)
        {
            p = q;
            t = q;
        }
        else
        {
            t->next = q;
            t = q;
        }
        i++;
    } /*while*/
    return p;
}
void cpu_round(struct pcb *q)// 执行时间片轮转调度算法的核心逻辑
{
    q->cputime += 2;
    q->needtime -= 2;
    if (q->needtime < 0)
    {
        q->needtime = 0;
    }
    q->count++;
    q->round++;
    q->process = execute;
}
struct pcb *get_next(struct pcb *k, struct pcb *head)//获取下一个就绪状态的进程
{
    struct pcb *t;
    t = k;
    do
    {
        t = t->next;
    } while (t && t->process == finish);
    if (t == NULL)
    {
        t = head;
        while (t->next != k && t->process == finish)
        {
            t = t->next;
        }
    }
    return t;
}
void set_state(struct pcb *p)// 更新状态
{
    while (p)
    {
        if (p->needtime == 0)
        {
            p->process = finish;
        }
        if (p->process == execute)
        {
            p->process = ready;
        }
        p = p->next;
    }
}
void display_round(struct pcb *p)//打印适用于时间片轮转调度算法的进程状态信息
{
    printf("NAME  CPUTIME  NEEDTIME  COUNT  ROUND  STATE\n");
    while (p)
    {
        printf("%s", p->name);
        printf("        ");
        printf("%d", p->cputime);
        printf("        ");
        printf("%d", p->needtime);
        printf("        ");
        printf("%d", p->count);
        printf("        ");
        printf("%d", p->round);
        printf("        ");
        switch (p->process)
        {
        case ready:
            printf("ready\n");
            break;
        case execute:
            printf("execute\n");
            break;
        case finish:
            printf("finish\n");
            break;
        }
        p = p->next;
    }
}
void round_cal()//计算cpu时间片
{
    struct pcb *p;
    struct pcb *r;
    int cpu = 0;
    p = get_process_round();

    r = p;
    while (!process_finish(p))
    {
        cpu += 2;
        cpu_round(r);
        r = get_next(r, p);
        printf("cpu %d\n", cpu);
        display_round(p);
        set_state(p);
        Sleep(5);
    }
    printf("All processes have finished,press any key to exit");
    _getch();
}
/* 主程序 */
int main()
{
    int user_input;
    display_menu();
    scanf("%d", &user_input);
    switch (user_input)
    {
    case 1:
        priority_cal();
        break;
    case 2:
        round_cal();
        break;
    case 3:
        break;
    default:
        display_menu();
        scanf("%d", &user_input);
        break;
    }
    return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>
//#define getpch(type) (type *)malloc(sizeof(type))
//int n;
//float T1 = 0, T2 = 0;
//int times = 0;
//struct jcb // 作业控制块
//{
//    char name[10]; // 作业名
//    int reachtime; // 作业到达时间
//    int starttime; // 作业开始时间
//    // int gettime;       //作业的到达时间
//    int needtime;     // 作业需要运行的时间
//    float super;      // 作业的响应比
//    int finishtime;   // 作业完成时间
//    float cycletime;  // 作业周转时间
//    float cltime;     // 作业带权周转时间
//    char state;       // 作业状态
//    struct jcb *next; // 结构体指针
//} *ready = NULL, *p, *q;
//typedef struct jcb JCB;
//
//void inital() // 建立作业控制块队列,先将其排成先来先服务的模式队列
//{
//    int i;
//    printf("\n输入作业数:");
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        p = getpch(JCB);
//        printf("\n输入作业名:");
//        scanf("%s", p->name);
//        // getch();
//
//        printf("输入作业到达时间:");
//        scanf("%d", &p->reachtime);
//        // getch();
//
//        printf("输入作业需运行时间:");
//        scanf("%d", &p->needtime);
//        p->state = 'W';
//        p->next = NULL;
//        if (ready == NULL)
//        {
//            ready = p;
//            q = p;
//        }
//            
//        else
//        {
//            q->next = p;
//            q = p;
//        }
//    }
//}
//void disp(JCB *q, int m) // 显示作业运行后的周转时间及带权周转时间等
//{
//    if (m == 3) // 显示高响应比算法调度作业后的运行情况
//    {
//        printf("\n作业%s正在运行，估计其运行情况：\n", q->name);
//        printf("\n 开始运行时刻 \t 完成时刻 \t 周转时间 \t 带权周转时间 \t相应比 \n");
//        printf(" %d    \t", q->starttime);
//        printf("           %d    \t", q->finishtime);
//        printf(" %f    \t", q->cycletime);
//        printf(" %f\t", q->cltime);
//        printf(" %f\n", q->super);
//        _getch();
//    }
//    else // 显示先来先服务,最短作业优先算法调度后作业的运行情况
//    {
//
//        printf("\n作业%s正在运行，估计其运行情况：\n", q->name);
//        printf("\n 开始运行时刻 \t 完成时刻 \t 周转时间 \t 带权周转时间 \n");
//        printf(" %d    \t", q->starttime);
//        printf("           %d    \t", q->finishtime);
//        printf(" %f    \t", q->cycletime);
//        printf(" %f\t", q->cltime);
//        _getch();
//    }
//}
//void running(JCB *p, int m) // 运行作业
//{
//    if (p == ready) // 先将要运行的作业从队列中分离出来
//    {
//        ready = p->next;
//        p->next = NULL;
//    }
//    else
//    {
//        q = ready;
//        while (q->next != p)
//            q = q->next;
//        q->next = p->next;
//    }
//    p->starttime = times; // 计算作业运行后的完成时间,周转时间等等
//    p->state = 'R';
//    p->finishtime = p->starttime + p->needtime;
//    p->cycletime = (float)(p->finishtime - p->reachtime);
//    p->cltime = (float)(p->cycletime / p->needtime);
//    T1 += p->cycletime;
//    T2 += p->cltime;
//    disp(p, m); // 调用disp()函数,显示作业运行情况
//    times += p->needtime;
//    p->state = 'F';
//    printf("\n%s 作业已完成!\n请按任意键继续...\n", p->name);
//    free(p); // 释放运行后的作业
//    _getch();
//}
//void super() // 计算队列中作业的高响应比
//{
//    JCB *padv;
//    padv = ready;
//    do
//    {
//        if (padv->state == 'W' && padv->reachtime <= times)
//            padv->super = (float)(times - padv->reachtime + padv->needtime) / padv->needtime;
//        padv = padv->next;
//    } while (padv != NULL);
//}
//void final() // 最后打印作业的平均周转时间,平均带权周转时间
//{
//    float s, t;
//    t = T1 / n;
//    s = T2 / n;
//    _getch();
//    printf("\n\n作业已经全部完成!");
//    printf("\n%d个作业的平均周转时间是：%f", n, t);
//    printf("\n%d个作业的平均带权周转时间是：%f\n\n\n", n, s);
//}
//void hrn(int m) // 高响应比算法
//{
//    JCB *min;
//    int i, iden;
//    system("cls");
//    inital();
//    for (i = 0; i < n; i++)
//    {
//        p = min = ready;
//        iden = 1;
//        super();
//        do
//        {
//            if (p->state == 'W' && p->reachtime <= times)
//                if (iden)
//                {
//                    min = p;
//                    iden = 0;
//                }
//                else if (p->super > min->super)
//                    min = p;
//            p = p->next;
//        } while (p != NULL);
//        if (iden)
//        {
//            i--;
//            times++;
//            if (times > 1000)
//            {
//                printf("\nruntime is too long...error...");
//                _getch();
//            }
//        }
//        else
//        {
//            running(min, m); // 调用running()函数
//        }
//    } // for
//    final(); // 调用running()函数
//}
//
//void sjf(int m) // 最短作业优先算法
//{
//    JCB *min;
//    int i, iden;
//    system("cls");
//    inital();
//    for (i = 0; i < n; i++)
//    {
//        p = min = ready;
//        iden = 1;
//        do
//        {
//            if (p->state == 'W' && p->reachtime <= times)
//                if (iden)
//                {
//                    min = p;
//                    iden = 0;
//                }
//                else if (p->needtime < min->needtime)
//                    min = p;
//            p = p->next;
//        } while (p != NULL);
//        if (iden)
//        {
//            i--;
//            times++;
//            if (times > 100)
//            {
//                printf("\nruntime is too long...error");
//                _getch();
//            }
//        }
//        else
//        {
//            running(min, m); // 调用running()函数
//        }
//    } // for
//    final(); // 调用running()函数
//}
//
//void fcfs(int m) // 先来先服务算法
//{
//    int i, iden;
//    system("cls");
//    inital();
//    for (i = 0; i < n; i++)
//    {
//        p = ready;
//        iden = 1;
//        do
//        {
//            if (p->state == 'W' && p->reachtime <= times)
//                iden = 0;
//            if (iden)
//                p = p->next;
//        } while (p != NULL && iden);
//        if (iden)
//        {
//            i--;
//            printf("\n没有满足要求的进程,需等待");
//            times++;
//            if (times > 100)
//            {
//                printf("\n时间过长");
//                _getch();
//            }
//        }
//        else
//        {
//            running(p, m); // 调用running()函数
//        }
//    }
//    final(); // 调用running()函数
//}
//
//void mune()
//{
//    int m;
//    times = 0;
//    T1 = 0, T2 = 0;
//    printf("\n\n\t\t*********************************************\t\t\n");
//    printf("\t\t\t\t作业调度主菜单\n");
//    printf("\t\t*********************************************\t\t\n");
//    printf("\n\n\n\t\t\t1.先来先服务算法");
//    printf("\n\t\t\t2.最短作业优先算法");
//    printf("\n\t\t\t3.响应比高者优先算法");
//    printf("\n\t\t\t0.退出程序");
//    printf("\n\n\t\t\t\t选择算法:");
//    scanf("%d", &m);
//    switch (m)
//    {
//    case 1:
//        fcfs(m);
//        _getch();
//        system("cls");
//        mune();
//        break;
//    case 2:
//        sjf(m);
//        _getch();
//        system("cls");
//        mune();
//        break;
//    case 3:
//        hrn(m);
//        _getch();
//        system("cls");
//        mune();
//        break;
//    case 0:
//        system("cls");
//        break;
//    default:
//        printf("选择错误,重新选择.");
//        _getch();
//        system("cls");
//        mune();
//    }
//}
//int main()
//{
//    mune();
//
//    return 0;
//}