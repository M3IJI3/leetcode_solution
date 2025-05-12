class Solution {
public:
    string reorderSpaces(string text) {
        int spaceCount = 0;
        for(int i = 0 ; i < text.size() ; i++){
            if(isspace(text[i])) spaceCount++;
        }

        vector<string> words;
        istringstream iss(text);
        string word;
        
        while(iss >> word){
            words.push_back(word);
        }
        
        int n = words.size();
        string result;
        if(n <= 1){
            return words[0] + string(spaceCount, ' ');
        } else {
            int gap = n - 1;
            int spacesPerGap = spaceCount / gap;
            int extraSpaces = spaceCount % gap;

            for(int k = 0 ; k < n - 1 ; k++){
                result += words[k] + string(spacesPerGap, ' ');
            }
            result += words[n - 1] + string(extraSpaces, ' ');
        }

        return result;
    }
};