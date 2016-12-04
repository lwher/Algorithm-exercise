import java.util.*;
public class Solution {
    public int minCut(String s) {
        int len = s.length();
        Vector v[] = new Vector[len + 1];
        for(int i = 0; i <= len; i++)
            v[i] = new Vector();
        int l, r;
        for(int i = 0; i < len; i++){
            l = i; r = i;
            while(l - 1 >= 0 && r + 1 < len && s.charAt(l - 1) == s.charAt(r + 1)){
                l--; r++;
                v[r + 1].add(l + 1);
            }
            l = i; r = i + 1;
            while(l >= 0 && r < len && s.charAt(l) == s.charAt(r)){
                v[r + 1].add(l + 1);
                l--; r++;
            }
        }
        int f[] = new int[len + 1], Size, tmp;
        f[0] = -1;
        for(int i = 1; i <= len; i++){
            f[i] = f[i - 1] + 1;
            Size = v[i].size();
            for(int j = 0; j < Size; j++){
                int p = (int)v[i].get(j);
                tmp = f[p - 1] + 1;
                if(tmp < f[i])
                    f[i] = tmp;
            }
        }
        return f[len];
    }
}