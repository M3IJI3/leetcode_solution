bool isIsomorphic(char* s, char* t) {
    int map_s[256] = {0};
    int map_t[256] = {0};

    for(int i = 0 ; s[i] != '\0' ; i++){
        unsigned char cs = s[i];
        unsigned char ct = t[i];

        if(map_s[cs] != map_t[ct]) return false;

        map_s[cs] = i + 1;
        map_t[ct] = i + 1;
    }

    return true;
}