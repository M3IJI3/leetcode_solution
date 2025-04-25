class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        // 1. 合并相邻的相同元素
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = 2 * nums[i];
                nums[i + 1] = 0;
            }
        }

        // 2. 移动非零元素到前面
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                nums[index++] = nums[i];
        }

        // 3. 剩下的位置填充0
        for (int i = index; i < nums.size(); i++) {
            nums[i] = 0;
        }

        return nums;
    }
};