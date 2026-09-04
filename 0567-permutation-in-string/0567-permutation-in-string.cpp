class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return false;
        }
        int freq1[26] = {};
        int freqWindow[26] = {};
        for(char c : s1) {
            freq1[c - 'a']++;
        }
        int windowSize = s1.length();
        for(int i = 0; i < windowSize; i++) {
            freqWindow[s2[i] - 'a']++;
        }
        if(equal(freq1, freq1 + 26, freqWindow)) {
            return true;
        }
        for(int i = windowSize; i < s2.length(); i++) {
            freqWindow[s2[i] - 'a']++;
            freqWindow[s2[i - windowSize] - 'a']--;
            if(equal(freq1, freq1 + 26, freqWindow)) {
                return true;
            }
        }
        return false;
    }
};