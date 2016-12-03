public class Solution {
    private int max(int a, int b){
        if(a > b) return a;
        else return b;
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int lmax[] = new int[n], rmax[] = new int[n];
        if(n <= 1)
            return 0;
        int minx = prices[0];
        lmax[0] = -1000000000;
        for(int i = 1; i < n; i++){
            lmax[i] = max(lmax[i - 1], prices[i] - minx);
            if(prices[i] < minx) minx = prices[i];
        }
        int maxx = prices[n - 1]; 
        rmax[n - 1] = -1000000000;
        for(int i = n - 2; i >= 0; i--){
            rmax[i] = max(rmax[i + 1], maxx - prices[i]);
            if(prices[i] > maxx) maxx = prices[i];
        }
        int ans = lmax[n - 1];
        for(int i = 1; i < n - 2; i++){
            ans = max(ans, lmax[i] + rmax[i + 1]);
        }
        if(ans < 0) ans = 0;
        return ans;
    }
}