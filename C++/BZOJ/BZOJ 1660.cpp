#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;
int n, a[80010];
stack <int> s; 
int main()
{       
        int i;       
        cin>>n;       
        for(i = 1; i <= n; i++) scanf("%d",&a[i]);       
        long long ans = 0;       
        s.push(a[1]);       
        for(i = 1; i <= n; i++)       
        {              
                       if(a[i] < s.top())              
                       {                     
                       ans += s.size();                     
                       s.push(a[i]);              
                       }              
        else              
        {                     
        while(a[i] >= s.top()) 
        {
                   s.pop(); 
                   if(s.empty()) break;
        }                     
        ans += s.size();                     
        s.push(a[i]);              
        }       
        }       
        cout<<ans<<endl;
        system("pause");
        return 0;
}
