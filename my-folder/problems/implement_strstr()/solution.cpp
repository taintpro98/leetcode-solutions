class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int n = haystack.length(), k = needle.length();
        for(int i=0; i<=n-k; i++){
            if(needle == haystack.substr(i, k)) return i;
        }
        return -1;
    }
};