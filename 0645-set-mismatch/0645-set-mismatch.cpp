class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> ans;

        // initialize an increment key:value map, and
        // set all value to 0
        for(int i = 1 ; i <= nums.size() ; i++){
            map[i] = 0;
        }

        for(int num: nums){
            map[num]++;
        }

        for(const auto& pair: map){
            if(pair.second == 2){
                ans.push_back(pair.first);
            } 
            
            // std::cout << pair.first << "," << pair.second << std::endl;
        }

        for(const auto& pair: map){
            if(pair.second == 0){
                ans.push_back(pair.first);
            } 
            
            // std::cout << pair.first << "," << pair.second << std::endl;
        }

        return ans;
    }
};