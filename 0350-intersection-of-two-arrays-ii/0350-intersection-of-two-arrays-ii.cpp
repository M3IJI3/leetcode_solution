class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> result;
        // for(int i = 0 ; i < nums1.size() ; i++){
        //     for(int j = 0 ; j < nums2.size() ; j++){
        //         if(nums1[i] == nums2[j]){
        //             result.push_back(nums1[i]);
        //             nums2[j] = -1; // marked as used
        //             break;
        //         }
        //     }
        // }
        // return result;
        /////////////////////////////////////////////

        unordered_map<int, int> freq;
        vector<int> result;

        for(int num: nums1){
            freq[num]++;
        }

        for(int num : nums2){
            if(freq[num] > 0){
                result.push_back(num);
                freq[num]--;
            }
        }
        return result;
    }
};