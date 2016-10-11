import java.util.*;

public class Main{
    static int A[] = new int [21];
    static int n, sum;
    static boolean mark[] = new boolean [21];

    private static boolean dfs(int now, int len, int pos){
        if(now == 5) return true;
        if(len == sum){
            if(dfs(now + 1, 0, 1)) return true;
            else return false;
        }
        for(int i = pos; i <= n; i++){
            if(mark[i] || len + A[i] > sum) continue;
            mark[i] = true;
            if(dfs(now, len + A[i], i + 1)) return true;
            mark[i] = false;
        }
        return false;
    }

    private static void solve(){
        if(sum % 4 != 0){
            System.out.println("no");
            return;
        }
        sum /= 4;
        for(int i = 1; i <= n; i++){
            if(A[i] > sum){
                System.out.println("no");
                return;
            }
        }
        if(dfs(1,0,1)) System.out.println("yes");
        else System.out.println("no");
    }

    public static void  main(String args[]){
        Scanner cin = new Scanner(System.in);
        int T;
        T = cin.nextInt();
        for(int tt = 1; tt <= T; tt++){
            sum = 0;
            n = cin.nextInt();
            for(int i = 1; i <= n; i++) {
                A[i] = cin.nextInt();
                mark[i] = false;
                sum += A[i];
            }
            solve();
        }
    }

}
