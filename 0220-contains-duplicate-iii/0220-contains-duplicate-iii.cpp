class Solution {
public:
long long getBucket(int x, int size){
    if(x>=0) return x/size;
    return ((long long) x+1)/size-1;
}
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
 set<int> st;
        int i = 0;
        int n = nums.size();
        int bucketSize = (long long)valueDiff+1;
        unordered_map<int, int> bucket;

        while(i<n){
            long long x = nums[i];
            int j = getBucket(nums[i], bucketSize);
            if(bucket.count(j)){
                return true;
            }
            if(bucket.count(j-1) && abs(bucket[j-1] - x) <= valueDiff){
                return true;
            }

            if(bucket.count(j+1) && abs(bucket[j+1] - x) <= valueDiff){
                return true;
            }
            bucket[j] = x;
            if(i>=indexDiff){
                int k = getBucket(nums[i-indexDiff], bucketSize);
                bucket.erase(k);
            }
            i++;
        }
        return false;

            
    }
};