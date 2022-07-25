class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    if(amount == 0) return 0;
    map<int, int> dp;
    dp[0] = 0;
    queue<int> q;
    q.push(0);
    // sort(coins.begin(), coins.end());
    while(!q.empty()){
      int first = q.front(); q.pop();
      for(auto c: coins){
        if(!dp[first+c] && first + c <= amount){
          // if(first+c > amount) return -1;
          if(first+c == amount) return dp[first] + 1;
          q.push(first+c);
          dp[first + c] = dp[first] + 1;
        }
      }
    }    
    return -1;
  }
};