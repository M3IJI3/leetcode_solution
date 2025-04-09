class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // vector<string> ans;
        // int left = 0;
        // int right = 1;

        // for(int i  = 0 ; i < nums.size() - 1 ; i++){
        //     if(nums[right] - nums[i] == 1){
        //         right += 1;
        //     } else {
        //         std::string str = std::to_string(nums[left]) + "->" + std::to_string(nums[right - 1]);
        //         left = right;
        //         ans.push_back(str);
        //     }
        // }
        // return ans;
        ////////////////////////////////////////////

        vector<string> result;
        if(nums.empty()) return result;

        int start = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            // 1. check if the index 'i' reach the last element
            // 2. check if the next element is consecutive, by subtracting the adjacent elements
            if(i == nums.size() - 1 || nums[i + 1] != 1 + nums[i]){
                // Check if the start element is same with the current one
                // if it does,
                if(start == nums[i]){
                    result.push_back(std::to_string(start));
                } 
                // if it doesn't,
                else {
                    result.push_back(std::to_string(start) + "->" + std::to_string(nums[i]));
                }

                // update 'start' if i haven't reach to last
                if(i < nums.size() - 1){
                    start = nums[i + 1];
                }
            }
        }
        return result;
    }
};