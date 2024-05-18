#include<stdio.h> 
#include<stdlib.h>
struct fcfs //ID
{
	char name[20];
	float startime;
	float arrivetime;
	float servicetime;
	float finishtime;
	float zztime; //��תʱ�� 
	float dqzztime; // ƽ����תʱ�� 
};
void input(fcfs *p,int N)//������������
{
	printf("��������̵����� ����ʱ��  ����ʱ�䣺�����磺����1 0 10��\n");
	for(int i=1;i<=N;i++)
	{
		printf("���������%d����Ϣ:\n", i);//i�ĳ�ʼֵ��Ϊ1,���������ʾ 
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
 			//��תʱ��=Ҫ�����ʱ��+�ȴ�ʱ��
			p[i].zztime=p[i].servicetime;
			//�������̣�p[i].zztime=p[i].finishtime-p[i].arrivetime;
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
 	printf("���������ȷ����㷨����̵�����˳��Ϊ��\n");
	for(i=0;i<N;i++){
	 	printf("%s",p[i].name);
	 	printf("---->");
	 } 
	 printf("\n");
	 printf("����Ľ��̵�����ϢΪ\n"); 
	 printf("���� ����ʱ�� ����ʱ�� ��תʱ�� ....\n");
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
 	fcfs a[100]; //����100���ṹ�� 
 	int N; //��������
    printf("�����������Ŀ");
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
	printf("����FCFS�㷨���ƽ����תʱ��Ϊ��%f",average_zztime);
	printf("����FCFS�㷨���ƽ����Ȩ��תʱ��Ϊ��%f",average_dqzztime);
	return 0;
	printf("ʵ��һ��FCFS�㷨");
}
