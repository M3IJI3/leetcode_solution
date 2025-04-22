class Solution {
public:
    bool isHappy(int n) { 
        unordered_set<int> seen;

        while(n != 1){
            if(seen.count(n)) return false;
            seen.insert(n);
            n = getSumofDigitsSquare(n);
        }
        
        return true;
    }

    int getSumofDigitsSquare(int num){
        int remainder = 0;
        int sum = 0;

        while(num > 0){
            remainder = num % 10;
            num /= 10;
            sum += remainder * remainder;
        }

        return sum;
    }
};