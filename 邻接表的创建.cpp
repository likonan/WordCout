#include <stdio.h>
#include <stdlib.h>
#define MVNum 100                                 //��󶥵���
typedef struct ArcNode{                        //����
    int adjvex;                                    //�ڽӵ��λ��
    struct ArcNode *nextarc;      //ָ����һ�������ָ��
  }ArcNode;
typedef struct VNode{
   char data;                                    //������Ϣ
   ArcNode *firstarc;         //ָ���һ�������ָ��
}VNode, AdjList[MVNum];                 //AdjList��ʾ�ڽӱ�����
typedef struct{
    AdjList vertices;              //ͷ�������
    int vexnum, arcnum;     //ͼ�ĵ�ǰ�������ͱ���
}ALGraph;
void CreatMGraph(ALGraph &G);/* ����ͼ */
void printGraph(ALGraph G);/*���ͼ */
int main()
{
    ALGraph G;
    CreatMGraph(G);
    printGraph(G);
    return 0;
}

void printGraph(ALGraph G)
{
    int i;
    ArcNode *p;
    for(i=0;i<G.vexnum;i++)
    {
       printf("%c:",G.vertices[i].data);
       for(p=G.vertices[i].firstarc;p;p=p->nextarc)
           printf(" %c",G.vertices[p->adjvex].data);
       printf("\n");
    }
}

/* ����������д�� */
int locate(ALGraph G,char v)//�󶥵�v���±�
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(v==G.vertices[i].data)
            return i;
    }
    return -1;
}
void CreatMGraph(ALGraph &G)//����ͼG
{
    int i,j,k;
    ArcNode *p1,*p2;
    char str[10],a[3];
    scanf("%d %d",&(G.vexnum),&(G.arcnum));
    scanf("%s",str);
    for(i=0;i<9;i++)
    {
        if(str[i]=='\0')
            break;
        G.vertices[i].data=str[i];
    }
    for(i=0;i<G.arcnum;i++)
    {
        G.vertices[i].firstarc=NULL;
    }
    for(k=0;k<G.arcnum;k++)
    {
        scanf("%s",a);
        i=locate(G,a[0]);j=locate(G,a[1]);
        p1=new ArcNode;
        p1->adjvex=j;
        p1->nextarc=G.vertices[i].firstarc;
        G.vertices[i].firstarc=p1;
        p2=new ArcNode;
        p2->adjvex=i;
        p2->nextarc=G.vertices[j].firstarc;
        G.vertices[j].firstarc=p2;
    }
}
