class Solution {
public:
void countSort(vector<int> &nums, int n, int exp){
    vector<int> ans(n);
    vector<long long> cnt(10, 0);
    for(int i = 0; i<nums.size(); i++){
        cnt[(nums[i]/exp)%10]++;
    }
    for(int i = 1; i<10; i++){
        cnt[i]+=cnt[i-1];
    }
    for(int i = n-1; i>=0; i--){
        ans[cnt[(nums[i]/exp)%10] -1] = nums[i];
        cnt[(nums[i]/exp)%10]--;
    }
    for(int i = 0; i<n; i++){
        nums[i] = ans[i];
    }
}
void radixSort(vector<int>& nums, int n){
    int maxi = *max_element(nums.begin(), nums.end());
    for(long long exp = 1; maxi/exp>0; exp*=10){
        countSort(nums, n, exp);
    }
    
}
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        radixSort(nums, n);
        int maxi =0;
        for(int i = 0; i<nums.size()-1; i++){
            maxi = max(maxi, nums[i+1]-nums[i]);
        }
        return maxi;
        
    }
};