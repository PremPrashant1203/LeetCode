class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = nums[0];
        int maximum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            current = max(nums[i], current + nums[i]);
            maximum = max(maximum, current);
        }

        return maximum;
    }
};