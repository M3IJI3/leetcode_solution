class Solution {
    public int trap(int[] height) {
        // 1. 单调栈
        // Stack<Integer> stack = new Stack<>();
        // int water = 0;

        // // 遍历数组
        // for(int i = 0 ; i < height.length ; i++)
        // {
        //     // 满足条件 形成凹槽 可以蓄水   
        //     while(!stack.isEmpty() && height[i] > height[stack.peek()])
        //     {
        //         // 弹出栈顶元素
        //         int top = stack.pop();

        //         // 栈为空 左边没有柱子 不可以蓄水
        //         if(stack.isEmpty()) break;

        //         // 计算当前位置能接的水
        //         int width = i - stack.peek() - 1; // 水平距离
        //         int boundedHeight = Math.min(height[i], height[stack.peek()]) - height[top];
        //         water += width * boundedHeight;
        //     }

        //     stack.push(i);
        // }
        // return water;

        // ----------------------------------------------------------

        // 2. 双指针
        int left = 0, right = height.length - 1;
        int leftMax = 0, rightMax = 0; // 定义左右边界的最大高度
        int water = 0;

        while(left < right)
        {
            if(height[left] < height[right])
            {
                if(height[left] > leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    water += leftMax - height[left];
                }
                left++;
            }
            else
            {
                if(height[right] > rightMax)
                {
                    rightMax = height[right];
                }
                else
                {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        return water;
    }
}