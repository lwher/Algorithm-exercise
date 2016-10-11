import java.util.*;
public class Main {
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        int n, ty = 0;
        n = cin.nextInt();
        for(int i = 1; i < n; ++i){
            if(ty == 0) System.out.print("I hate that ");
            else System.out.print("I love that ");
            ty ^= 1;
        }
        if(ty == 0) System.out.println("I hate it");
        else System.out.println("I love it");
    }
}

