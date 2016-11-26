class Solution {
public:
    int numDistinct(string s, string t) {
        int la = s.size(), lb = t.size();
        if(la == 0)
            return 0;
        int *f[2];
        for(int i = 0; i < 2; i++)
            f[i] = new int[lb + 1];
        int p = 0, q = 1;
        for(int i = 0; i <= lb; i++)
            f[p][i] = 0;
        f[p][0] = 1;
        for(int i = 1; i <= la; i++){
            for(int j = 0; j <= lb; j++){
                f[q][j] = f[p][j];
                if(j > 0 && s[i - 1] == t[j - 1])
                    f[q][j] += f[p][j - 1];
            }
            p ^= 1; q ^= 1;
        }
        int ans = f[p][lb];
        for(int i = 0; i < 2; i++)
            delete [] f[i];
        return ans;
    }
};
