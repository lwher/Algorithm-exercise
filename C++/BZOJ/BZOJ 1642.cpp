#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n, m, R, ST[1000010], data[1010];
struct node
{
       int st, end, w;
}a[1010];
bool cmp(node a1, node a2)
{
     return a1.st < a2.st;
}
int main()
{       
        int i, ans = 0;       
        cin>>n>>m>>R;       
        memset(ST, 0, sizeof(ST));       
        for(i = 1; i <= m; i++) 
        {cin>>a[i].st>>a[i].end>>a[i].w; a[i].end += R;}       
        sort(a + 1, a + 1 + m, cmp);       
        for(i = m; i >= 1; i--) ST[a[i].st] = i;       
        data[0] = 0;       
        for(i = 1; i <= m; i++)       
        {                   
                            int maxx = 0;              
                            for(int j = 1; j <= m; j++) 
                            if(a[i].st >= a[j].end)                     
                            maxx = max(maxx, data[j]);              
                            data[i] = maxx + a[i].w;              
                            ans = max(ans, data[i]);       
        }       
        cout<<ans<<endl;
        system("pause");
        return 0;
}   
