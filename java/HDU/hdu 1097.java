import java.util.*;
public class Main {

    private static int quick_pow(int A, int B){
        int res = 1;
        A %= 10;
        while(B > 0){
            if((B & 1) == 1) res = res * A % 10;
            A = A * A % 10;
            B = B >> 1;
        }
        return res;
    }

    public static void  main(String args[]){
        Scanner cin = new Scanner(System.in);
        int a, b;
        while(cin.hasNextInt()){
            a = cin.nextInt();
            b = cin.nextInt();
            int ans = quick_pow(a, b);
            System.out.println(ans);
        }
    }

}

