class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 快慢指针
        int slow = 0;
        for(int fast = 0 ; fast < nums.size() ; fast++){
            if(nums[fast] != val){
                nums[slow++] = nums[fast];
            }
            cout << slow << ", " << fast << endl;
        }
        return slow;
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        // int left = 0 ;
        // int right = nums.size() - 1;

        // while(left <= right){
        //     if(nums[left] == val){
        //         nums[left] = nums[right];
        //         right--;
        //     } else {
        //         left++;
        //     }
        // }
        // return left;
    }
};