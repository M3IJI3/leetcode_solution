class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[] rows = new int[9];
        int[] cols = new int[9];
        int[] boxs = new int[9];

        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '1'; // convert 1-9 to 0-8
                int mask = 1 << num;         // create bitmask for the number
                int boxIndex = (i / 3) * 3 + j / 3;

                if((rows[i] & mask) != 0 || (cols[j] & mask) != 0 || (boxs[boxIndex] & mask) != 0)
                {
                    return false;
                }

                // 按位或运算 赋值给左边 只要有一个1 结果为1
                rows[i] |= mask;
                cols[j] |= mask;
                boxs[boxIndex] |= mask;
            }
        }
        return true;
    }
}