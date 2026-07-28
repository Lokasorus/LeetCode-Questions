class Solution {
public:
int f(int i, int flag, vector<int>& arr, vector<vector<int>>& dp){
    if(i>=arr.size()) return 0;
    if(dp[i][flag]!= -1) return dp[i][flag];
    if(flag){
        int sum = 0;
        int ans = INT_MIN;
        for(int k = 1; k<=3 && i+k-1<arr.size(); k++){
            sum += arr[i+k-1];
            ans = max(ans, sum + f(i+k, !flag, arr, dp));
        }
        return dp[i][flag] = ans;
    }else{
        int sum = 0;
        int ans = INT_MAX;
        for(int k = 1; k<=3; k++){
            ans = min(ans, f(i+k, !flag, arr, dp));
        }
        return dp[i][flag] = ans;
    }
     
    
}
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        int ans = f(0, 1, stoneValue, dp);
        int tot = 0;
        for(int x: stoneValue){
            tot+=x;
        }

        int bob = tot - ans;
        if(bob>ans) return "Bob";
        else if(ans>bob) return "Alice";
        else return "Tie";


        
    }
};