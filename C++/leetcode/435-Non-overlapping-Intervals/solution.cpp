/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator <(const Interval &a, const Interval &b){
    return a.start < b.start;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end());
        int ans = 0, nr = -10000000;
        for(auto it = intervals.begin(); it != intervals.end(); ++it){
            if((*it).start < nr){
                ++ans;
                if((*it).end < nr)
                    nr = (*it).end;
            }
            else 
                nr = (*it).end;
        }
        return ans;
    }
    
};
