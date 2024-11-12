class Solution {
    public int trap(int[] height) {
        // 1. 单调栈
        Stack<Integer> stack = new Stack<>();
        int water = 0;

        // 遍历数组
        for(int i = 0 ; i < height.length ; i++)
        {
            // 满足条件 形成凹槽 可以蓄水   
            while(!stack.isEmpty() && height[i] > height[stack.peek()])
            {
                // 弹出栈顶元素
                int top = stack.pop();

                // 栈为空 左边没有柱子 不可以蓄水
                if(stack.isEmpty()) break;

                // 计算当前位置能接的水
                int width = i - stack.peek() - 1; // 水平距离
                int boundedHeight = Math.min(height[i], height[stack.peek()]) - height[top];
                water += width * boundedHeight;
            }

            stack.push(i);
        }
        return water;

    }
}