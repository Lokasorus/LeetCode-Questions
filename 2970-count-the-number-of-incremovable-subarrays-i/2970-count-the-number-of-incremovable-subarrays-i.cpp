class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                int last = -1;
                bool flag = true;
                for(int k = 0; k<i; k++){
                    if(nums[k]>last){
                        last = nums[k];
                    }else{
                        flag = false;
                        break;
                    }
                }
                for(int k = j+1; k<n; k++){
                    if(nums[k] > last){
                        last = nums[k];
                    }else{
                        flag = false;
                        break;
                    }
                }
                if(flag) ans++;
            }
            
        }

        return ans;
    }
};