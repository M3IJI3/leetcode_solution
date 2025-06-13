class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // convert sentence to words in vector
        vector<string> words;
        {  
            string word;
            istringstream iss(sentence);
            while(iss >> word) words.push_back(word);
        }

        sort(dictionary.begin(), dictionary.end()); // 排序保证先找最短的root

        vector<pair<string, string>> mapper;
        for(int w_idx = 0 ; w_idx < words.size() ; w_idx++){
            bool found = false;  // 检测有没有找到 root
            string word = words[w_idx];
            for(int d_idx = 0 ; d_idx < dictionary.size() ; d_idx++){
                string root = dictionary[d_idx];
                if(word.rfind(root, 0) == 0){
                    mapper.push_back({word, root});
                    found = true;
                    break;
                }
            }
            if(!found) mapper.push_back({word, word});
        }

        string ans;
        for(int i = 0 ; i < mapper.size() - 1 ; i++){
            ans += mapper[i].second + " ";
        } 
        ans += mapper[mapper.size() - 1].second;
        return ans;
    }
};