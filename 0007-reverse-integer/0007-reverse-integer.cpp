class Solution {
public:
    int reverse(int x) {
        // int num = 0;

        // if(x < 0){
        //     num = -x;
        //     int reversed_num = getReverseNumber(num);
        //     return -reversed_num;
        // } else if(x > 0) {
        //     return getReverseNumber(x);
        // }

        // return 0;
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
        int ans = 0;

        while(x != 0){
            int digit = x % 10;

            if(ans > INT_MAX / 10 || ans < INT_MIN / 10){
                return 0;
            }

            ans = ans * 10 + digit;
            x /= 10;
        }
        return ans;
    }
};

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// private:
//     int getReverseNumber(int num){
//         int remainder = 0;
//         string s = "";

//         while(num > 0){
//             remainder = num % 10;
//             num /= 10;
//             s += to_string(remainder);
//         }

//         int ans = stoi(s);
//         return ans;
//     }
