class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1 || numRows >= s.length()) return s;
        
        // 为每一行创建数组
        List<StringBuilder> rows = new ArrayList<>();
        for(int i = 0; i < numRows ; i++)
        {
            rows.add(new StringBuilder());
        }

        int currentRow = 0;        // 当前行
        boolean goingDown = false; // 判断方向 (上或者下)

        for(char c: s.toCharArray())
        {
            rows.get(currentRow).append(c); // 把字符串放到当前行
            if(currentRow == 0 || currentRow == numRows - 1)
            {
                goingDown = !goingDown;     // 改变方向
            }
            currentRow += goingDown ? 1 : -1;
        }

        // 拼接所有行的内容
        StringBuilder result = new StringBuilder();
        for(StringBuilder row: rows)
        {
            result.append(row);
        }

        return result.toString();
    }
}