#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int numbed,visted[30];
int main(){
	while(scanf("%d",&numbed),numbed){
	  memset(visted,0,sizeof(visted));
	  string ss;
	  cin>>ss;
	  int num=numbed;
	  int sum=0;
	  int len=ss.size();
	  for(int i=0;i<len;++i){
		  if(visted[ss[i]-'A']==2)
			  continue;
		  else if(num<=0&&!visted[ss[i]-'A']){sum++;visted[ss[i]-'A']=2;}
		  else if(!visted[ss[i]-'A']&&num){
		    visted[ss[i]-'A']=1;
			num--;
		  }
		  else if(visted[ss[i]-'A']){
		    num++;
		  }
	  }
	  if(sum==0)printf("All customers tanned successfully.\n");
	  else printf("%d customer(s) walked away.\n",sum);
	}
  return 0;
}
