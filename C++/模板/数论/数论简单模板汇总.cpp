//数论多个模板的汇总
//0、快速幂
int quickpow(int a,int b,int p){// a ^ b % p
	int res=1;
	while(b>0){
		if(b & 1) res=(res*a)%p;
		b>>=1;
		a=(a*a)%p;
	}
	return res;
}

//1、线筛素数 筛出1-N的素数 
int prime[N],tot;
bool mark[N];
void getphi(){  
   for(int i=2;i<=N;i++){
       if(!mark[i])  prime[++tot]=i;
       for(int j=1;j<=tot;j++){
          if(i*prime[j]>N)  break;
          mark[i*prime[j]]=1;
          if(i%prime[j]==0) break;
       }
   }
}
//2、线筛逆元 在满足条件的情况下，筛出1~p-1关于p的逆元 
for(i=2;i<p;i++) Inv[i]=(Inv[p%i]*(p-p/i))%p;

//3、求解欧拉函数 
//(1)复杂度 sqrt(n)
int getphi(int x){
	phi=1;
	for(i=2;i*i<=x;i++){
		if(x%i==0){
			x/=i;phi*=i-1;
			while(x%i==0){
				x/=i;phi*=i;
			}
		}
	}
	if(x>1)	phi*=x-1;
	return phi;
}		
//(2)线筛1~N的欧拉函数
int phi[],prime[],tot;
bool mark[]; 
void getphi(){
	phi[1]=1;
	for(int i=2;i<=N;i++){
		if(!check[i])  {tot++;prime[tot]=i;phi[i]=i-1;}
		for(int j=1;j<=tot;j++){
			if(i*prime[j]>1000)  break;
			check[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i * prime[j]]=phi[i]*prime[j];break;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
} 
/*4、线筛莫比乌斯函数 
对于一个数，u值定义如下：
	1、如果存在某个平方或以上的素因子 : 0
	2、如果存在奇数个不同的素因子 ：-1
	2、如果存在偶数个不同的素因子 ：1
*/
int tot,prime[],u[]; 
bool mark[]; 
void getu(){  
    u[1]=1; 
    for(int i=2;i<=N;i++) { 
        if(!mark[i])  {prime[++tot]=i;u[i]=1;} 
        for(int j=1;j<=tot;j++) { 
            if(i*prime[j]>N)  break; 
            mark[i*prime[j]]=1; 
            if(i%prime[j]==0){
				u[i*prime[j]]=0;break;
			} 
            else u[i*prime[j]]=u[i]*(-1); 
        } 
    } 
}  
//5、扩展欧几里得算法 ax+by=gcd(a,b)
long long x,y;
int exgcd(int a,int b){
    if(b==0){
        x=1;y=0;
		return a;
    }
    int d=exgcd(b,a%b),t=x;
    x=y;
    y=t-a/b*y;
    return d;
} 
//6、降幂大法：
//A ^ phi(P) = 1 (mod P) (A,P互质)  
//由上式可得：当P为质数时，phi(P)=P-1  因此A ^ (P-2) * A = 1 (mod P),即A ^ (P-2)为A关于P的逆元 
//对于矩阵，当A可逆时，降幂大法依然成立

//7、辛普森积分
//S = (f(l) + f(r) + 4 * f(mid)) * (r - l) / 6 
//为保证精度，需要自适应公式：f(x)为计算函数在x位置的y值也可以说是覆盖的长度，因题而异 
double calc(double len,double fl,double fmid,double fr){
    return (fl+fr+4*fmid)*len/6;
}
double simpson(double l,double mid,double r,double fl,double fmid,double fr,double s){
    double m1=(l+mid)*0.5,m2=(mid+r)*0.5;
    double fm1=f(m1),fm2=f(m2);
    double s1=calc(mid-l,fl,fm1,fmid),s2=calc(r-mid,fmid,fm2,fr);
    if(fabs(s-s1-s2)<eps)  return s1+s2;
    return simpson(l,m1,mid,fl,fm1,fmid,s1)+simpson(mid,m2,r,fmid,fm2,fr,s2);
}

/*8、卡特兰数列
//f[0]=1,f[1]=1
//递推公式:f[n]=f[0]*f[n-1]+f[1]*f[n-2]+...f[n-1]*f[0](n>=2) 
//组合数:f[n]=C(2n,n)-C(2n,n-1)，f[n]=C(2n,n)/(n+1)
//应用：出栈次序、凸多边形三角划分、n个节点的二叉树等 
*/



