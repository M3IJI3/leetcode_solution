class Solution {
    public int[] productExceptSelf(int[] nums) {
        // 初始化一个全为1的数组
        int[] answer = new int[nums.length];
        Arrays.fill(answer, 1);

        // 先把每个元素左边的乘积得出并存储
        int left = 1;
        for(int i = 0 ; i < nums.length ; i++)
        {
            answer[i] *= left;
            left *= nums[i];
        }

        // 再把每个元素右边的乘积得出并存储
        int right = 1;
        for(int i = nums.length - 1 ; i >= 0 ; i--)
        {
            answer[i] *= right;
            right *= nums[i];
        }

        return answer;
    }
}