class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> hashset;
        for(auto i: nums){
            if(hashset[i]) return true;
            hashset[i] = 1;
        }
        return false;
    }
};