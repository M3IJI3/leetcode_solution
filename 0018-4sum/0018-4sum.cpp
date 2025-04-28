class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue; // 去重
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue; // 去重

                int left = j + 1, right = n - 1;
                long long new_target = (long long)target - nums[i] - nums[j];
                while (left < right) {
                    int sum = nums[left] + nums[right];

                    if (sum == new_target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left + 1] == nums[left])
                            left++;
                        while (left < right && nums[right - 1] == nums[right])
                            right--;

                        left++;
                        right--;
                    } else if (sum < new_target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};