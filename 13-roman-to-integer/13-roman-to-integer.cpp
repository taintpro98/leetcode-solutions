class Solution {
public:
    int special(string s){
        if(s == "IV") return 4;
        else if(s == "IX") return 9;
        else if(s == "XL") return 40;
        else if(s == "XC") return 90;
        else if(s == "CD") return 400;
        else if(s == "CM") return 900;
        return 0;
    }
    
    int romanToInt(string s) {
        map<char, int> dict;
        dict.insert(pair<char, int>('I', 1));
        dict.insert(pair<char, int>('V', 5));
        dict.insert(pair<char, int>('X', 10));
        dict.insert(pair<char, int>('L', 50));
        dict.insert(pair<char, int>('C', 100));
        dict.insert(pair<char, int>('D', 500));
        dict.insert(pair<char, int>('M', 1000));
        
        int res = 0;
        int i=0;
        while(i<s.length()){
            if(dict[s[i]] >= dict[s[i+1]]){
                res += dict[s[i]];
                i++;
            } else {
                res += special(s.substr(i, 2));
                i+=2;
            }
        }
        if(i == s.length()) res += dict[s[i]]; 
        return res; 
    }
};