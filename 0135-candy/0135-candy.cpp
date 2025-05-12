class Solution {
public:
    // 从左到右、从右到左各遍历一遍，分别满足两个方向的局部约束，然后取最大值：
    // 从左到右：如果右边孩子评分更高 → 分的糖果要更多；
    // 从右到左：如果左边孩子评分更高 → 也要更多。
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // 从左到右遍历
        for(int i = 1 ; i < n ; i++){
            if(ratings[i] > ratings[i - 1]){
                candies[i] = candies[i - 1] + 1;
            }
        }

        // 从右到左遍历
        for(int i = n - 2 ; i >= 0 ; i--){
            if(ratings[i] > ratings[i + 1]){
                // 如果糖果已经比右边的多 就不用再给糖果了
                // 否则就是右边糖果 +1;
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};