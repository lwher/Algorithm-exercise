#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
bool used[100005];
int s,e;
struct Point
{
    int x,step;
}; 
int BFS(int x)
{
    queue<Point> que;
    Point tp,ans;
    int tx; 
    ans.x=x,ans.step=0;
    used[x]=false;
    que.push(ans); 
    while(!que.empty())
    {
        tp=que.front();
        que.pop();
        tx=tp.x+1;
        if(tx<0||tx>100000);
        else
        {
            if(used[tx])
            {
                used[tx]=false,ans.x=tx,ans.step=tp.step+1,que.push(ans);
                if(ans.x==e)return ans.step;
            }
        } 
        tx=tp.x-1;
        if(tx<0||tx>100000);
        else
        {
            if(used[tx])
            {
                used[tx]=false,ans.x=tx,ans.step=tp.step+1,que.push(ans);
                if(ans.x==e)return ans.step;
            }
        } 
        tx=2*tp.x;
        if(tx<0||tx>100000);
        else
        {
            if(used[tx])
            {
                used[tx]=false,ans.x=tx,ans.step=tp.step+1,que.push(ans);
                if(ans.x==e)return ans.step;
            }
        }
    }
}
int main()
{
    while(cin>>s>>e)
    {
        if(s==e)
        {
            cout<<"0"<<endl;
            continue;
        }
        memset(used,true,sizeof(used));
        cout<<BFS(s)<<endl;
    }
    return 0;
} 
