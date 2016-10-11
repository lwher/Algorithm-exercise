#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define LEN 2000
using namespace std;
struct sth
{
       int size,next;
       char buff[2010];
}list[2010];
char s[1000010],ch[3],S[3];
int len,q,sz;
void clear(int k)
{
     list[k].next=-1;list[k].size=0;
}
void putin(int p,int chang,int tot)
{
     int i,j=0;
     list[tot].size=chang;
     for(i=p;i<=p+chang-1;i++)   list[tot].buff[++j]=s[i];
}
void init()
{
     int i;
     for(i=1;i<=len;i+=1000)
     {
         list[sz].next=sz+1;
         sz++;clear(sz);
         putin(i,min(1000,len-i+1),sz);
     }
}
void Split(int id)
{
     int i,t=list[id].size;sz++;clear(sz);
     for(i=t/2+1;i<=t;i++)
     {
         list[sz].size++;
         list[sz].buff[list[sz].size]=list[id].buff[i];
         list[id].size--;
     }
     list[sz].next=list[id].next;list[id].next=sz;
}
void Ins(int pos,char a)
{
     int i,cur=1;
     while(pos>list[cur].size && list[cur].next!=-1)
     {
         pos-=list[cur].size;cur=list[cur].next;
     }
     if(pos>=list[cur].size)  {list[cur].buff[list[cur].size+1]=a;}
     else
     {
         for(i=list[cur].size+1;i>pos+1;i--)   list[cur].buff[i]=list[cur].buff[i-1];
         list[cur].buff[pos+1]=a;
     }
     list[cur].size++;
     if(list[cur].size>=LEN)  Split(cur);
}
void find(int pos)
{
     int cur=1;
     while(pos>list[cur].size && list[cur].next!=-1)
     {
         pos-=list[cur].size;cur=list[cur].next;
     }
     printf("%c\n",list[cur].buff[pos]);
}
int main()
{
    int i,pos;
    scanf("%s",s+1);
    len=strlen(s+1);
    init();
    scanf("%d",&q);
    
    for(i=1;i<=q;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='I')
        {
            scanf("%s",S);scanf("%d",&pos);
            Ins(pos-1,S[0]);
        }
        else
        {
            scanf("%d",&pos);
            find(pos);
        }
    }
    system("pause");
    return 0;
}
