#include<iostream>
using namespace std;

#define m 16 
#define NULLKEY 0 

struct HashTable{
   int  key;
};

void CreateHash(HashTable HT[],int key){
  int H0=key%13;
  int Hi;
  if (HT[H0].key==NULLKEY) {
    HT[H0].key=key; 
    return;
  }
  else{             
     for(int i=1;i<m;++i){                
		Hi=(H0+i)/m;
        if (HT[Hi].key==NULLKEY) {
            HT[Hi].key=key; 
            return;
        }
     }
  }
}

int main()
{    int key;
    int result;
    int i,j,n;
    HashTable HT[m];
    for(i=0;i<m;i++)
     HT[i].key=0;
    cin >> n;
    if(n>m) return 0;
    for(j=1;j<=n;j++){
        cin >> key;
        CreateHash(HT,key);
    }
    for(i=0;i<m;i++)
        cout << HT[i].key << " ";
    return 0;
}
/*#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct hnode
{  int weight;
   int lchild,rchild,parent;
 }HTNode,*HuffmanTree;
typedef char **HuffmanCode;
void Select(HTNode HT[],int len,int &s1,int &s2)//选出权值最小的两个结点，下标通过s1和s2传出去
{
    int i,min1=32767,min2=32767;
    for(i=1;i<=len;i++)
    {
        if(HT[i].weight<min1&&HT[i].parent==0)
        {
            s2=s1;
            min2=min1;
            min1=HT[i].weight;
            s1=i;
        }
        else if(HT[i].weight<min2&&HT[i].parent==0)
        {    min2=HT[i].weight;
            s2=i;
        }
    }
}
void CreateHuffman_tree(HuffmanTree &HT,int n)
{
    if(n<=1) return;
    int m,i,s1,s2;
    m=2*n-1;
    HT=new HTNode[m+1];
    for(i=0;i<=m;i++)
    {
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&HT[i].weight);
    }
    for(i=n+1;i<=m;i++)
    {
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
}
void Huffman_code(HuffmanTree HT,HuffmanCode &HC,int n)//求哈夫曼编码
{
    int i,f,start,c;
    char *cd;
    HC=new char*[n+1];
    cd=new char[n];
    cd[n-1] ='\0';
    for(i=1;i<=n;i++)
    {
        start=n-1;
        c=i;f=HT[i].parent;
        while(f!=0)
        {
            start--;
            if(HT[f].lchild==c)
                cd[start]='0';
            else
                cd[start]='1';
            c=f;f=HT[f].parent;
        }
        HC[i]=new char[n-start];
        strcpy(HC[i],&cd[start]);
    }
    delete cd;
}

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int i, n;
    scanf("%d",&n);
    CreateHuffman_tree(HT, n);
    Huffman_code(HT,HC,n);
    for(i=1;i<=n;i++)
       printf("编码是：%s\n",HC[i]);
    return 0;
}*/
