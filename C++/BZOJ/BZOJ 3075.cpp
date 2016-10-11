#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char A[10010],B[1010];
int n,m;
int next[1010],to[1010][27];
int f1[1010],f2[1010],ans;
void getnext()
{
     int i=0,j;
     next[0]=-1;
     for(i=0;i<m;i++)
     {
         for(j=next[i];j!=-1;j=next[j])  if(B[i+1]==B[j+1]) break;
         next[i+1]=j+1;
     }
}
int main()
{
    int i,j,k;
    scanf("%s",A+1);scanf("%s",B+1);
    n=strlen(A+1);m=strlen(B+1); 
    getnext();    
    for(i=0;i<m;i++)
    {
        for(j=0;j<26;j++)  
        {
             k=i;
             while(k!=-1)  
             {
                if(B[k+1]=='a'+j)  {to[i][j]=k+1;break;}
                k=next[k];
             }
             if(k==-1)  to[i][j]=0;
        }
    }    
    memset(f1,-1,sizeof(f1));
    f1[0]=0;
    for(i=1;i<=n;i++)
    {
        for(k=0;k<m;k++)  f2[k]=f1[k];
        for(j=0;j<m;j++)
        if(f1[j]!=-1)
        {
            k=to[j][A[i]-'a'];
            if(k<m)   f2[k]=max(f2[k],f1[j]+1);
        }
        for(k=0;k<m;k++)  f1[k]=f2[k];
    }
    for(i=0;i<m;i++)  ans=max(ans,f1[i]);
    cout<<n-ans<<endl;
    system("pause");
    return 0;
}
