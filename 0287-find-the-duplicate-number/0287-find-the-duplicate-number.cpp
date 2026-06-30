class Solution {
public:
   int findDuplicate(vector<int>& nums) {
    for (int x : nums) {
        int idx = abs(x);

        if (nums[idx] < 0)
            return idx;

        nums[idx] *= -1;
    }
    return -1;
}
};