class Solution {
public:
    string minWindow(string s, string t) {

        int need[128] = {};

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int required = t.length();

        int start = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < s.length(); right++) {

            if (need[s[right]] > 0) {
                required--;
            }

            need[s[right]]--;

            while (required == 0) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                need[s[left]]++;

                if (need[s[left]] > 0) {
                    required++;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};