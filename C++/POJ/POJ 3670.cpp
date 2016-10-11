#include<stdio.h>
                  //arr数组里存储原始序列 maxarr数组里存储子序列  maxarr[len]为长度为len的子序列里 
                 //最后一个数的最优值（也就是最小值（lis中）） 或 第一个数的最优值（也就是最大值（lds中））
int n;
int search_lis(int maxarr[],int len,int x){
	int l=0,r=len-1,mid;
	while(l<=r){//开始寻找x能代替的位置 在lis中，此位置为 x比前一个数大，比后一个数小，返回的就是这个后一个大数的位置
		mid=(l+r)/2;
		if(maxarr[mid]<=x){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return l;
}
int lis(int arr[]){
	int maxarr[30010],len=1,pos;
	maxarr[0]=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>=maxarr[len-1]){//如果此数大于maxarr这个子序列里的最后一个数，那我就把此数放到maxarr队尾
			maxarr[len++]=arr[i];
		}
		else{//否则 找到合适的位置放入
			pos=search_lis(maxarr,len,arr[i]);
			maxarr[pos]=arr[i];
		}
	}
	return len;
}
int search_lds(int maxarr[],int len,int x){
	int l=0,r=len-1,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(maxarr[mid]>=x){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return r+1;
}
int lds(int arr[]){
	int maxarr[30010],len=1;
	maxarr[0]=arr[0];
	for(int i=1;i<n;i++){
		if(maxarr[len-1]>=arr[i]){
			maxarr[len++]=arr[i];
		}
		else{
			int pos=search_lds(maxarr,len,arr[i]);
			maxarr[pos]=arr[i];
		}
	}
	return len;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		int len=0,maxarr[30010],arr[30010];
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		int LIS=lis(arr);
		int LDS=lds(arr);
		int max=LIS>LDS?LIS:LDS;
		printf("%d\n",n-max);
	}
	while(1);
	return 0;
}
