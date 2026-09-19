class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        long long total = 0;

        for(int x : nums) {
            total += x;
        }

        int target = total % p;
        if(target == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long long prefix = 0;

        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++) {

            prefix += nums[i];

            int current = prefix % p;

            int needed = (current - target + p) % p;

            if(mp.find(needed) != mp.end()) {

                ans = min(ans, i - mp[needed]);
            }

            mp[current] = i;
        }

        if(ans == nums.size())
            return -1;

        return ans;
    }
};