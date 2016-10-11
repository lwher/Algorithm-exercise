#include <cstdio>
#include <stack>
using namespace std;
stack <int> stack1;
int n,w,ans;
int main()
{
   int i,x,y;
   while (scanf("%d %d",&n,&w)!=EOF)
   {
   while (!stack1.empty()) stack1.pop();
   stack1.push(0);
   ans=0;
   for (i=0;i<=n;i++)
   { 
   if (i<n)
    scanf("%d %d",&x,&y);
   else
    y=0;             
   while (y<stack1.top())
   {
    stack1.pop();
    ans++;
   }
   if (y>stack1.top())
    stack1.push(y);
   }
   printf("%d\n",ans);
   }
   system("pause");
   return 0;
}

