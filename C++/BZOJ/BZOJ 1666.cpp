#include<iostream>
using namespace std;
int n,ans;
int main()
{
    cin>>n;
    while(n!=1)
    {
       if(n & 1)  {ans++;n=n*3+1;}
       else
       {ans++;n=n/2;}
    }
    cout<<ans<<endl;
    //while(1);
    return 0;
}
