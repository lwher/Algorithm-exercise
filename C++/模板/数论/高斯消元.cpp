/*
    高斯消元 时间复杂度：O(N^3)
    1、解实数方程组 
    如果消完发现后面部分还有系数全是0而结果不是0的方程，则无解；
    如果消完发现后面部分有系数和结果全是0的方程，则有自由元（即无数解） 
    2、解异或方程组
    如果消完发现后面部分还有系数全是0而结果不是0的方程，则无解；
    如果消完发现后面部分某行有系数和结果全是0的方程，则有一个自由元（即多解）
    解的数量 num = 2^(自由元数量)  
*/
//1、解实数方程组
void Gauss(int N){
    int i,j,k,now=1;double t;
    for(i=1;i<=N;i++){
        for(j=now;j<=N;j++) if(fabs(A[j][i])>eps) break;
        if(j>N) continue;
        if(j!=now) for(k=1;k<=N+1;k++) swap(A[now][k],A[j][k]);
        t=A[now][i]; for(k=1;k<=N+1;k++) A[now][k]/=t;
        for(j=1;j<=N;j++){
            if(now==j) continue;
            t=A[j][i];
            for(k=1;k<=N+1;k++) A[j][k]-=t*A[now][k];
        }
        now++;
    }
    for(i=now;i<=N;i++) if(A[i][N+1]!=0) //无解
    if(now!=N+1) //无数解 
}
//2、解异或方程组(求可行解的数量)
int Gauss(int N){
	int i,j,k,now=1;
	for(i=1;i<=N;i++){
		for(j=now;j<=N;j++) if(A[j][i]) break;
		if(j>N) continue;
		if(j!=now) for(k=1;k<=N+1;k++) swap(A[now][k],A[j][k]);
		for(j=1;j<=N;j++)
		if(j!=now && A[j][i]){
			for(k=1;k<=N+1;k++) A[j][k]^=A[now][k];
		}
		++now;
	}
	for(i=now;i<=N;i++) if(A[i][N+1]) return 0; //无解 
	int ans=1;
	for(i=now;i<=N;i++) ans=(ans<<1) % mod;
	return ans;
}
