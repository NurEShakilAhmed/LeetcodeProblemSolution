class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        freq[0] = 1;

        int prefixSum = 0;
        int ans = 0;

        for(int x : nums) {

            if(x % 2 == 1)
                prefixSum++;

            int needed = prefixSum - k;

            if(freq.find(needed) != freq.end()) {
                ans += freq[needed];
            }

            freq[prefixSum]++;
        }

        return ans;
    }
};