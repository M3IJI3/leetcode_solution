class Solution {
public:
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        int n = cookbooks.size();
        int ans = -1;
        for(int mask = 0 ; mask < (1 << n) ; mask++){
            int delicious = 0, hunger = 0;
            vector<int> remaining = materials;
            // bool valid = true;

            for(int i = 0 ; i < n ; i++){
                if(mask & (1 << i)){
                    if(canCook(remaining, cookbooks[i])){
                        for(int j = 0 ; j < remaining.size() ; j++){
                            remaining[j] -= cookbooks[i][j];
                        }
                        delicious += attribute[i][0];
                        hunger += attribute[i][1];
                    } 
                    // else {
                        // valid = false;
                        // break;
                    // }
                }
            }
            if(hunger >= limit) ans = max(ans, delicious);
        }
        return ans;
    }

    bool canCook(vector<int>& materials, vector<int>& cookbook){
        for(int i = 0 ; i < materials.size() ; i++){
            if(materials[i] < cookbook[i]) return false;
        }
        return true;
    }
};