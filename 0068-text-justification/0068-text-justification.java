class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        List<String> temp = new ArrayList<>();
        int lineLength = 0;

        for(String word : words)
        {
            // 检查每行的字符数是否超过最大宽度
            // temp.size() 为每行空格数量
            if(lineLength + temp.size() + word.length() > maxWidth)
            {
                res.add(justifySpaces(temp, lineLength, maxWidth));
                temp.clear();
                lineLength = 0;
            }

            temp.add(word);
            lineLength += word.length();
        }

        // Handle the last line (left-justified)
        StringBuilder lastLine = new StringBuilder(String.join(" ", temp));
        while (lastLine.length() < maxWidth) {
            lastLine.append(" ");
        }
        res.add(lastLine.toString());

        return res;

    }

    private String justifySpaces(List<String> line, int lineLength, int maxWidth)
    {
        int spacesToDistribute = maxWidth - lineLength; // 计算出还剩多少个空格可以分配
        int gaps = line.size() - 1;                     // 计算出"缺口"的数量

        // 如果这一行只有一个word
        if(gaps == 0)
        {
            StringBuilder sb = new StringBuilder(line.get(0));
            while(sb.length() < maxWidth)
            {
                sb.append(" ");
            }
            return sb.toString();
        }

        int spacePerGap = spacesToDistribute / gaps;
        int extraSpaces = spacesToDistribute % gaps;

        StringBuilder justifiedLine = new StringBuilder();

        for(int i = 0 ; i < gaps ; i++)
        {
            justifiedLine.append(line.get(i));

            // 添加空格
            for(int j = 0 ; j < spacePerGap ; j++)
            {
                justifiedLine.append(" ");
            }

            if(extraSpaces > 0)
            {
                justifiedLine.append(" ");
                extraSpaces--;
            }
        }

        justifiedLine.append(line.get(gaps));
        return justifiedLine.toString();
    }
}