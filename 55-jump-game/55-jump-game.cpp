class Solution {
public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int target = n - 1;
    vector<int> dp(n, false);
    dp[n-1] = true;
    for(int i = nums.size() - 2; i>=0; i--){
      if(target - i <= nums[i]){
        dp[i] = dp[target];
        target = i;
      }
    }
    return dp[0];
  }
};