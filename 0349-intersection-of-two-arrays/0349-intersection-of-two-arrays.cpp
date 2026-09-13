class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> s;
        for(int x : nums1) {
            s.insert(x);
        }

        vector<int> ans;
        for(int x : nums2) {

            if(s.count(x)) {
                ans.push_back(x);
                s.erase(x);
            }
        }
        return ans;
    }
};