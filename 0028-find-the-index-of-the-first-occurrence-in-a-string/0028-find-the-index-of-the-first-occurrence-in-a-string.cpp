class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.size();
        
        string curr;
        int left = 0;
        for(int right = 0 ; right < haystack.size() ; right++){
            curr += haystack[right];
            
            while(right - left + 1 > len){
                curr.erase(0, 1);
                left++;
            }

            if(curr == needle) return left;
        }

        return -1;
    }
};