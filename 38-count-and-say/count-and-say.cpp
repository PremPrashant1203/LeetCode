class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        while (--n) {
            string t;

            for (int i = 0; i < s.size();) {
                int j = i;
                while (j < s.size() && s[j] == s[i]) j++;
                t += to_string(j - i) + s[i];
                i = j;
            }

            s = t;
        }

        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna