class Solution {
public:
  int rob(vector<int>& nums) {
    int a, b;
    a = nums[0];
    if(nums.size() == 1) return a;
    b = max(nums[0], nums[1]);
    if(nums.size() == 2) return b;
    
    for(int i = 2; i<nums.size(); i++){
      int tmp = max(b, nums[i] + a);
      a = b; b = tmp;
    }
    return b;
  }
};