import java.util.*;
public class Main {

    public static void  main(String args[]){
        Scanner cin = new Scanner(System.in);
        int T, n, now, x;
        boolean flag;
        T = cin.nextInt();
        for(int i = 1; i <= T; i++){
            n = cin.nextInt();
            flag = false; now = 0;
            for(int j = 1; j <= n; j++){
                x = cin.nextInt();
                if(x != 1) flag = true;
                now ^= x;
            }
            if(flag){
                if(now == 0) System.out.println("Brother");
                else System.out.println("John");
            }
            else{
                if(now == 0) System.out.println("John");
                else System.out.println("Brother");
            }
        }

    }

}

