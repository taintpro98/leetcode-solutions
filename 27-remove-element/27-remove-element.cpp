class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = nums.size(), j = nums.size() - 1, i=0;       
        while(i<=j){
            while(j>i && nums[j] == val){
                j--;
                count--;
            }
            if(nums[i] == val){
                swap(nums[i], nums[j]);
                count--;
                j--;
            }
            i++;
        }
        return count;
    }
};