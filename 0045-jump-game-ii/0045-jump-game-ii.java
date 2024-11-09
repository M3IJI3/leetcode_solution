class Solution {
    public int jump(int[] nums) {
        int near = 0; // 表示靠近跳跃位置的第一个点
        int far  = 0; // 表示能跳到的最远位置
        int jump = 0; // 跳跃次数

        while(far < nums.length - 1) // 条件满足跳跃的最远位置不会超过数组长度
        {
            int maxDistance = 0;
            for(int i = near ; i <= far ; i++) // 遍历能跳到的所有点
            {
                // 保存能跳到的最远位置
                maxDistance = Math.max(maxDistance, i + nums[i]);
            }
            
            near = far + 1;    // 更新起点
            far = maxDistance; // 更新能跳到的最远位置
            jump++;
        }
        return jump;
    }
}