#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int a[55][55],r[55][55],b[55],n,m;
long long gauss()
{    
   int i,j,row=1,col;
   for(col=1;col<=m;++col)
   {    
        for(i=row;i<=n;++i)  if(a[i][col])  break ;
       if(i>n)   continue ;
       if(i!=row)
       {    
            for(j=col;j<=m;++j)
            swap(a[row][j],a[i][j]);
            swap(b[i],b[row]);
       }
       for(i=row+1;i<=n;++i)
           if(a[i][col])
           {    
                   for(j=col;j<=m;++j)
                   a[i][j]^=a[row][j];
                   b[i]^=b[row];
           }
       row++;
   }
   for(i=row;i<=n;++i)   if(b[i])  return 0;
   return 1ll<<(long long)(m-row+1);
}
int main()
{    
   int i,j,x,c,q,t,test=0;
   scanf("%d",&t);
   while(t--)
   {    
       printf("Case %d:\n",++test);
       scanf("%d%d",&n,&m);
       memset(a,0,sizeof(a));
       for(i=1;i<=m;++i)
       {    
           scanf("%d",&c);
           for(j=1;j<=c;++j)
           {    scanf("%d",&x);
               a[x][i]=1;
           }
       }
       scanf("%d",&q);
       for(i=1;i<=q;++i)
       {    
            for(j=1;j<=n;++j)   scanf("%d",&b[j]);
            memcpy(r,a,sizeof(a));
            printf("%I64d\n",gauss());
            memcpy(a,r,sizeof(a));
       }
   }
   system("pause");
   return 0;
}



