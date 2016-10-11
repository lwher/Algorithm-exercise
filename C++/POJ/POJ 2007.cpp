#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<math.h>
struct sth
{
       int x,y;
}dian[52];
int n;
int x1,y11;
double juli(sth a,sth b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int chaji(int a,int b,int c,int d)
{
   return a*d-b*c;  
}
inline bool comp(sth a,sth b)
{
   if(a.x==b.x)
   return a.y<b.y;
   else
   return a.x<b.x;
}
int cp3(const void *a, const void *b)
{
    sth *p1=(sth *)a,*p2=(sth *)b;
    if(chaji((*p2).x-x1,(*p2).y-y11,(*p1).x-x1,(*p1).y-y11)<0)
    return -1;
    else
    if(chaji((*p2).x-x1,(*p2).y-y11,(*p1).x-x1,(*p1).y-y11)==0)
    {
	 if((*p1).x*(*p2).x>0)
	 {
	 if(juli(*p1,dian[1])<juli(*p2,dian[1]))
	 return -1;
	 else
	 return 1;
	 }
	 else
	 if((*p1).x*(*p2).x==0)
	 return (*p1).x<(*p2).x;
	 else
	 if((*p1).y*(*p2).y==0)
	 return (*p1).y<(*p2).y;
	 else
	 return (*p1).x<(*p2).x;
	}
    else 
    return 1;
}

int main()
{
    n=0;
    int i;
    while(scanf("%d%d",&dian[n+1].x,&dian[n+1].y)!=EOF)
    n++;
     qsort(dian+2,n-1,sizeof(dian[1]),cp3);
        for(i=1;i<=n;i++)
     printf("(%d,%d)\n",dian[i].x,dian[i].y);
     
   // system("pause");
    return 0;
}

