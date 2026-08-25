class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;

        int maxi = -1e9;
        for(auto it: arr){
            maxi = max(maxi, it);
        }
        int size = max(maxi, maxi-difference);

        int ans = 1;

        for(auto x: arr){
            dp[x] = dp[x-difference]+1;
            
            ans = max(ans, dp[x]);
        }
        return ans;


        
    }
};