#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n[7],sum;
bool o;
void dfs(int now,int pre)
{
     int i;
     if(o) return;
     if(now==sum) {o=1;return;}
     for(i=pre;i>=1;i--)
     if(n[i])
     {
         if(now+i<=sum)
         {
         n[i]--;
         dfs(now+i,i);
         if(o)  return;
         }
     }
}
int main()
{
    int i,t=0;
    while(scanf("%d%d%d%d%d%d",&n[1],&n[2],&n[3],&n[4],&n[5],&n[6]))
    {
          sum=0;
          t++;
          for(i=1;i<=6;i++)  sum+=n[i]*i;
          if(!sum)   break;
          if(sum%2)    
          {  
             cout<<"Collection #"<<t<<':'<<endl;  
             cout<<"Can't be divided."<<endl<<endl;    
             continue;  
          }  
          o=0;
          sum/=2;
          dfs(0,6);      
          if(!o)
          {
             cout<<"Collection #"<<t<<':'<<endl;  
             cout<<"Can't be divided."<<endl<<endl;
          }                                        
          else
          {
              cout<<"Collection #"<<t<<':'<<endl;  
              cout<<"Can be divided."<<endl<<endl;
          }     
    } 
    system("pause");
    return 0;
}
