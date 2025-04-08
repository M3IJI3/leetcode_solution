class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;

        for(int num: nums){
            count[num]++;
        }

        int maxValue = INT_MIN;
        int majorityElement;
        for(auto& pair : count){
            if(pair.second > maxValue){
                maxValue = pair.second;
                majorityElement = pair.first;
            }
        }
        return majorityElement;
    }
};