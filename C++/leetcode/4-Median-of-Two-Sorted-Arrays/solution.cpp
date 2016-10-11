class Solution {
public:
	int find_rank_num(vector<int>& nums1, vector<int>& nums2, int K){
		int n = nums1.size();
		int m = nums2.size();
		
		if(n == 0) return nums2[K - 1];
		if(m == 0) return nums1[K - 1];
		
		if(n <= K && nums2[K - n] >= nums1[n - 1]){
			if(n < K && nums1[n - 1] < nums2[K - n - 1]) return nums2[K - n - 1];
			else return nums1[n - 1];
		}
		if(n > K && nums2[0] >= nums1[K - 1])
			return nums1[K - 1];
		
		if(m <= K && nums1[K - m] >= nums2[m - 1]){
			if(m < K && nums1[K - m - 1] >= nums2[m - 1]) return nums1[K - m - 1];
			else return nums2[m - 1];
		}
		if(m > K && nums1[0] >= nums2[K - 1])
			return nums2[K - 1];
		
		int l = (m < K) ? K - m - 1 : 0;
		int r = (n > K) ? K - 1: n - 1;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			if(nums2[K - mid - 1] >= nums1[mid])
				l = mid;
			else 
				r = mid;
		}
		int w;
		if(nums1[r + 1] >= nums2[K - r - 2] && nums2[K - r - 1] >= nums1[r]) w = r;
		else w = l;
		if(nums1[w] >= nums2[K - w - 2]) return nums1[w];
		else return nums2[K - w - 2];
	}
	
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
		int m = nums2.size();
		if((n + m) & 1)
			return (double)find_rank_num(nums1, nums2, ((n + m) >> 1) + 1);
		else
			return (double)(find_rank_num(nums1, nums2, ((n + m) >> 1) + 1) + find_rank_num(nums1, nums2, ((n + m) >> 1))) * 0.5;
    }
};