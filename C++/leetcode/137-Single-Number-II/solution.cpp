class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, tmp;
        for(auto it = nums.begin(); it != nums.end(); ++it){
            tmp = (*it) & two;
            two ^= tmp;
            *it ^= tmp;
            tmp = (*it) & one;
            two |= tmp;
            one ^= tmp;
            *it ^= tmp;
            one |= (*it);
        }
        return one;
    }
};