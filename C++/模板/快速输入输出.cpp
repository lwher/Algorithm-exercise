/*
	快速读入 将整数转为字符串再读入
	对于百万级别的数据输入有较为明显的效果 
*/
int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0' && ch<='9')){ch=getchar();if(ch=='-') f=-1;}
	while(ch>='0' && ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
long long read(){
	long long x=0,f=1;char ch=getchar();
	while(!(ch>='0' && ch<='9')){ch=getchar();if(ch=='-') f=-1;}
	while(ch>='0' && ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
/*
	 快速输出 加快输出的速度 
*/
void print(int x,char ZF)//输出数字x,后面可以跟一个字符，如空格、换行等 
{
    if(x==0){
		putchar('0');putchar(ZF);return;
	}
    int num=0;char ch[10];
    while(x>0) ch[++num]=(x%10+'0'),x/=10;
    while(num>0) putchar(ch[num--]);
    putchar(ZF);
}
