class Solution {
public:
    bool isBalanced(string num) {
        int evenSum = 0, oddSum = 0;
        int i = 0;

        while(i < num.size()){
            if(i % 2 != 0){
                oddSum += num[i] - '0';
            } else {
                evenSum += num[i] - '0';
            }
            i++;
        }
        return evenSum == oddSum;
    }
};