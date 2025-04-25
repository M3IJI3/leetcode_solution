class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();

        int even = 0, odd = 1;
        while(odd < n){
            cout << "(" << even << "," << odd << ")" << endl;
            if(nums[odd] % 2 == 0){
                if(nums[even] % 2 != 0) {
                    // swap(nums[odd], nums[even]);
                    int temp = nums[odd];
                    nums[odd] = nums[even];
                    nums[even] = temp;
                    
                    odd += 2;
                    even += 2;
                } else {
                    even += 2;
                }
            } else {
                odd += 2;
            }
        }
        return nums;
    }
// private:
//     void swap(int i, int j){
//         int temp = i;
//         i = j;
//         j = temp;
//     }
};