import java.util.*;
public class Main {
    static int num[] = new int[110];
    static boolean mark[] = new boolean[110];
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), sum = 0;
        for(int i = 1; i <= n; ++i) {
            num[i] = cin.nextInt();
            sum += num[i];
        }
        sum /= (n / 2);
        for(int i = 1; i <= n; ++i){
            if(!mark[i]){
                for(int j = i + 1; j <= n; ++j){
                    if(!mark[j] && num[i] + num[j] == sum){
                        mark[j] = true;
                        System.out.println(i + " " + j);
                        break;
                    }
                }
            }
        }
    }
}

