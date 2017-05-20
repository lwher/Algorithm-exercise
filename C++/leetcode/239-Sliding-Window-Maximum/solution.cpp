class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int *Queue = new int[n + 1];
        int t = 1, w = 0;
        vector<int> res;
        for(int i = 0; i < n; ++i){
            while(t <= w && nums[i] >= nums[Queue[w]]) --w;
            Queue[++w] = i;
            while(t <= w && i - Queue[t] >= k) ++t;
            if(i >= k - 1)
                res.push_back(nums[Queue[t]]);
        }
        return res;
    }
};