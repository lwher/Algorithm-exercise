#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,tot,pre[250010],last[3000010],val[250010],Time[250010];
int sz,root,v[250010],t[250010],l[250010],r[250010],w[250010],rad[250010],size[250010];
// v-得分 t-时间  w-名字的位置 rad-rand 
string s[250010];
int getnum(char q[])
{
    int i,len=strlen(q+1);string ss="";
    long long k=0;
    for(i=1;i<=len;i++)  {ss+=q[i];k=k*26+int(q[i]-'A')+1;k%=3000010;}
    i=last[k];
    while(i>0)
    {
        if(s[i]==ss)   return i; 
        i=pre[i];
    }
    tot++;s[tot]=ss;pre[tot]=last[k];last[k]=tot;
    return tot;
}
void updata(int x)
{
     size[x]=size[l[x]]+size[r[x]]+1;
}
void rturn(int &t)
{
     int k=l[t];
     l[t]=r[k];r[k]=t;
     updata(t);updata(k);
     t=k;
}
void lturn(int &t)
{
     int k=r[t];
     r[t]=l[k];l[k]=t;
     updata(t);updata(k);
     t=k;
}
void Ins(int &x,int V,int T,int W)
{
     if(x==0)
     {
         sz++;x=sz;t[x]=T;v[x]=V;w[x]=W;rad[x]=rand();size[x]=1;return;
     }
     if(V>v[x]) 
     {
         Ins(l[x],V,T,W);if(rad[l[x]]<rad[x])  rturn(x);  else size[x]++;
     }
     else
     {
         Ins(r[x],V,T,W);if(rad[r[x]]<rad[x])  lturn(x);  else size[x]++;
     }
}
void shanchu(int &x,int V,int T)
{
     if(v[x]==V && t[x]==T)
     {
          if(l[x]*r[x]==0)  x=l[x]+r[x];  else
          if(rad[l[x]]<rad[r[x]])  {int k=l[x];rturn(x);size[k]--;shanchu(r[x],V,T);}
          else  {int k=r[x];lturn(x);size[k]--;shanchu(l[x],V,T);}
          return;
     }
     if(V>v[x] || (V==v[x] && T<t[x]))  {shanchu(l[x],V,T);size[x]--;}
     else {shanchu(r[x],V,T);size[x]--;}
}
int findname(int x,int k)
{
     if(size[l[x]]+1==k)  return w[x];
     if(size[l[x]]>=k)  return findname(l[x],k);
     if(size[l[x]]+1<k) return findname(r[x],k-size[l[x]]-1);
}
int findrank(int x,int V,int T,int now)
{
    if(v[x]==V && t[x]==T)  return  now+size[l[x]]+1;
    if(V>v[x] || (V==v[x] && T<t[x]))  return  findrank(l[x],V,T,now);
    else  return findrank(r[x],V,T,now+size[l[x]]+1);
}
int main()
{
    char ch[20],kk;
    scanf("%d",&n);
    int i,j,k,vv,o,len;        
    for(i=1;i<=n;i++)
    {
        kk=getchar();
        while(kk!='+' && kk!='?')  kk=getchar();
        if(kk=='+')
        {
            j=tot;
            scanf("%s",ch+1);scanf("%d",&vv);
            k=getnum(ch);
            if(k>j)  {Ins(root,vv,i,k);val[k]=vv;Time[k]=i;}
            else
            {
                shanchu(root,val[k],Time[k]);
                val[k]=vv;Time[k]=i;
                Ins(root,vv,i,k);
            } 
        }
        else
        {
            scanf("%s",ch+1);
            if(ch[1]>='0' && ch[1]<='9')
            {
                 vv=0;len=strlen(ch+1);
                 for(j=1;j<=len;j++)  vv=vv*10+(ch[j]-'0');
                 k=findname(root,vv);len=s[k].size();
                 for(o=0;o<len;o++)  printf("%c",s[k][o]); 
                 for(j=1;j<=9;j++)
                 {
                     if(vv+j<=size[root])
                     {
                         printf(" ");
                         k=findname(root,vv+j);len=s[k].size();
                         for(o=0;o<len;o++)  printf("%c",s[k][o]);
                     }
                     else  break;
                 }
                 printf("\n");
            }
            else
            {
                k=getnum(ch);
                printf("%d\n",findrank(root,val[k],Time[k],0));
            }
        }
    }
    //system("pause");
    return 0;
}
