#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int m,i,j;
    cin>>m;
    for(i=1;i<=(m/2);i++)
    for(j=i+1;j<=i+m;j++)
    {
       if(((j-i+1)*(j+i)/2)>m)  break;
       if(((j-i+1)*(j+i)/2)==m)  cout<<i<<" "<<j<<endl;
    }
    system("pause");
    return 0;
}
