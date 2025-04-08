class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int n = nums.size();

        // for(int i = 0 ; i < n - 1 ; i++){
        //     for(int j = i + 1 ; j < n ; j++){
        //         if(nums[i] + nums[j] == target){
        //             return {i , j};
        //         }
        //     }
        // }
        // return {};
        /////////////////////////////////////////////

        // unordered_map<int, int> numMap; // define hashtable
        // int n = nums.size();            // length of array

        // for(int i = 0 ; i < n ; i++)
        // {
        //     numMap[nums[i]] = i;
        // }

        // for(int i = 0 ; i < n ; i++)
        // {
        //     int complement = target - nums[i];
        //     if(numMap.count(complement) && nums[complement] != i){
        //         return {i, numMap[complement]};
        //     }
        // }
        // return {};
        //////////////////////////////////////////////

        unordered_map<int, int> numMap;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++)
        {
            int complement = target - nums[i];
            if(numMap.count(complement)){
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};