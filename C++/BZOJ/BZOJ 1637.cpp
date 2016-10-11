#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, sum[50010], hash[50010];
struct node
{
       int id, x;
}a[50010];
bool cmp(node a1, node a2)
{return a1.x < a2.x;} 
int main()
{       
        int i, ans = 0;             
        cin>>n;        
        memset(sum, 0, sizeof(sum)); 
        memset(hash, 0x3f, sizeof(hash));       
        for(i = 1; i <= n; i++) 
        {cin>>a[i].id>>a[i].x; if(!a[i].id) a[i].id = -1;}       
        sort(a + 1, a + 1 + n, cmp);       
        for(i = 1; i <= n; i++)       
        {              
        sum[i] = sum[i - 1] + a[i].id;              
        if(i < hash[sum[i]]) hash[sum[i]] = i;       
        }       
        for(i = 1; i <= n; i++)       
        {              
                       int j = hash[sum[i]];              
                       if(j >= i) continue;              
                       ans = max(ans, a[i].x - a[j + 1].x);       
        }       
        cout<<ans<<endl; 
        system("pause");
        return 0;
} 
