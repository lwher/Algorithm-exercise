#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
char s[100010];int p1,p2,p3,len;
bool print(int x)
{
	int i,j,l,r;char s1,s2;
	if(x==0 || x==len-1)  return 0;
	if(s[x-1]>='0' && s[x-1]<='9' && s[x+1]>='0' && s[x+1]<='9' && s[x-1]<s[x+1])
	{
		r=s[x+1]-'0';l=s[x-1]-'0';
		if(p3==1){
		   for(i=l+1;i<r;i++)  for(j=1;j<=p2;j++){
				if(p1==3)  printf("*");  else printf("%d",i);
		   }
	    }
	    if(p3==2){
		   for(i=r-1;i>l;i--)  for(j=1;j<=p2;j++){
				if(p1==3)  printf("*");  else printf("%d",i);
		   }
		}
	    return 1;
	}
	if(s[x-1]>='a' && s[x-1]<='z' && s[x+1]>='a' && s[x+1]<='z' && s[x-1]<s[x+1])
	{
		r=s[x+1]-'a';l=s[x-1]-'a';
		if(p3==1){
		   for(i=l+1;i<r;i++){
		   s1='a'+i;s2='A'+i;
		   for(j=1;j<=p2;j++){
				if(p1==3)  printf("*");else  if(p1==1)  printf("%c",s1);else  printf("%c",s2);
		   }
		   }
	    }
	    if(p3==2){
		   for(i=r-1;i>l;i--)
		   {
		   s1='a'+i;s2='A'+i;
		   for(j=1;j<=p2;j++){
				if(p1==3)  printf("*");else  if(p1==1)  printf("%c",s1);else  printf("%c",s2);
		   }
		   }
	    }
	    return 1;
	}
	return 0;
}
int main()
{
	int i;
	scanf("%d%d%d",&p1,&p2,&p3);
	scanf("%s",s);len=strlen(s);
	for(i=0;i<len;i++){
		if(s[i]=='-')  {if(!print(i))  printf("-");}  else  printf("%c",s[i]);  
	}
	cout<<endl;
	return 0;
}
