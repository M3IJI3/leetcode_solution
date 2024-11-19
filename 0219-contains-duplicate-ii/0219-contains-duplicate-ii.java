class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        
        for(int i = 0; i < nums.length ; i++)
        {
            if(map.containsKey(nums[i]) && i - map.get(nums[i]) <= k)
            {
                return true;
            }
            map.put(nums[i], i); // map.put(); 也可以更新拥有相同 key 的值
        }
        return false;
    }
}