import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int T,n;
		int num[]=new int[100001];
		int f[]=new int[100001];
		int fa[]=new int[100001];
		T=cin.nextInt();
	    for(int t=1;t<=T;t++){
	    	n=cin.nextInt();
	    	for(int i=1;i<=n;i++) num[i]=cin.nextInt();
	    	f[1]=num[1];fa[1]=1;
	    	for(int i=2;i<=n;i++){
	    		if(f[i-1]<0){
	    			f[i]=num[i];fa[i]=i;
	    		}
	    		else{
	    			f[i]=f[i-1]+num[i];fa[i]=fa[i-1];
	    		}
	    	}
	    	int ans=0;f[0]=-0x7fffffff;
	    	for(int i=1;i<=n;i++){
	    		if(f[i]>f[ans]) ans=i;
	    	}
	    	System.out.println("Case "+t+":");
	    	System.out.println(f[ans]+" "+fa[ans]+" "+ans);
	    	if(t!=T) System.out.println();
	    }
	}
}
