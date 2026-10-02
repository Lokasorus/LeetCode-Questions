class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        vector<int> pre;
        map<int, int> mpp;
        mpp[0] = -1;
        int n = nums.size();
        int sum = 0;
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        int target = s%p;
        if(target == 0) return 0;
        int mini = nums.size();
        for(int i = 0; i<n; i++){
           
            sum = (sum+ nums[i])%p;
           
            int need = (sum - target + p)%p;
            if(mpp.find(need)!=mpp.end()){
                mini = min(mini, i-mpp[need]);
            }
            mpp[sum] = i;
            
        }
        if(mini == nums.size()) return -1;
        else return mini;

        

        
    }
};