bool canConstruct(char* ransomNote, char* magazine) {
    int count[26] = {0};

    // 统计 magazine 中每个字母的数量
    for(int i = 0 ; magazine[i] != '\0' ; i++){
        count[magazine[i] - 'a']++;
    }

    // 检查 randomNote 中每个字母是否足够
    for(int i = 0 ; ransomNote[i] != '\0' ; i++){
        if(--count[ransomNote[i] - 'a'] < 0){
            return false;
        }       
    }

    return true;
}