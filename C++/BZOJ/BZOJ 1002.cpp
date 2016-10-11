#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct highcalc{
    int num[110];
}f[110];
highcalc operator *(const highcalc &a,int b){
    highcalc ans;
    memset(ans.num,0,sizeof(ans.num));
    for(int i=1;i<=a.num[0];i++) ans.num[i]=a.num[i]*b;
    for(int i=1;i<a.num[0];i++) if(ans.num[i]>9) {ans.num[i+1]+=ans.num[i]/10;ans.num[i]%=10;}
    for(ans.num[0]=a.num[0];ans.num[ans.num[0]]>9;ans.num[0]++) {
       ans.num[ans.num[0]+1]+=ans.num[ans.num[0]]/10;ans.num[ans.num[0]]%=10;
    }
    return ans;
}
highcalc operator -(const highcalc &a,const highcalc &b){
    highcalc ans,A;
    memset(ans.num,0,sizeof(ans.num));
    memset(A.num,0,sizeof(A.num));
    for(int i=0;i<=a.num[0];i++) A.num[i]=a.num[i];
    for(int i=1;i<=A.num[0];i++) {
       if(A.num[i]<b.num[i]) {
          A.num[i+1]--;
          ans.num[i]=A.num[i]+10-b.num[i];
       }
       else ans.num[i]=A.num[i]-b.num[i];
    }
    for(ans.num[0]=A.num[0];!ans.num[ans.num[0]];ans.num[0]--);
    return ans;
}
highcalc operator +(const highcalc &a,int b){
    highcalc ans;
    memset(ans.num,0,sizeof(ans.num));
    for(int i=0;i<=a.num[0];i++) ans.num[i]=a.num[i];
    ans.num[1]+=b;
    for(int i=1;i<ans.num[0];i++) {
      if(ans.num[i]>9) ans.num[i+1]+=ans.num[i]/10,ans.num[i]%=10;
      else break;
    }
    for(;ans.num[ans.num[0]]>9;ans.num[0]++) ans.num[ans.num[0]+1]+=ans.num[ans.num[0]]/10,ans.num[ans.num[0]]%=10; 
    return ans;
}
int n;
int main()
{
    f[1].num[0]=1;f[1].num[1]=1;
    f[2].num[0]=1;f[2].num[1]=5;
    scanf("%d",&n);
    for(int i=3;i<=n;i++)  f[i]=f[i-1]*3-f[i-2]+2;    
    for(int i=f[n].num[0];i>0;i--) printf("%d",f[n].num[i]);
    printf("\n");
    return 0;
}