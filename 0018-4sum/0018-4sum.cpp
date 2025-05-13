class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0 ; i < n - 3 ; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1 ; j < n - 2 ; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                int x = j + 1;
                int y = n - 1;

                long long new_target = (long long)target - nums[i] - nums[j];
                while(x < y){
                    long long sum = (long long)nums[x] + nums[y];
                    if(sum == new_target){
                        answer.push_back({nums[i], nums[j], nums[x], nums[y]});
                        // 记住每次将结果计入时 需要立即更新索引位置
                        x++;
                        y--;

                        while(x < y && nums[x] == nums[x-1]) x++;
                        while(x < y && nums[y] == nums[y+1]) y--;

                    } else if(sum < new_target){
                        x++;
                    } else {
                        y--;
                    }
                }
            }
        }

        return answer;
    }
};