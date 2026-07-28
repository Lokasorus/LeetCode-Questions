class Solution {
public:
int f(int i, int M, int flag, vector<int>& arr, vector<vector<vector<int>>>& dp){
    if(i>=arr.size()) return 0;
    if(dp[i][M][flag]!=-1) return dp[i][M][flag];

    if(flag){
        int ans = INT_MIN;
        int sum = 0;
        for(int k = 1; k<=2*M && i+k-1<arr.size(); k++){
            sum += arr[i+k-1];
            ans = max(ans, sum + f(i+k, max(M, k), !flag, arr, dp));
        }
        return dp[i][M][flag] = ans;
    }else{
        int ans = INT_MAX;
        for(int k = 1; k<=2*M ; k++){
            ans = min(ans, f(i+k, max(M, k), !flag, arr, dp));
        }
        return dp[i][M][flag] = ans;
    }
}
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        return f(0, 1, 1, piles, dp);
        
        
        

    }
};