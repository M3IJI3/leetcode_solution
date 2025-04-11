class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxNum = INT_MIN;
        int maxNumIndex = 0;

        for(int num: nums){
            maxNum = max(maxNum, num);
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != 0 && nums[i] != maxNum){
                double res = maxNum / nums[i];
                cout << res << endl;
                if(res < 2){
                    return -1;
                }
            }

            if(nums[i] == maxNum){
                maxNumIndex = i;
            }
        }

        return maxNumIndex;
    }
};