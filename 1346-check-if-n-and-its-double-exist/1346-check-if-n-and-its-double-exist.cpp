class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int index = 0;

        while(index < arr.size()){
            int temp = arr[index] * 2;

            // 左半边区间 0 ~ index
            for(int i = 0 ; i < index ; i++){
                if(temp == arr[i]) return true;
            }

            // 右半边区间 index ~ arr.size()
            for(int i = index + 1 ; i < arr.size() ; i++){
                if(temp == arr[i]) return true;
            }

            index++;
        }
        return false;
    }
};