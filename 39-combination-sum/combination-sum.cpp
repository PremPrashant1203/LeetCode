class Solution {
public:
    void solve(vector<int>& a, int target, int start, vector<int>& cur, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i < a.size(); i++) {
            if (a[i] > target) continue;

            cur.push_back(a[i]);
            solve(a, target - a[i], i, cur, ans);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> cur;

        solve(candidates, target, 0, cur, ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna