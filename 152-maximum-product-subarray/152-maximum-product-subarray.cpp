class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = 1, currMin = 1, res = nums[0];
        for(auto n: nums){
            int tmp = n*currMax;
            currMax = max(n, max(n*currMax, n*currMin));
            currMin = min(n, min(tmp, n*currMin));
            res = max(res, currMax);
        }
        return res;
    }
};