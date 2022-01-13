class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int cycle = 2*numRows - 2;
        vector<string> ql; 
        for(int i=0; i<numRows; i++) ql.push_back("");
        int nCycle = s.length() / cycle + 1;

        for(int t=0; t<s.length(); t++){
            int i = t/cycle;
            int j = t%cycle;
            if(j<numRows){
                ql[j].push_back(s[t]);
            } else{
                ql[cycle-j].push_back(s[t]);
            }
        }
        string res = "";
        for(auto x: ql) res += x;
        return res;
    }
};