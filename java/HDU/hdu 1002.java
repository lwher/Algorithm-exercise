import java.math.*;
import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int T;
		BigInteger a,b;
		T=cin.nextInt();
		for(int i=1;i<=T;i++){
			a=cin.nextBigInteger();
			b=cin.nextBigInteger();
			System.out.println("Case "+i+":");
			System.out.println(a+" + "+b+" = "+a.add(b));
			if(i!=T) System.out.println();
		}
	}
}