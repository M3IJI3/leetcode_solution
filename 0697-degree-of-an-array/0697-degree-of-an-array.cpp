class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int max_freq = 0;

        // record frequence of numbers appeared
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
            // find the maximum freq number
            max_freq = max(max_freq, freq[num]);
        }

        int left = 0;
        int right = 0;
        int min_len = INT_MAX;

        for(const auto& pair: freq){
            if(pair.second == max_freq){
                for(int i = 0 ; i < nums.size() ; i++){
                    if(nums[i] == pair.first){
                        left = i;
                        break;
                    }
                }

                for(int j = nums.size() - 1 ; j >= 0 ; j--){
                    if(nums[j] == pair.first){
                        right = j;
                        break;
                    }
                }

                min_len = min(min_len, right - left + 1);
            }
        }
        return min_len; 
    }      
};