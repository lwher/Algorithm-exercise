#include<iostream>
#include<cmath>
using namespace std;
int main()
{
        float h,s,v,l,k,n,tmax,tmin,s1,s2,m;
        cin>>h>>s>>v>>l>>k>>n;
        m=0;
        tmax=sqrt(2*h/10);
        tmin=sqrt(2*(h-k)/10);
        s2=s-tmin*v+l;
        s1=s-tmax*v;
        for(int i=0;i<n;i++)
        {
           if(i>=s1-0.00001&&i<=s2+0.00001)
           m++;
        }
        cout<<m<<endl;
        return 0;
}
