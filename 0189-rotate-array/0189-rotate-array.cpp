class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());
        reverse(rev.begin(), rev.begin() + k);
        reverse(rev.begin() + k, rev.end());
        nums = rev;
    }
};