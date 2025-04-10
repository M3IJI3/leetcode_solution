class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // if(bits[bits.size() - 2] == 0) return true;

        int index = 0;

        while(index < bits.size() - 1){
            if(bits[index] == 1){
                index += 2;
            }else{
                index++;
            }
        }

        return index == bits.size() - 1;
    }
};