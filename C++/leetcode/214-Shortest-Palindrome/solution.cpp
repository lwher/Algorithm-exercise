class Solution{
public:
    string shortestPalindrome(string s){
        const int mod1 = 10007, mod2 = 13257;
        int *Hash_mod1_next, *Hash_mod2_next, *Hash_mod1_pre, *Hash_mod2_pre, *pow26_mod1, *pow26_mod2;
        int n = s.size();
        Hash_mod1_next = new int[n + 1];
        Hash_mod2_next = new int[n + 1];
        Hash_mod1_pre = new int[n + 2];
        Hash_mod2_pre = new int[n + 2];
        pow26_mod1 = new int[n + 1];
        pow26_mod2 = new int[n + 1];
        Hash_mod1_next[0] = Hash_mod2_next[0] = 0;
        for(int i = 0; i < n; ++i){
            Hash_mod1_next[i + 1] = (Hash_mod1_next[i] * 26 + s[i] - 'a') % mod1;
            Hash_mod2_next[i + 1] = (Hash_mod2_next[i] * 26 + s[i] - 'a') % mod2;
        }
        Hash_mod1_pre[n + 1] = Hash_mod2_pre[n + 1] = 0;
        for(int i = n; i > 0; --i){
            Hash_mod1_pre[i] = (Hash_mod1_pre[i + 1] * 26 + s[i - 1] - 'a') % mod1;
            Hash_mod2_pre[i] = (Hash_mod2_pre[i + 1] * 26 + s[i - 1] - 'a') % mod2;
        }
        pow26_mod1[0] = pow26_mod2[0] = 1;
        for(int i = 1; i <= n; ++i){
            pow26_mod1[i] = pow26_mod1[i - 1] * 26 % mod1;
            pow26_mod2[i] = pow26_mod2[i - 1] * 26 % mod2;
        }
        int res = n;
        for(int i = 0; i < n; ++i){ //odds
            int R = i + i + 1;
            if(R - 1 >= n) break;
            int strmod1 = (Hash_mod1_pre[i + 1] - Hash_mod1_pre[R + 1] * pow26_mod1[R - i]) % mod1;
            if(strmod1 < 0) strmod1 += mod1;
            int strmod2 = (Hash_mod2_pre[i + 1] - Hash_mod2_pre[R + 1] * pow26_mod2[R - i]) % mod2;
            if(strmod2 < 0) strmod2 += mod2;
            if(Hash_mod1_next[i + 1] == strmod1 && Hash_mod2_next[i + 1] == strmod2)
                res = min(res, n - (i * 2 + 1));
        }
        for(int i = 0; i < n - 1; ++i){ // even
            int R = i + i + 2;
            if(R - 1 >= n) break;
            int strmod1 = (Hash_mod1_pre[i + 2] - Hash_mod1_pre[R + 1] * pow26_mod1[R - i - 1]) % mod1;
            if(strmod1 < 0) strmod1 += mod1;
            int strmod2 = (Hash_mod2_pre[i + 2] - Hash_mod2_pre[R + 1] * pow26_mod2[R - i - 1]) % mod2;
            if(strmod2 < 0) strmod2 += mod2;
            if(Hash_mod1_next[i + 1] == strmod1 && Hash_mod2_next[i + 1] == strmod2)
                res = min(res, n - (i + 1) * 2);            
        }
        string ans = "";
        for(int i = 1; i <= res; ++i){
            ans += s[n - i];
        }
        ans += s;
        return ans;
    }
};