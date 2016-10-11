import java.util.*;
public class Main {
    static boolean X[] = new boolean[100010], Y[] = new  boolean[100010];
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        int n, m, leftx, lefty, x, y;
        n = cin.nextInt(); m = cin.nextInt();
        leftx = n; lefty = n;
        long ans = (long)(n) * n;
        for(int i = 1; i <= m; ++i) {
            x = cin.nextInt();
            y = cin.nextInt();
            if(!X[x]){
                ans -= lefty;
                --leftx;
                X[x] = true;
            }
            if(!Y[y]){
                ans -= leftx;
                --lefty;
                Y[y] = true;
            }
            if(i != m) System.out.print(ans + " ");
            else System.out.println(ans);
        }
    }
}

