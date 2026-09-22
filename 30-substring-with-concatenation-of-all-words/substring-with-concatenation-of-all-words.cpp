class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = words.size(), len = words[0].size();

        unordered_map<string, int> need;
        for (auto& w : words) need[w]++;

        for (int i = 0; i < len; i++) {
            unordered_map<string, int> have;
            int left = i, count = 0;

            for (int j = i; j + len <= s.size(); j += len) {
                string word = s.substr(j, len);

                if (!need.count(word)) {
                    have.clear();
                    count = 0;
                    left = j + len;
                    continue;
                }

                have[word]++;
                count++;

                while (have[word] > need[word]) {
                    string x = s.substr(left, len);
                    have[x]--;
                    left += len;
                    count--;
                }

                if (count == n) {
                    ans.push_back(left);
                    string x = s.substr(left, len);
                    have[x]--;
                    left += len;
                    count--;
                }
            }
        }

        return ans;
    }
};