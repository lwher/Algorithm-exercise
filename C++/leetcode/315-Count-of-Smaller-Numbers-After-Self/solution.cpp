class Solution {
public:
    int lowbit(int x) {
        return x & -x;
    }

    void BitAdd(int x, int num, int n, vector<int> &bitTree) {
        for (int i = x; i <= n; i += lowbit(i))
            bitTree[i] += num;
    }

    int BitQuery(int x, vector<int> &bitTree) {
        int res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            res += bitTree[i];
        }
        return res;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> realNum;
        for (int i = 0; i < nums.size(); ++i) {
            realNum.push_back(nums[i]);
        }
        sort(realNum.begin(), realNum.end());
        realNum.erase(unique(realNum.begin(), realNum.end()), realNum.end());
        vector<int> result(nums.size());
        vector<int> bitTree(realNum.size() + 1);
        for (int i = nums.size() - 1; i >= 0; --i) {
            int idx = lower_bound(realNum.begin(), realNum.end(), nums[i]) - realNum.begin() + 1;
            result[i] = BitQuery(idx - 1, bitTree);
            BitAdd(idx, 1, realNum.size(), bitTree);
        }
        return result;
    }
};

