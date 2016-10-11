#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
string a;
int now;
int main()
{
    int i;
    cin>>a;
    for(i=0;i<=a.size()-1;i++)
    {
       now+=a[i]-'0';
    }
    now%=3;
    if(!now)
    cout<<"King will win."<<endl;
    else
    {cout<<"MaoLaoDa will win."<<endl;cout<<now<<endl;}
    system("pause");
    return 0;
}
