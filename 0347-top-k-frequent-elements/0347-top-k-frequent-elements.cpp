class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &[num, freq] : mp) {
            bucket[freq].push_back(num);
        }
        vector<int> ans;

        for (int freq = nums.size(); freq >= 1 && ans.size() < k; freq--) {

            for (int num : bucket[freq]) {
                ans.push_back(num);

                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};