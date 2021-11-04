class Solution {
public:
    int INF = 1e9;
    
    int PL(int l, int r, vector<int> &nums){
        int rs = -INF;
        int s = 0;
        for(int i=r; i>=l; i--){
            s += nums[i];
            rs = max(rs, s);
        }
        return rs;
    }
    
    int PR(int l, int r, vector<int> &nums){
        int rs = -INF;
        int s = 0;
        for(int i=l; i<=r; i++){
            s += nums[i];
            rs = max(rs, s);
        }
        return rs;
    }
    
    int P(int l, int r, vector<int> &nums){
        if(l == r) return nums[r];
        int m = (l+r)/2;
        return max(max(P(l,m, nums), P(m+1, r, nums)), PL(l, m, nums) + PR(m+1, r, nums));
    }
    
    int maxSubArray(vector<int>& nums) {
        return P(0, nums.size() - 1, nums);
    }
};