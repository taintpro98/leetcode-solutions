class Solution {
public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int maxValue = 0;
    while(l < r){
      if(height[l] <= height[r]){
        maxValue = max(maxValue, height[l] * (r-l));
        l++;
      } else {
        maxValue = max(maxValue, height[r] * (r-l));
        r--;
      }
    }
    return maxValue;
  }
};