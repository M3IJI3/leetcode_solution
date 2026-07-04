class Solution {
    int ans = -1;
public:
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        dfs(cookbooks, materials, attribute, limit, 0, 0, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& cookbooks, vector<int>& materials, vector<vector<int>>& attribute, int limit, int delicious, int hunger, int index){
        if(hunger >= limit){
            ans = max(ans, delicious);
        }

        if(index == cookbooks.size()) return;

        dfs(cookbooks, materials, attribute, limit, delicious, hunger, index + 1);

        if(canCook(materials, cookbooks[index])){
            for(int i = 0 ; i < materials.size() ; i++){
                materials[i] -= cookbooks[index][i];
            }   
            dfs(cookbooks, materials, attribute, limit, delicious + attribute[index][0], hunger + attribute[index][1], index + 1);
            for(int i = 0 ; i < materials.size() ; i++){
                materials[i] += cookbooks[index][i];
            }
        }
    }

    bool canCook(const vector<int>& materials, vector<int>& cookbook){
        for(int i = 0 ; i < materials.size() ; i++){
            if(materials[i] < cookbook[i]) return false;
        }
        return true;
    }
};