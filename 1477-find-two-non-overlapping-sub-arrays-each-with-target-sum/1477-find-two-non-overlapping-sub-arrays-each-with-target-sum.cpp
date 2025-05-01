class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> best(n, INT_MAX);

        int sum = 0, left = 0;
        int ans = INT_MAX;
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                int currLen = right - left + 1;

                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, currLen + best[left - 1]);
                }

                minLen = min(minLen, currLen);
            }

            best[right] = minLen;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};