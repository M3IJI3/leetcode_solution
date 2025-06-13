// 用整数会丢失小数的位数 从而导致查询失败
// class Solution {
// public:
//     bool judgePoint24(vector<int>& cards) {
//         int n = cards.size();
//         if(n == 1) return cards[0] == 24;

//         for(int i = 0 ; i < n ; i++){
//             for(int j = i + 1 ; j < n ; j++){
//                 int a = cards[i], b = cards[j];

//                 vector<int> nextCards;
//                 for(int k = 0 ; k < n ; k++){
//                     if(k != i && k != j){
//                         nextCards.push_back(cards[k]);
//                     }
//                 }

//                 vector<int> candidates = {
//                     a + b,
//                     a - b,
//                     b - a,
//                     a * b
//                 };
//                 if(a != 0 && b != 0){
//                     candidates.push_back(a / b);
//                     candidates.push_back(b / a);
//                 } else {
//                     candidates.push_back(0);
//                 }

//                 for(int z : candidates){
//                     nextCards.push_back(z);
//                     if(judgePoint24(nextCards)) return true;
//                     nextCards.pop_back();
//                 }
//             }
//         }
//         return false;
//     }
// };
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
class Solution {
    const double TARGET = 24.0;
    const double EPS    = 1e-6;
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        bool res = dfs(nums);
        return res;
    }

    bool dfs(vector<double>& nums){
        int n = nums.size();
        if(n == 1) return fabs(nums[0] - TARGET) < EPS;

        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                double a = nums[i], b = nums[j];

                vector<double> nextNums;
                for(int k = 0 ; k < n ; k++){
                    if(k != i && k != j){
                        nextNums.push_back(nums[k]);
                    }
                }

                vector<double> candidates = {
                    a + b,
                    a - b,
                    b - a,
                    a * b
                };
                if(fabs(b) > EPS) candidates.push_back(a / b);
                if(fabs(a) > EPS) candidates.push_back(b / a); 

                for(double z : candidates){
                    nextNums.push_back(z);
                    if(dfs(nextNums)) return true;
                    nextNums.pop_back();
                }
            }
        }
        return false;
    }
};