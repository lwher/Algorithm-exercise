import java.util.*;
public class Main {
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), x, res = 0;
        for(int i = 1; i <= n; ++i) {
            x = cin.nextInt();
            if (x % 2 == 0) res ^= 1;
            if(res != 0) System.out.println(1);
            else System.out.println(2);
        }
    }
}

