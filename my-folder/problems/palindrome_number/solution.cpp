class Solution {
public:
    vector<int> convert_numer2digits(int n){
        vector<int> res;
        while(n){
            int tmp;
            tmp = n%10;
            res.push_back(tmp);
            n/=10;
        }
        return res;
    }
    
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        vector<int> digits = convert_numer2digits(x);
        int n = digits.size();
        int t = n/2;
        for(int i=0; i<t; i++){
            if(digits[i] != digits[n-1-i]) return false; 
        }
        return true;
    }
};