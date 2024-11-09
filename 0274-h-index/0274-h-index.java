class Solution {
    public int hIndex(int[] citations) {
        // 满足至少h篇论文被引用的次数不少于h次
        
        int n = citations.length;
        Arrays.sort(citations);

        for(int i = 0 ; i < n ; i++)
        {
            if(citations[i] >= n - i)
            {
                return n - i;
            }
        }
        return 0;
    }
}