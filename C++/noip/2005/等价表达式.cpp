#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
string c;
struct sth
{
	string s,e;
};
sth a[10000];
int b[10000],k=2;
int z1[10000],z3[10000];
char z2[10000];
int top1=1,top2=2;
bool mark[27];
void zh()
{
	int i,j=1;
	a[1].s=c[0];
	for(i=1;i<=c.size()-1;i++)
	{
	 if((int(c[i])<48)||(int(c[i])>57))
	{
	if((int(c[i-1])>=48)&&(int(c[i-1])<=57)&&(c[i-1]!=' '))
	{	a[k].s=c.substr(j,i-j);
	k++;}
		if((c[i]=='-')&&(c[i-1]!=')'))
     	if((int(c[i-1])<48)||(int(c[i-1])>57)&&(c[i-1]!=' '))
		{a[k].s+='0';k++;}
		a[k].s=c[i];
		k++;j=i+1;
	}
     }
     k--;

	for(i=1;i<=k;i++)
    {
	 if((int(a[i].s[0])<48)||(int(a[i].s[0])>57))
	 {
		if((a[i].s=="+")||(a[i].s=="-"))
		b[i]=3;
		if((a[i].s=="*")||(a[i].s=="/"))
		b[i]=4;
		if((a[i].s=="(")||(a[i].s==")"))
		b[i]=2;
		if(a[i].s=="^")
		b[i]=5;
		if(a[i].s=="#")
		b[i]=1;
		
	 }	
	 else b[i]=atoi(a[i].s.c_str());
	}
}
void zxz()
{
	
	int i,j,l;
	bool o=0;
	z2[1]=a[1].s[0];z3[1]=1;
	for(i=2;i<=k;i++)
	{
		if((int(a[i].s[0])>=48)&&(int(a[i].s[0])<=57))
		{
		z1[top1]=b[i];top1++;
		}
		else 
		{
		 if((b[i]>z3[top2-1])||(a[i].s=="("))
		 {z2[top2]=a[i].s[0];z3[top2]=b[i];top2++;}
		 else
		 {
			while((z3[top2-1]>=b[i])&&(top2>1))
		{
			if((a[i].s[0]==')')&&(z2[top2-1]=='(')){top2--;o=1;break;}
			l=z1[top1-2];
			if(z2[top2-1]=='+'){z1[top1-2]+=z1[top1-1];z1[top1-2]%=10007;top1--;}
			if(z2[top2-1]=='-'){z1[top1-2]-=z1[top1-1];z1[top1-2]%=10007;top1--;}
			if(z2[top2-1]=='*'){z1[top1-2]*=z1[top1-1];z1[top1-2]%=10007;top1--;}
			if(z2[top2-1]=='/'){z1[top1-2]/=z1[top1-1];z1[top1-2]%=10007;top1--;}
			if(z2[top2-1]=='^')
			{   
			    
				for(j=1;j<=z1[top1-1]-1;j++)
				{z1[top1-2]*=l;z1[top1-2]%=10007;}
				top1--;
			}
			top2--;
		 
		}
	    
		 if(top2<2)top2=2;
		 if(!o)
		 {z2[top2]=a[i].s[0];z3[top2]=b[i];top2++;}
		 o=0;
		 
		}
		}
		
    }
	
}
int js(string q,string j)
{
	int i;
	for(i=0;i<=q.size()-1;i++)
    if(q[i]=='a')  q.replace(i,1,j);
    c+='#';
    c+=q;
	c+='#';
	//cout<<c<<endl;
    zh();
    zxz();
    c="";
    k=2;
    top1=1,top2=2;
    return z1[1];
}
int main()
{
	//freopen("equal.in","r",stdin);
	//freopen("equal.out","w",stdout);
	char ch;
    string ss,aa,kk;
	int zhi,n,i,j,ll,w,o;
	getline(cin,ss);

	cin>>n;
	getline(cin,kk);
	for(i=1;i<=n;i++)
	{getline(cin,a[i].e);}
	
	for(i=1;i<=n;i++)
	{j=0;
		while(j<a[i].e.size())
	{
	while(a[i].e[j]==' ')
	{a[i].e.erase(j,1);}
	j++;}}
	j=0;
	while(j<ss.size())
	{
	while(ss[j]==' ')
	{ss.erase(j,1);}
	j++;}

	for(i=1;i<=8;i++)
	{
		aa="";
		ch=48+i;
		aa+=ch;
		
	  zhi=js(ss,aa);
	  //cout<<zhi<<endl;
	  for(j=1;j<=n;j++)
	  {if(!mark[j])
		{
	  ll=js(a[j].e,aa);
	  //cout<<ll<<" ";
	  if(ll!=zhi) 
	  mark[j]=1;
	  
	  }
	 }
    
}
	for(i=1;i<=n;i++)
	if(!mark[i])
	
	{//cout<<mark[i]<<" ";
		ch=i+64;
//	cout<<a[i].e<<endl;
	    cout<<ch;
}
  // cout<<aa;

//system("pause");
return 0;
}