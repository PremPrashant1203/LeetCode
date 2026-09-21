class Solution {
public:
    void generate(int open, int close, int n, string current,
                  vector<string>& ans) {
        
        // We have used all n pairs
        if (current.size() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // We can add an opening bracket
        if (open < n) {
            generate(open + 1, close, n, current + "(", ans);
        }

        // We can add a closing bracket only if
        // there are more opening brackets available
        if (close < open) {
            generate(open, close + 1, n, current + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        generate(0, 0, n, "", ans);

        return ans;
    }
};