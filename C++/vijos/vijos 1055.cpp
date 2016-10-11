#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct data{
	int x,y;
}p[5001];
inline bool cp(data a,data b)
{
	return a.x<b.x;
}
inline bool cp2(data a,data b)
{
	return a.y<b.y;
}
int main()
{
	int l,w,s;
	int ans=0;
	scanf("%d%d%d",&l,&w,&s);//cin>>l>>w>>s;
	for(int i=1;i<=s;i++)   scanf("%d%d",&p[i].x,&p[i].y);//cin>>p[i].x>>p[i].y;
	p[s+1].x=0;p[s+1].y=0;
	p[s+2].x=0;p[s+2].y=l;
	p[s+3].x=0;p[s+3].y=w;
	p[s+4].x=l;p[s+4].y=w;
	s+=4;
	sort(p+1,p+s+1,cp2);
	for(int i=2;i<=s;i++)  ans=max((p[i].y-p[i-1].y)*l,ans);
	sort(p+1,p+s+1,cp);
	for(int i=1;i<s;i++)
    {
       int u=0,d=w;
       for(int j=i+1;j<=s;j++)
       {
         if(p[j].x==p[i].x||p[j].y>d||p[j].y<u)continue;
         ans=max(ans,(d-u)*(p[j].x-p[i].x));
         if(p[j].y<d&&p[j].y>=p[i].y){d=p[j].y;}
         if(p[j].y>u&&p[j].y<=p[i].y){u=p[j].y;}
         if(u>=d)break;
       }
    }
	cout<<ans<<endl;
	system("pause");
    return 0;
}
