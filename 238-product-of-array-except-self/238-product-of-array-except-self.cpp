class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct, suffixProduct, results;
        int res = 1;
        prefixProduct.push_back(res);
        for(auto i: nums){
            res *= i;
            prefixProduct.push_back(res);
        }
        res = 1;
        suffixProduct.push_back(res);
        for(int i=nums.size() - 1; i>=0; i--){
            res *= nums[i];
            suffixProduct.push_back(res);
        }
        for(int i=0; i<nums.size(); i++){
            int tmp = prefixProduct[i] * suffixProduct[nums.size() - i - 1];
            results.push_back(tmp);
        }
        return results;
    }
};