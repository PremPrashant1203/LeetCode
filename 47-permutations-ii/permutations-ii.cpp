class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int i = idx; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;

            used.insert(nums[i]);

            swap(nums[idx], nums[i]);

            solve(nums, idx + 1, ans);

            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        solve(nums, 0, ans);

        return ans;
    }
};