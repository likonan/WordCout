#include <stdio.h>
#include <stdlib.h>
#define MVNum 100                                 //最大顶点数
typedef struct ArcNode{                        //表结点
    int adjvex;                                    //邻接点的位置
    struct ArcNode *nextarc;      //指向下一个表结点的指针
  }ArcNode;
typedef struct VNode{
   char data;                                    //顶点信息
   ArcNode *firstarc;         //指向第一个表结点的指针
}VNode, AdjList[MVNum];                 //AdjList表示邻接表类型
typedef struct{
    AdjList vertices;              //头结点数组
    int vexnum, arcnum;     //图的当前顶点数和边数
}ALGraph;
void CreatMGraph(ALGraph &G);/* 创建图 */
void printGraph(ALGraph G);/*输出图 */
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

/* 请在这里填写答案 */
int locate(ALGraph G,char v)//求顶点v的下标
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(v==G.vertices[i].data)
            return i;
    }
    return -1;
}
void CreatMGraph(ALGraph &G)//创建图G
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
