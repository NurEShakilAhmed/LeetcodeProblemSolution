class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int val = num % k;

            vector<long long> next(k, 0);

            // Subarray containing only the current element
            next[val]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newRemainder = (1LL * r * val) % k;
                    next[newRemainder] += dp[r];
                }
            }

            // Add current subarrays to answer
            for (int r = 0; r < k; r++) {
                result[r] += next[r];
            }

            // Move to next position
            dp = next;
        }

        return result;
    }
};
