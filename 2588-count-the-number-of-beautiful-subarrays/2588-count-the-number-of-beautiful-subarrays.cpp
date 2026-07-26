class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, long long> mpp;
        mpp[0] = 1;
        int xr = 0;
        long long cnt = 0;
        for(int i = 0; i<n; i++){
            
            xr = xr^nums[i];
            cnt+=mpp[xr];
    
            mpp[xr]++;
        }
        return cnt;


        
    }
};