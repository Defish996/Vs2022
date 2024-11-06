#define _CRT_SECURE_NO_WARNINGS 1

#include <Windows.h>
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
#define P_NUM 3
#define P_TIME 50
enum state // ����״̬
{
    ready,// ����
    execute,// ִ��
    block,// ����
    finish// ���
};
struct pcb //PCB��Ϣ,�洢���̵������Ϣ��������������ȼ���CPUʱ�䡢����ʱ�䡢״̬
{
    char name[4];
    int priority;
    int cputime;
    int needtime;
    int count;// ִ�д���
    int round;// ��ת����
    enum state process;// ����״̬
    struct pcb *next;// ��һ������
};
struct pcb *get_process();//���û������ȡ������Ϣ�����������̿��ƿ�����
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
void display(struct pcb *p)// ��ӡ����״̬
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
int process_finish(struct pcb *q)// ������н����Ƿ����
{
    int bl = 1;
    while (bl && q)
    {
        bl = bl && q->needtime == 0;
        q = q->next;
    }
    return bl;
}
void cpuexe(struct pcb *q)// ���ȼ������㷨�ĺ����߼�
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
void priority_cal()//�������ȼ�
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
void display_menu()//�˵�
{
    printf("CHOOSE THE ALGORITHM:\n");
    printf("1 PRIORITY\n");
    printf("2 ROUNDROBIN\n");
    printf("3 EXIT\n");
}
struct pcb *get_process_round()// ��ȡ������ʱ��Ƭ��ת�����㷨�Ľ���
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
void cpu_round(struct pcb *q)// ִ��ʱ��Ƭ��ת�����㷨�ĺ����߼�
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
struct pcb *get_next(struct pcb *k, struct pcb *head)//��ȡ��һ������״̬�Ľ���
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
void set_state(struct pcb *p)// ����״̬
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
void display_round(struct pcb *p)//��ӡ������ʱ��Ƭ��ת�����㷨�Ľ���״̬��Ϣ
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
void round_cal()//����cpuʱ��Ƭ
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
/* ������ */
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
//struct jcb // ��ҵ���ƿ�
//{
//    char name[10]; // ��ҵ��
//    int reachtime; // ��ҵ����ʱ��
//    int starttime; // ��ҵ��ʼʱ��
//    // int gettime;       //��ҵ�ĵ���ʱ��
//    int needtime;     // ��ҵ��Ҫ���е�ʱ��
//    float super;      // ��ҵ����Ӧ��
//    int finishtime;   // ��ҵ���ʱ��
//    float cycletime;  // ��ҵ��תʱ��
//    float cltime;     // ��ҵ��Ȩ��תʱ��
//    char state;       // ��ҵ״̬
//    struct jcb *next; // �ṹ��ָ��
//} *ready = NULL, *p, *q;
//typedef struct jcb JCB;
//
//void inital() // ������ҵ���ƿ����,�Ƚ����ų������ȷ����ģʽ����
//{
//    int i;
//    printf("\n������ҵ��:");
//    scanf("%d", &n);
//    for (i = 0; i < n; i++)
//    {
//        p = getpch(JCB);
//        printf("\n������ҵ��:");
//        scanf("%s", p->name);
//        // getch();
//
//        printf("������ҵ����ʱ��:");
//        scanf("%d", &p->reachtime);
//        // getch();
//
//        printf("������ҵ������ʱ��:");
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
//void disp(JCB *q, int m) // ��ʾ��ҵ���к����תʱ�估��Ȩ��תʱ���
//{
//    if (m == 3) // ��ʾ����Ӧ���㷨������ҵ����������
//    {
//        printf("\n��ҵ%s�������У����������������\n", q->name);
//        printf("\n ��ʼ����ʱ�� \t ���ʱ�� \t ��תʱ�� \t ��Ȩ��תʱ�� \t��Ӧ�� \n");
//        printf(" %d    \t", q->starttime);
//        printf("           %d    \t", q->finishtime);
//        printf(" %f    \t", q->cycletime);
//        printf(" %f\t", q->cltime);
//        printf(" %f\n", q->super);
//        _getch();
//    }
//    else // ��ʾ�����ȷ���,�����ҵ�����㷨���Ⱥ���ҵ���������
//    {
//
//        printf("\n��ҵ%s�������У����������������\n", q->name);
//        printf("\n ��ʼ����ʱ�� \t ���ʱ�� \t ��תʱ�� \t ��Ȩ��תʱ�� \n");
//        printf(" %d    \t", q->starttime);
//        printf("           %d    \t", q->finishtime);
//        printf(" %f    \t", q->cycletime);
//        printf(" %f\t", q->cltime);
//        _getch();
//    }
//}
//void running(JCB *p, int m) // ������ҵ
//{
//    if (p == ready) // �Ƚ�Ҫ���е���ҵ�Ӷ����з������
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
//    p->starttime = times; // ������ҵ���к�����ʱ��,��תʱ��ȵ�
//    p->state = 'R';
//    p->finishtime = p->starttime + p->needtime;
//    p->cycletime = (float)(p->finishtime - p->reachtime);
//    p->cltime = (float)(p->cycletime / p->needtime);
//    T1 += p->cycletime;
//    T2 += p->cltime;
//    disp(p, m); // ����disp()����,��ʾ��ҵ�������
//    times += p->needtime;
//    p->state = 'F';
//    printf("\n%s ��ҵ�����!\n�밴���������...\n", p->name);
//    free(p); // �ͷ����к����ҵ
//    _getch();
//}
//void super() // �����������ҵ�ĸ���Ӧ��
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
//void final() // ����ӡ��ҵ��ƽ����תʱ��,ƽ����Ȩ��תʱ��
//{
//    float s, t;
//    t = T1 / n;
//    s = T2 / n;
//    _getch();
//    printf("\n\n��ҵ�Ѿ�ȫ�����!");
//    printf("\n%d����ҵ��ƽ����תʱ���ǣ�%f", n, t);
//    printf("\n%d����ҵ��ƽ����Ȩ��תʱ���ǣ�%f\n\n\n", n, s);
//}
//void hrn(int m) // ����Ӧ���㷨
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
//            running(min, m); // ����running()����
//        }
//    } // for
//    final(); // ����running()����
//}
//
//void sjf(int m) // �����ҵ�����㷨
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
//            running(min, m); // ����running()����
//        }
//    } // for
//    final(); // ����running()����
//}
//
//void fcfs(int m) // �����ȷ����㷨
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
//            printf("\nû������Ҫ��Ľ���,��ȴ�");
//            times++;
//            if (times > 100)
//            {
//                printf("\nʱ�����");
//                _getch();
//            }
//        }
//        else
//        {
//            running(p, m); // ����running()����
//        }
//    }
//    final(); // ����running()����
//}
//
//void mune()
//{
//    int m;
//    times = 0;
//    T1 = 0, T2 = 0;
//    printf("\n\n\t\t*********************************************\t\t\n");
//    printf("\t\t\t\t��ҵ�������˵�\n");
//    printf("\t\t*********************************************\t\t\n");
//    printf("\n\n\n\t\t\t1.�����ȷ����㷨");
//    printf("\n\t\t\t2.�����ҵ�����㷨");
//    printf("\n\t\t\t3.��Ӧ�ȸ��������㷨");
//    printf("\n\t\t\t0.�˳�����");
//    printf("\n\n\t\t\t\tѡ���㷨:");
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
//        printf("ѡ�����,����ѡ��.");
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