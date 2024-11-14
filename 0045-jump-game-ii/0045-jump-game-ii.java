class Solution {
    public int jump(int[] nums) {
        int jump = 0;
        int near = 0;
        int far = 0;

        while (far < nums.length - 1) {
            int maxDistance = 0;
            for (int i = near; i <= far; i++) {
                maxDistance = Math.max(maxDistance, i + nums[i]);
            }

            near = far + 1;
            far = maxDistance;
            jump++;
        }

        return jump;
    }
}