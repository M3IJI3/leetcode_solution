class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;

        for(int num : nums){
            count[num]++;
        }

        for(auto& pair: count)
        {
            if(pair.second >= 2){
                return true;
            }
        }
        return false;
    }
};