class Solution {
public:
  int linearRob(vector<int>& nums, int l, int r){
    int a, b;
    a = nums[l];
    if(r - l == 0) return a;
    b = max(nums[l], nums[l+1]);
    if(r - l == 1) return b;
    
    for(int i = l+2; i<r+1; i++){
      int tmp = max(b, nums[i] + a);
      a = b; b = tmp;
    }
    return b;
  }
  
  int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);
    if(nums.size() == 3) return max(nums[2], max(nums[0], nums[1]));
    int resNoLast = linearRob(nums, 0, nums.size() - 2);
    int resLast = nums[nums.size() - 1] + linearRob(nums, 1, nums.size() - 3);
    return max(resNoLast, resLast);
  }
};