import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int n,sum;
		while(cin.hasNextInt()){
			sum=0;
			n=cin.nextInt();
			for(int i=1;i<=n;i++) sum+=i;
			System.out.println(sum);
			System.out.println();
		}
	}
}