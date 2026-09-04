class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;
        for (string& word : strs) {
            int freq[26] = {};
            for (char c : word) {
                freq[c - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; i++) {
                key += char(freq[i]);   
            }
            mp[key].push_back(word);
        }
        vector<vector<string>> ans;
        for (auto& [key, group] : mp) {
            ans.push_back(move(group));
        }
        return ans;
    }
};