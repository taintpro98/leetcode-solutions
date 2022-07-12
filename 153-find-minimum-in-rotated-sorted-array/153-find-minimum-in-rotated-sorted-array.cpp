class Solution {
public:
  int check(vector<int>& nums, int h){
    if(h == 0 || nums[h] < nums[h-1]) return 0;
    if(nums[h] < nums[0]){
      return 1;
    } else {
      return -1;
    } 
  }
    
  int findMin(vector<int>& nums) {
    int n = nums.size();
    if(n == 1 || nums[0] < nums[n-1]) return nums[0];
    if(n == 2) return nums[1];
    if(nums[n-1] < nums[n-2]) return nums[n-1];
    int l = 0, r = n-1;
    int h = (l+r)/2;
    int pivot = check(nums, h);
    while(pivot != 0){
      if(pivot == -1){
        l = h;
      } else {
        r = h;
      }
      h = (l+r)/2;
      pivot = check(nums, h);
    }
    return nums[h];
  }
};