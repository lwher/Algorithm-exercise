class Solution {
public:
    int f[51][51][51];
    string A, B;
    
    inline bool the_same(int x, int y, int L){
        for(int i = 0; i < L; ++i)
            if(A[x + i] != B[y + i])
                return false;
        return true;
    }
    
    bool dfs(int x, int y, int L){
        if(f[x][y][L] != -1)
            return f[x][y][L] == 1 ? true : false;
        if(L == 1 && A[x] != B[y])
            return false;
        if(the_same(x, y, L)){
            f[x][y][L] = 1;
            return true;
        }
        for(int i = 1; i < L; ++i){
            if((dfs(x, y, i) && dfs(x + i, y + i, L - i)) || (dfs(x, y + L - i, i) && dfs(x + i, y, L - i))){
                f[x][y][L] = 1;
                return true;
            }
        }
        f[x][y][L] = 0;
        return false;
    }
    
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        A = s1; B = s2;
        memset(f, -1, sizeof(f));
        return dfs(0, 0, len);
    }
};