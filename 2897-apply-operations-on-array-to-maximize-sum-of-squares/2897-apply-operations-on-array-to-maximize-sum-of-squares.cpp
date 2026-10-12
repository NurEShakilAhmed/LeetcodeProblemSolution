
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1'000'000'007;
        vector<int> count(31, 0);

        for (int num : nums) {
            for (int bit = 0; bit < 31; bit++) {
                if ((num >> bit) & 1) {
                    count[bit]++;
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int bit = 0; bit < 31; bit++) {
                if (count[bit] > 0) {
                    x |= (1LL << bit);
                    count[bit]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return (int)ans;
    }
};
