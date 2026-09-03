class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;

        vector<string> words;
        while(ss >> word) {
            words.push_back(word);
        }
        if(pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> map1;
        unordered_map<string, char> map2;

        for(int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = words[i];
            if(map1.count(c) && map1[c] != w) {
                return false;
            }
            if(map2.count(w) && map2[w] != c) {
                return false;
            }
            map1[c] = w;
            map2[w] = c;
        }
        return true;
    }
};