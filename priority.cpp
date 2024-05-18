#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pcb
{
    char name[5];
    struct pcb *next;
    int needtime;
    int priority;
    char state[5];
}NODE;

NODE *create_process(int n)
{
    NODE * head, * s, * t;
    int time,i=0,j;
    char pname[5];
    head=(NODE *)malloc(sizeof(NODE));
    printf("请输入进程名:");
    scanf("%s",pname);
    strcpy(head->name,pname);
    printf("请输入进程运行时间:");
    scanf("%d",&time);
    head->needtime=time;
    printf("请输入进程优先级:");
    scanf("%d",&j);
    head->priority=j;
    strcpy(head->state,"ready");
    head->next=NULL;
    t=head;

    for(i=1;i<n;i++)
    {
        s=(NODE *)malloc(sizeof(NODE));
        printf("请输入进程名:");
        getchar();
        gets(pname);
        strcpy(s->name,pname);
        printf("请输入进程运行时间 :");
        scanf("%d",&time);
        s->needtime=time;
        printf("请输入进程优先级:");
        scanf("%d",&j);
        s->priority=j;
        strcpy(s->state,"ready");
        s->next=NULL;
        t->next=s;
        t=s;
    }
    return head;
}

void pri_process (NODE * p)
{
    int i;
    NODE * q;
    q=p-> next;
    printf ("\n进程名\t 需要时间\t 优先级\t 状态\n");
    while (q!=NULL)
    {
        printf("%4s\t %2d \t\t %2d \t\t %5s \n", q->name,q->needtime,q->priority,q->state);
        q=q-> next;
    }
}

NODE *order (NODE *head_sort)
{
    NODE * p, * s, * q, * head, * r, * t;
    int m, pr;
    char name[5];
    head=head_sort;
    p=head->next;
    r=p;
    t=p;
    q=p->next;
    while(r!=NULL)
    {
        while(q!=NULL)
        {
            if(p->priority<q->priority)
            {
                m=p->priority;
                p->priority=q->priority;
                q->priority=m;
                strcpy(name,p->name);
                strcpy(p->name,q->name);
                strcpy(q->name,name);
                pr=p->needtime;
                p->needtime=q->needtime;
                q->needtime=pr;
            }
            p=q;
            q=q->next;
        }
        r=r->next;
        p=t;
        q=p->next;
    }
    return(head_sort);
}

int main ()
{
    NODE * p=NULL, * head=NULL, * m=NULL, * z=NULL, * n=NULL;
    int j, time, x=0;
    char c, pname [5];
    printf (" 请输入进程数目");
    scanf("%d",&x);
    head = (NODE *)malloc(sizeof(NODE));
    p=create_process(x);
    head->next=p;
    pri_process(head);

    getchar();
    while(x>0)
    {
        order(head);
        m=head->next;
        strcpy(m->state,"run");
        if(m->priority>=2)
            m->priority--;
        m->needtime--;
        if(head->next!=NULL)
            pri_process(head);
        if(m->needtime==0)
        {
            head->next=m->next;
            printf("%s 进程已经完成了\n",m->name);
            free(m);
            x--;
        }
        getchar();
    }
    printf("结束!");
    getchar();
    return 0;
}


