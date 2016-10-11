#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n;
int map[10][10];
bool mark[10];
bool o;
int main()
{
    int i,j,k,l;
    cin>>n;
    while(n--)
    {
          o=0;
           for(i=1;i<=9;i++)
           for(j=1;j<=9;j++)
           {
           cin>>map[i][j];
           if(map[i][j]<1 || map[i][j]>9)  o=1;
           }
           if(!o)
           for(i=1;i<=9;i++) 
           {
             memset(mark,0,sizeof(mark));
             for(j=1;j<=9;j++)
             {
                
                if(mark[map[i][j]])
                {o=1;break;}
                mark[map[i][j]]=1;  
             }
             if(o)  break;
           } 
            if(!o)
           for(i=1;i<=9;i++) 
           {
             memset(mark,0,sizeof(mark));
             for(j=1;j<=9;j++)
             {
                
                if(mark[map[j][i]])
                {o=1;break;}
                mark[map[j][i]]=1;  
             }
             if(o)  break;
           }
           if(!o)
           for(i=1;i<=9;i+=3) 
           for(j=1;j<=9;j+=3)
           {
             memset(mark,0,sizeof(mark));
             for(k=0;k<=2;k++)
             for(l=0;l<=2;l++)
             {
                if(mark[map[i+k][j+l]])
                {o=1;break;}
                mark[map[i+k][j+l]]=1;  
             }
             if(o)  break;
           }
           if(o)  cout<<"Wrong"<<endl;
           else
           cout<<"Right"<<endl;
    }
    system("pause");
    return 0;
}
