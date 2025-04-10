class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> map;

        // initialize an increment key:value map, and
        // set all value to 0
        for(int i = 1 ; i <= nums.size() ; i++){
            map[i] = 0;
        }

        for(int num: nums){
            map[num]++;
        }

        int repeat = 0;
        int complement = 0;

        for(const auto& pair: map){
            if(pair.second == 2){
                repeat = pair.first;
            } else if(pair.second == 0) {
                complement = pair.first;
            }
        }

        return {repeat, complement};
    }
};