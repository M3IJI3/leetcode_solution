class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // // types of candies
        // unordered_set<int> types(candyType.begin(), candyType.end());

        // // numbers of candies that alice can eat
        // int target = candyType.size() / 2;

        // if(types.size() >= target){
        //     return target;
        // } 

        // return types.size();
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        sort(candyType.begin(), candyType.end());
        stack<int> stk;
        stk.push(candyType[0]);
        int target = (candyType.size() / 2) - 1;

        for(int i = 1 ; i < candyType.size() ; i++){
            if(target > 0 && candyType[i] != stk.top()){
                stk.push(candyType[i]);
                target--;
            }
        }

        return stk.size();
    }
};