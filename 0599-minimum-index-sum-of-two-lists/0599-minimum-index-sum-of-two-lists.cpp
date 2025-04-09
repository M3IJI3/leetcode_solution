class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;

        for(int i = 0 ; i < list1.size() ; i++){
            for(int j = 0 ; j < list2.size() ; j++){
                if(list1[i] == list2[j]){
                    map[list1[i]] = i + j;
                }
            }
        }

        vector<string> ans;
        int min_value = INT_MAX;
        string s = "";
        for(const auto& pair : map){
            if(pair.second <= min_value){
                min_value = pair.second;
                s = pair.first;
            }
        }

        for(const auto& pair : map){
            if(pair.second == min_value){
                ans.push_back(pair.first);
            }
        }
        
        return ans;
    }
};