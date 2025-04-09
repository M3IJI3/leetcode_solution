class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // TLE
        // int start = 0;
        // double sum = 0.0;
        // double max_avg = -DBL_MAX;

        // while(start <= nums.size() - k){
        //     for(int i = start ; i < start + k ; i++){
        //         sum += nums[i];
        //     }
        //     max_avg = max(max_avg, sum / k);
        //     start++;
        //     sum = 0;
        // }

        // return max_avg;
        // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

        double sum = 0;
        for(int i = 0 ; i < k ; i++){
            sum += nums[i];
        }

        double max_avg = sum;
        for(int i = k ; i < nums.size() ; i++){
            sum = sum - nums[i - k] + nums[i];
            max_avg = max(max_avg, sum);
        }
        
        return max_avg / k;
    }
};