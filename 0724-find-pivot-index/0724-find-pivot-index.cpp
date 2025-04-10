class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot = 0;
        int left_sum = 0;
        int right_sum = 0;
        
        for(int i = 1 ; i < nums.size() ; i++){
            right_sum += nums[i];
        }

        while(pivot < nums.size()){
            if(left_sum != right_sum){
                // pivot++;
                // // cout << pivot << endl;
                // left_sum += nums[pivot - 1];
                // right_sum -= nums[pivot];

                left_sum += nums[pivot];
                pivot++;
                if(pivot < nums.size()){
                    right_sum -= nums[pivot];
                }
            } else {
                return pivot;
            }
        }
        return -1;
    }
};