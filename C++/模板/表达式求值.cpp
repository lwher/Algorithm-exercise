#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define N 10010 

using namespace std;

struct sth{
	string s;
}A[N];

string S;
int B[N],tot; //tot存储分割后的段数 
int stack_num[N],level_ch[N],top_num,top_ch;
char stack_ch[N];

void Prework(){
	int i,j=1,len=S.size();
	A[++tot].s=S[0];
	for(i=1;i<len;i++){
		if(S[i]<'0' || S[i]>'9'){
			if((S[i-1]>='0') && (S[i-1]<='9')){	
				A[++tot].s=S.substr(j,i-j);
			}
			if((S[i]=='-') && (S[i-1]!=')'))
			    if((S[i-1]<'0') || (S[i-1]>'9')){
					A[++tot].s+='0';
				}
			A[++tot].s=S[i];
	        j=i+1;
		}
    }
	for(i=1;i<=tot;i++){
		if((A[i].s[0]<'0') || (A[i].s[0]>'9')){
		    if((A[i].s=="+")||(A[i].s=="-"))  B[i]=3;
			if((A[i].s=="*")||(A[i].s=="/"))  B[i]=4;
			if((A[i].s=="(")||(A[i].s==")"))  B[i]=2;
			if(A[i].s=="^")  B[i]=5;
			if(A[i].s=="#")  B[i]=1;
		}	
	 	else B[i]=atoi(A[i].s.c_str());
	}
}
void solve(){
	int i,j;
	bool flag=0;
	stack_ch[++top_ch]=A[1].s[0]; level_ch[top_ch]=1;
	for(i=2;i<=tot;i++){
		if((A[i].s[0]>='0') && (A[i].s[0]<='9')){
			stack_num[++top_num]=B[i];
		}
		else {
		 	if((B[i]>level_ch[top_ch]) || (A[i].s=="(")){
				stack_ch[++top_ch]=A[i].s[0];
				level_ch[top_ch]=B[i];
			}
		 	else{
				while((level_ch[top_ch]>=B[i])&&(top_ch>0)){
					if((A[i].s[0]==')') && (stack_ch[top_ch]=='(')){
						top_ch--;flag=1;break;
					}
					if(stack_ch[top_ch]=='+'){stack_num[top_num-1]+=stack_num[top_num];top_num--;}
					if(stack_ch[top_ch]=='-'){stack_num[top_num-1]-=stack_num[top_num];top_num--;}
					if(stack_ch[top_ch]=='*'){stack_num[top_num-1]*=stack_num[top_num];top_num--;}
					if(stack_ch[top_ch]=='/'){stack_num[top_num-1]/=stack_num[top_num];top_num--;}
					if(stack_ch[top_ch]=='^'){
						int l=stack_num[top_num-1];   
						for(j=1;j<=stack_num[top_num]-1;j++)
							stack_num[top_num-1]*=l;
						top_num--;
					}
					top_ch--;
		 		}
				if(top_ch<1) top_ch=1;
				if(!flag){
					stack_ch[++top_ch]=A[i].s[0];
					level_ch[top_ch]=B[i];
				}
				flag=0;
		 	}
		}	
    }
}
int main(){
	string q;
    S+='#';
	cin>>q;
	S+=q;
	S+='#';
    Prework();
    solve();
    cout<<stack_num[1]<<endl;
	return 0;
}
