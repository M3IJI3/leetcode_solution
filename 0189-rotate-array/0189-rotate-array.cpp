class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // k = k % nums.size();

        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());

        int n = nums.size();
        k %= n;
        int count = 0; // 记录被移动的元素个数

        for (int start = 0; count < n; ++start) {
            int current = start;
            int prev = nums[start];

            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current); // 回到起点表示这个环结束
        }
    }
};