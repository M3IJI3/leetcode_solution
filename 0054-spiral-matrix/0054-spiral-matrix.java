class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();  // 存储结果的列表

        // 定义矩阵的四个边界
        int top = 0, bottom = matrix.length - 1;
        int left = 0, right = matrix[0].length - 1;

        // 只要上边界小于等于下边界，左边界小于等于右边界，就继续遍历
        while (top <= bottom && left <= right) {
            // 1. 遍历 top 行，从左到右
            for (int j = left; j <= right; j++) {
                result.add(matrix[top][j]);
            }
            top++;  // 遍历完 top 行后，top 边界向下移动一行

            // 2. 遍历 right 列，从上到下
            for (int i = top; i <= bottom; i++) {
                result.add(matrix[i][right]);
            }
            right--;  // 遍历完 right 列后，right 边界向左移动一列

            // 3. 遍历 bottom 行（如果有效，即 top <= bottom）
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.add(matrix[bottom][j]);
                }
                bottom--;  // 遍历完 bottom 行后，bottom 边界向上移动一行
            }

            // 4. 遍历 left 列（如果有效，即 left <= right）
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.add(matrix[i][left]);
                }
                left++;  // 遍历完 left 列后，left 边界向右移动一列
            }
        }

        return result;  // 返回结果列表
    }
}
