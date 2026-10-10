
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,vector<int>& nums2,int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> diff;
        long long mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            mx = max(mx, d);
        }

        long long total = 0;
        for (long long d : diff) total += d;

        if (total <= k) return 0;

        long long low = 0, high = mx;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long needed = 0;

            for (long long d : diff) {
                needed += max(0LL, d - mid);
            }

            if (needed <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long level = low;
        long long used = 0;
        long long ans = 0;

        for (long long d : diff) {
            long long reduced = min(d, level);
            used += d - reduced;
            ans += reduced * reduced;
        }

        long long remaining = k - used;

        for (long long d : diff) {
            if (remaining == 0) break;

            if (d >= level && level > 0) {
                ans -= level * level;
                ans += (level - 1) * (level - 1);
                remaining--;
            }
        }

        return ans;
    }
};
