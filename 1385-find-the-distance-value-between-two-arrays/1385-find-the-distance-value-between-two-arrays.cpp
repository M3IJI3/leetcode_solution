class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for(int i = 0 ; i < arr1.size() ; i++){
            bool flag = true;
            for(int j = 0 ; j < arr2.size() ; j++){     
                int distance = abs(arr1[i] - arr2[j]);
                if(distance <= d) {
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};