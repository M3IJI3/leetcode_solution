class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int num : nums) freq[num]++;

        int countMax = 0;
        for(auto& [num, count] : freq){
            countMax = max(countMax, count);
        }

        int n = nums.size();
        if(countMax <= n / 2){
            return n % 2;
        } else {
            return 2 * countMax - n;
        }
    }
};