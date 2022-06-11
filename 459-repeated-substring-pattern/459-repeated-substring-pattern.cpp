class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int checkLength = s.length() / 2;
        for(int i=1; i<=checkLength; i++){
            if(s.length() % i == 0){
                string root = s.substr(0, i);
                int checkIndex = i;
                while(checkIndex < s.length() && s.substr(checkIndex, i) == root) checkIndex += i;
                if(checkIndex >= s.length()) return true;
            }
        }
        return false;
    }
};