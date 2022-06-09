class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, count = 1;
        for(int j=1; j<nums.size(); j++){
            if(nums[j] > nums[i]){
                swap(nums[i+1], nums[j]);
                i++;
                count++;
            }
        }
        return count;
    }
};