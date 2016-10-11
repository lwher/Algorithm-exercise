import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int f[]=new int[10000];
		int A,B,n,i;
		while(cin.hasNextInt()){
			A=cin.nextInt();
			B=cin.nextInt();
			n=cin.nextInt();
			if(A==0 || B==0 || n==0) break;
			f[1]=1;f[2]=1;
			for(i=3;i<10000;i++){
				f[i]=(A*f[i-1]+B*f[i-2])%7;
				if(f[i-1]==1 && f[i]==1) break;
			}
			i-=2;n=n%i;
			if(n==0) n+=i;
			System.out.println(f[n]);
		}
	}
}