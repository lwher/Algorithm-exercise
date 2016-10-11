#include<cstdio>  
using namespace std;  
typedef unsigned long long ll;  
short a,b,c,d,e,f,g,h;  
char s[21]="18446744073709551616";  
int main()  
{  
    ll ans;  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
              scanf("%d%d%d%d%d%d%d%d%llu",&a,&b,&c,&d,&e,&f,&g,&h,&ans);  
              if(ans==(1ll<<63) && a+b+c+d+e+f+g+h==60*8)  printf("%s\n",s);  
              else  {ans+=(1ll<<a)+(1ll<<b)+(1ll<<c)+(1ll<<d)+(1ll<<e)+(1ll<<f)+(1ll<<g)+(1ll<<h);printf("%llu\n",ans);}  
    }  
    //system("pause");  
    return 0;  
}
