class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;

        for(int num: nums){
            map[num]++;
        }

        for(auto& pair: map){
            if(pair.second == 1){
                return pair.first;
            }
        }
        return -1;
    }
};