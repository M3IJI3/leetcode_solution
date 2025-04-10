class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // types of candies
        unordered_set<int> types(candyType.begin(), candyType.end());

        // numbers of candies that alice can eat
        int target = candyType.size() / 2;

        if(types.size() >= target){
            return target;
        } 

        return types.size();
    }
};