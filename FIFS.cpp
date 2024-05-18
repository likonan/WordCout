#include<stdio.h> 
#include<stdlib.h>
struct fcfs //ID
{
	char name[20];
	float startime;
	float arrivetime;
	float servicetime;
	float finishtime;
	float zztime; //周转时间 
	float dqzztime; // 平均周转时间 
};
void input(fcfs *p,int N)//输入进程相关信
{
	printf("请输入进程的名字 到达时间  服务时间：（比如：进程1 0 10）\n");
	for(int i=1;i<=N;i++)
	{
		printf("请输入进程%d的信息:\n", i);//i的初始值设为1,这样方便表示 
		printf("Process ID: ");
		scanf("%s",p[i-1].name);
		printf("Arrival Time: ");
		scanf("%f",&p[i-1].arrivetime);
		printf("Service Time: ");
		scanf("%f",&p[i-1].servicetime);
		printf("\n"); 
	 } 
	 
 }
 
void sort(fcfs *p,int N){
 	int i,j;
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<N-i-1;j++)
		{
			if(p[j].arrivetime>p[j+1].arrivetime)
			{
				fcfs temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
 }
 void run(fcfs *p,int N){
 	int i; 
 	for(i=0;i<N;i++)
 	{
 		if(i==0){
 			p[i].startime=p[i].arrivetime;
 			p[i].finishtime=p[i].arrivetime+p[i].servicetime;
 			//周转时间=要求服务时间+等待时间
			p[i].zztime=p[i].servicetime;
			//其他进程：p[i].zztime=p[i].finishtime-p[i].arrivetime;
			p[i].dqzztime=p[i].zztime/p[i].servicetime;
		 }else{
		 	p[i].startime=p[i-1].finishtime;
		 	p[i].finishtime=p[i].startime+p[i].servicetime;
		 	p[i].zztime=p[i].finishtime-p[i].arrivetime;
		 	p[i].dqzztime=p[i].zztime/p[i].servicetime;

		 }
	 }
 }
 
 void show(fcfs *p,int N) {
 	int i;
 	printf("调用先来先服务算法后进程的运行顺序为：\n");
	for(i=0;i<N;i++){
	 	printf("%s",p[i].name);
	 	printf("---->");
	 } 
	 printf("\n");
	 printf("具体的进程调度信息为\n"); 
	 printf("进程 到达时间 服务时间 周转时间 ....\n");
	for(i=0;i<N;i++){
		printf("%3s",p[i].name);
		printf("%8.3f",p[i].arrivetime);
		printf("%8.3f",p[i].servicetime);
		printf("%8.3f",p[i].zztime);
		printf("\n");
	}
	 
 }
 
int main()
{
 	fcfs a[100]; //创建100个结构体 
 	int N; //进程数量
    printf("请输入进程数目");
	scanf("%d",&N);
	input(a,N);
	sort(a,N);
	run(a,N);
	show(a,N);
	int i;
	float average_zztime=0;
	float average_dqzztime=0;
	for(i=0;i<N;i++){
		average_zztime+=a[i].zztime;
		average_dqzztime+=a[i].dqzztime;
	}
	average_zztime/=N;
	average_dqzztime/=N;
	printf("采用FCFS算法算得平均周转时间为：%f",average_zztime);
	printf("采用FCFS算法算得平均带权周转时间为：%f",average_dqzztime);
	return 0;
	printf("实验一：FCFS算法");
}
