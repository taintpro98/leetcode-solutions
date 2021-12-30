class Solution {
public:
    vector<string> res;
    map<char, string> myDict;
    int n;
    string x;
    
    bool check(char v, int k){
        return true;
    } 
    
    void solution(){
        res.push_back(x);
    }
    
    
    void handle(int k, string digits){
        char digit = digits[k];
        for(auto c: myDict[digit]){
            if(check(c, k)){
                x[k] = c;
                if(k == n-1) solution();
                else handle(k+1, digits);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        x.resize(n); 
        
        myDict.insert({'2', "abc"});
        myDict.insert({'3', "def"});
        myDict.insert({'4', "ghi"});
        myDict.insert({'5', "jkl"});
        myDict.insert({'6', "mno"});
        myDict.insert({'7', "pqrs"});
        myDict.insert({'8', "tuv"});
        myDict.insert({'9', "wxyz"});
        
        handle(0, digits);
        return res;
    }
};