/*
    后缀数组  倍增排序法  POJ 2774
	此代码为求两个字符串的最长公共子串 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define N 100001
using namespace std;
char A[N],B[N];
int n,ans,K,LA,LB,p=0,q=1,sa[2][N<<1],rk[2][N<<1],v[N<<1],height[N<<1],num[N<<1];
void Calc_SA(int sa[],int rk[],int SA[],int RK[]){
    for(int i=1;i<=n;i++) v[rk[sa[i]]]=i;
    for(int i=n;i>=1;i--) if(sa[i]>K) SA[v[rk[sa[i]-K]]--]=sa[i]-K; 
    for(int i=n-K+1;i<=n;i++) SA[v[rk[i]]--]=i;
    for(int i=1;i<=n;i++) RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]] || rk[SA[i]+K]!=rk[SA[i-1]+K]);
}
void Sort_SA(){
    for(int i=1;i<=n;i++) v[num[i]]++;
    for(int i=1;i<=30;i++) v[i]+=v[i-1];
    for(int i=1;i<=n;i++) sa[p][v[num[i]]--]=i;
    for(int i=1;i<=n;i++) rk[p][sa[p][i]]=rk[p][sa[p][i-1]]+(num[sa[p][i]]!=num[sa[p][i-1]]);
    for(K=1;K<=n;K<<=1){
        Calc_SA(sa[p],rk[p],sa[q],rk[q]);
        p^=1;q^=1;
    }
}
void Get_height(){
    int i,j,k=0;
    height[1]=0;
    for(i=1;i<=n;i++){
        if(rk[p][i]!=1){
            j=sa[p][rk[p][i]-1];
            while(num[i+k]==num[j+k]) k++;
            height[rk[p][i]]=k;
            if(k>0) k--;
        }
    }
}
void init(){
    scanf("%s",A+1);
    scanf("%s",B+1);
    LA=strlen(A+1);LB=strlen(B+1);
    for(int i=1;i<=LA;i++) num[++n]=A[i]-'a'+1;
    num[++n]=28;
    for(int i=1;i<=LB;i++) num[++n]=B[i]-'a'+1;
}
void solve(){
    Sort_SA();
    Get_height();
    for(int i=2;i<=n;i++){
        if(sa[p][i]<=LA && sa[p][i-1]>LA+1 || sa[p][i-1]<=LA && sa[p][i]>LA+1)
            ans=max(ans,height[i]);
    }
    cout<<ans<<endl;
}
int main(){
    init();
    solve();
    return 0;
}
