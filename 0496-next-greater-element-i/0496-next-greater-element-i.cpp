class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Monotonic Stack

        // define hashmap storing map between current number and next greater number
        unordered_map<int,int> next_greater;
        // define stack
        stack<int> stk;

        for(int num: nums2){
            while(!stk.empty() && num > stk.top()){
                next_greater[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        while(!stk.empty()){
            next_greater[stk.top()] = -1;
            stk.pop();
        }

        vector<int> ans(nums1.size());
        for(int i = 0; i < ans.size() ; i++){
            ans[i] = next_greater[nums1[i]];
        }

        return ans;
    }
};