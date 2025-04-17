class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;     // nums1 有效部分的末尾
        int j = n - 1;     // nums2 末尾
        int k = m + n - 1; // nums1 最终末尾

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};