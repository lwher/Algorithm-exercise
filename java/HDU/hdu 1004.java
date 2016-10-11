import java.util.*;
public class Main{
	public static void main(String agrs[]){
		Scanner cin = new Scanner(System.in);
		String s[]=new String[1001];
		String p;
		int sz=0,ans,n;
		int num[]=new int[1001];
		boolean flag;
		while(cin.hasNext()){
			n=cin.nextInt();
			if(n==0) break;
			for(int i=1;i<=sz;i++){
				s[i]="";num[i]=0;
			}
			sz=0;
			for(int i=1;i<=n;i++){
			    p=cin.next();flag=false;
			    for(int j=1;j<=sz;j++){
			    	if(s[j].equals(p)){
			    		num[j]++;flag=true;break;
			    	}
			    }
			    if(flag==false){
			    	s[++sz]=p;num[sz]=1;
			    }
			}
			ans=0;num[0]=0;
			for(int i=1;i<=sz;i++){
				if(num[i]>num[ans]) ans=i;
			}
			System.out.println(s[ans]);
		}
	}
}