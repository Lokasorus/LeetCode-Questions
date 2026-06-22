class Solution {
public:
void bucketSort(vector<int>& nums, int n){
    int maxi = *max_element(nums.begin(), nums.end());
    int mini = *min_element(nums.begin(), nums.end());
    int Range = (maxi -mini)/n +1;
    vector<vector<int>> buckets(n);
    for(int i = 0; i<n; i++){
        int idx = (nums[i]-mini)/Range;
        buckets[idx].push_back(nums[i]);
    }

    int k = 0;
    
    for(int i = 0; i<n; i++){
        sort(buckets[i].begin(), buckets[i].end());
        for(int x: buckets[i]){
            nums[k++] = x;

        }
    }
}
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        bucketSort(nums, n);
        int maxi =0;
        for(int i = 0; i<nums.size()-1; i++){
            maxi = max(maxi, nums[i+1]-nums[i]);
        }
        return maxi;
        
    }
};