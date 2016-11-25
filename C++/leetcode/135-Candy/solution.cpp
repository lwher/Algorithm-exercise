class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int *A = new int[n];
        A[0] = 1;
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1])
                A[i] = A[i - 1] + 1;
            else
                A[i] = 1;
        }
        int now = 1;
        ans += A[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1])
                now++;
            else
                now = 1;
            ans += max(now, A[i]);
        }
        delete [] A;
        return ans;
    }
};
