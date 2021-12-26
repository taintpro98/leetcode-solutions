class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<nums.size()-2; i++){
            int j = i+1;
            int k = nums.size() - 1;
            while(j < k){
                int cur = nums[i] + nums[j] + nums[k];
                if(cur == target){
                    return target;
                } else if (cur < target){
                    j++;
                } else{
                    k--;
                }
                if(abs(cur - target) < abs(res - target)) res = cur;
            }
            
        }
        return res;
    }
};