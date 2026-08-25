class Solution {
public:
long long f(int i, vector<long long>& points, vector<long long>& dp){
    if(i<0)return 0;
    if(dp[i]!= -1) return dp[i];
    long long nottake = f(i-1, points, dp);
    long long take = points[i] + f(i-3, points,dp);
    return dp[i] = max(take, nottake);
}
    long long maximumTotalDamage(vector<int>& power) {

        int maxi = -1e9;
        for(auto it: power){
            maxi = max(maxi, it);
        }
        vector<long long> points(maxi+1);
        for(int i = 0; i<power.size(); i++){
            points[power[i]] += power[i];
        }

        vector<long long> dp(maxi+1, -1);
        return f(maxi, points, dp);
        
    }
};