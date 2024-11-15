public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        
        // 1. 排序数组
        Arrays.sort(nums);
        
        // 2. 遍历数组，固定一个元素 nums[i]
        for (int i = 0; i < nums.length - 2; i++) {
            // 去重：跳过重复的元素
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;  // 左指针
            int right = nums.length - 1;  // 右指针
            
            // 3. 双指针法查找和为 0 的三元组
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // 找到一个三元组
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    
                    // 去重：跳过重复的 left 和 right 元素
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // 移动指针
                    left++;
                    right--;
                } else if (sum < 0) {
                    // 如果和小于 0，左指针右移
                    left++;
                } else {
                    // 如果和大于 0，右指针左移
                    right--;
                }
            }
        }
        
        return result;
    }
}
