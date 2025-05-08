class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 快慢指针
        int slow = 0;
        for(int fast = 0 ;  fast < nums.size() ; fast++){
            if(nums[fast] != val){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};