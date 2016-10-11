import java.util.*;
public class Main {
    static int num[] = new int[110];
    static int ch[] = new int[100010];
    static boolean appear[] = new boolean[110];
    private static int letter_change(char x){
        if(x >= 'a' && x <= 'z') return x - 'a' + 1;
        else return x - 'A' + 27;
    }
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), sum = 0, ans = n;
        String p = cin.next();
        for(int i = 0; i < n; ++i){
            ch[i] = letter_change(p.charAt(i));
            if(!appear[ch[i]]){
                ++sum;
                appear[ch[i]] = true;
            }
        }

        int now = 0, l = 0;
        for(int i = 0; i < n; ++i){
            ++num[ch[i]];
            if(num[ch[i]] == 1) ++now;
            while(num[ch[l]] > 1){
                --num[ch[l]];
                ++l;
            }
            //System.out.println(l + " " + i);
            if(now == sum && i - l + 1 < ans)
                ans = i - l + 1;
        }
        System.out.println(ans);
    }
}

