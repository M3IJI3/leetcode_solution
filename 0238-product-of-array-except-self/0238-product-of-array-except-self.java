class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] answer = new int[nums.length];
        for(int i = 0 ; i < nums.length ; i++)
        {
            answer[i] = 1;
        }

        int left = 1;
        for(int i = 0 ; i < nums.length ; i++)
        {
            answer[i] *= left;
            left *= nums[i];
        }

        int right = 1;
        for(int i = nums.length - 1 ; i >= 0; i--)
        {
            answer[i] *= right;
            right *= nums[i];
        }

        return answer;
    }
}