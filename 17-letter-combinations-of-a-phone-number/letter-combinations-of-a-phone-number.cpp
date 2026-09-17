class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> phone = {
            "", "", "abc", "def", "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string current;

        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                ans.push_back(current);
                return;
            }

            string letters = phone[digits[index] - '0'];

            for (char ch : letters) {
                current.push_back(ch);
                backtrack(index + 1);
                current.pop_back();
            }
        };

        backtrack(0);

        return ans;
    }
};