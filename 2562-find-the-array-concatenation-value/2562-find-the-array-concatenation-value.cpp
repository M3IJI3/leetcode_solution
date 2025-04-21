class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;

        int head = 0, tail = nums.size() - 1;
        int concat;
        while(head <= tail){
            if(head != tail){
                concat = stoi(to_string(nums[head]) + to_string(nums[tail]));
            } else {
                concat = nums[head];
            }
            
            ans += concat;

            head++;
            tail--;
        }
        return ans; 
    }
};