class Solution {
    public int maxTurbulenceSize(int[] arr) {
        if (arr.length == 1) return 1; // 特殊情况，只有一个元素

        int maxLen = 1; // 最大湍流子数组长度
        int left = 0;   // 滑动窗口左边界

        for (int right = 1; right < arr.length; right++) {
            int compare = Integer.compare(arr[right - 1], arr[right]); // 比较相邻元素

            if (compare == 0) { // 如果相邻元素相等
                left = right; // 重置窗口
            } else if (right == 1 || 
                       (Integer.compare(arr[right - 2], arr[right - 1]) * compare != -1)) {
                // 如果湍流关系中断
                left = right - 1; // 重置窗口起点
            }

            // 更新最大长度
            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }
}
