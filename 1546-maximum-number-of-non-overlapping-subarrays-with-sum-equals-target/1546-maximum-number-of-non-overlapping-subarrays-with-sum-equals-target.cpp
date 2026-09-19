class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {

        unordered_map<long long, int> mp;

        mp[0] = -1;

        long long prefix = 0;

        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {

            prefix += nums[i];

            if(mp.find(prefix - target) != mp.end()) {

                ans++;
                mp.clear();

                mp[0] = i;

                prefix = 0;
            }
            else {
                mp[prefix] = i;
            }
        }
        return ans;
    }
};