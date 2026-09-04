class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length() < p.length()) {
            return ans;
        }
        int freqP[26] = {};
        int freqWindow[26] = {};
        for(char c : p) {
            freqP[c - 'a']++;
        }
        int windowSize = p.length();
        for(int i = 0; i < windowSize; i++) {
            freqWindow[s[i] - 'a']++;
        }
        if(equal(freqP, freqP + 26, freqWindow)) {
            ans.push_back(0);
        }
        for(int i = windowSize; i < s.length(); i++) {
            freqWindow[s[i] - 'a']++;
            freqWindow[s[i - windowSize] - 'a']--;
            if(equal(freqP, freqP + 26, freqWindow)) {
                ans.push_back(i - windowSize + 1);
            }
        }
        return ans;
    }
};