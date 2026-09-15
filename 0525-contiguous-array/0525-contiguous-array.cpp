class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mp;

        mp[0] = -1;

        int sum = 0;
        int longest = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 0)
                sum--;
            else
                sum++;

            if(mp.count(sum)) {

                int length = i - mp[sum];

                longest = max(longest, length);

            }
            else {

                mp[sum] = i;
            }
        }
        return longest;
    }
};