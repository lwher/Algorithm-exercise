#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n, m, dist[310][310];
int main()
{       
        int i, j, k, T;       
        cin>>n>>m>>T;       
        memset(dist, 127, sizeof(dist));       
        for(i = 1; i <= m; i++)        
        {              
                       int x, y, z;              
                       cin>>x>>y>>z;              
                       dist[x][y] = z;       
        }       
        for(i = 1; i <= n; i++) 
        dist[i][i] = 0;       
        for(k = 1; k <= n; k++)              
        for(i = 1; i <= n; i++)                     
        for(j = 1; j <= n; j++)                            
        dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));       
        for(i = 1; i <= T; i++)       
        {              
                       int x, y; 
                       scanf("%d%d",&x,&y);
                       if(dist[x][y]>100000000)      
                       printf("-1\n");
                       else
                       printf("%d\n",dist[x][y]);
                 //      cout<<(dist[x][y] > 100000000 ? -1 : dist[x][y])<<endl;       
        }    
        system("pause"); 
        return 0;
}  
