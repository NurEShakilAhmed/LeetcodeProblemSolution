class Solution {
public:

    bool canSplit(vector<int>& nums, int k, long long maxSum) {

        int parts = 1;
        long long currentSum = 0;

        for(int num : nums) {

            if(currentSum + num <= maxSum) {
                currentSum += num;
            }
            else {
                parts++;
                currentSum = num;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        long long left = *max_element(nums.begin(), nums.end());

        long long right = 0;

        for(int num : nums) {
            right += num;
        }

        while(left <= right) {

            long long mid = left + (right - left) / 2;

            if(canSplit(nums, k, mid)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};