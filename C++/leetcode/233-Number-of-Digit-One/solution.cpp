class Solution {
public:
    int countDigitOne(int n) {
        int f[17], mi_10[17];
        mi_10[0] = 1; mi_10[1] = 10; f[0] = 0; f[1] = 1;
        for(int i = 2; i < 17; ++i){
            mi_10[i] = mi_10[i - 1] * 10;
            f[i] = f[i - 1] * 10 + mi_10[i - 1];
        }
        int num[17], top = 0;
        ++n;
        while(n > 0){
            num[++top] = n % 10;
            n /= 10;
        }
        int res = 0, sum_1 = 0;
        for(int i = top; i > 0; --i){
            if(num[i] == 0) continue;
            res += f[i - 1] * num[i];
            res += sum_1 * mi_10[i - 1] * num[i];
            if(num[i] > 1) res += mi_10[i - 1];
            if(num[i] == 1){
                ++sum_1;
            }
        }
        return res;
    }
};