class Solution {
public:
  int convert(string s){
    int res = 0;
    int base = 1;
    int n = s.length();
    for (int i=n-1; i>=0; i--){
      res += base * int(s[i] - '0');
      base *= 10;
    }
    return res;
  }
  
  int numDecodings(string s) {
    int n = s.length();
    if(n == 1) return convert(s) >= 1 && convert(s) <= 26;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = convert(s.substr(0,1)) >= 1 && convert(s.substr(0,1)) <= 26;
    for(int i = 2; i<n+1; i++){
      int c1 = convert(s.substr(i-1, 1));
      if(c1 >= 1 && c1 <= 26) dp[i] += dp[i-1];
      if(s[i-2] != '0'){
        int c2 = convert(s.substr(i-2, 2));
        if(c2 >= 1 && c2 <= 26) dp[i] += dp[i-2];
      }
    }
    return dp[n];
  }
};