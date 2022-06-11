class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool checking = true;
        string res = "";
        int i = 0;
        
        while(checking){
            char a;
            if(strs[0][i]) a = strs[0][i];
            else {
                checking = false;
                break;
            }
            
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i]) {
                    if(a != strs[j][i]){
                        checking = false;
                        break;
                    }
                } else {
                    checking = false;
                    break;
                }
                
            }
            if(checking) res += a;
            i++;
        }
        return res;
    }
};