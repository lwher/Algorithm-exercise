import java.util.*;

public class Main {

    public static void  main(String args[]){
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext()){
            String s = cin.nextLine();
            if(s.charAt(0) == '#') break;
            String p[] = s.split(" +");
            int ans = 0, n = p.length;
            boolean flag;
            for(int i = 0; i < n; i++){
                flag = false;
                for(int j = 0; j < i; j++){
                    if(p[i].equals(p[j])){
                        flag = true;
                        break;
                    }
                }
                if(!flag) ans++;
            }
            System.out.println(ans);
        }
    }
}
