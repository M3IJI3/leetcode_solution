class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0; 

        int i = 0;
        for(int j = 0 ; j < nums.length ; j++){
            if(nums[i] != nums[j]){
                k++;
                nums[k] = nums[j];
                i = j;
            }
        }
        return k+1;
    }
}