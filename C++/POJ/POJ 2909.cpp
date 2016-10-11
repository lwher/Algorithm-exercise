#include<iostream>
using namespace std;
#define maxsize 16000
#define is_prim  1
#define no_prim  0
int a[maxsize];
int primnum[2*maxsize+1]={0};
void prim()
{
   int i,j,prim_now;
   for(i=0;i<maxsize;i++)
       a[i]=is_prim;
   for(i=0;i<maxsize;i++)
   {
      if(a[i])
      {
          prim_now=2*i+3;
          for(j=prim_now+i;j<maxsize;j+=prim_now)
             a[j]=no_prim;
      }
   }
   primnum[2]=is_prim;
   for(i=0;i<maxsize;i++)
     if(a[i])
     {
        primnum[2*i+3]=is_prim;
     }
}
int main()
{
    int n,i,sum;
    prim();
    while(cin>>n&&n)
    {
        int big=n/2;
        sum=0;
        for(i=2;i<=big;i++)
        {
           if(primnum[i]&&primnum[n-i])
           {
               sum++;
           }
        }
        cout<<sum<<endl;
    }
    return 0;
}

