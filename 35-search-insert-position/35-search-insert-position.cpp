class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1){
            if(target > nums[0]) return n;
            else return 0;
        }
        int l = 0, r = n-1;
        while(l < r){
            if(r - l == 1) {
                if(target > nums[r]) return n;
                else if (target <= nums[l]) return 0;
                else return r;
            }
            int pivot = (l+r)/2;
            if(nums[pivot] == target) {
                return pivot;
            }
            else if(nums[pivot] < target) l = pivot;
            else r = pivot;
        }
        return 0;
    }
};