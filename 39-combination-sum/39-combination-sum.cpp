class Solution {
public:
  void dfs(vector<int> &candidates, int l, int sum, vector<vector<int>> &res, vector<int> &temp){    
    if(sum == 0){
      res.push_back(temp);
      return;
    }
    if(l >= candidates.size()) return;
    if(sum < 0) return;
    
    dfs(candidates, l+1, sum, res, temp);
    temp.push_back(candidates[l]);
    dfs(candidates, l, sum - candidates[l], res, temp);
    temp.pop_back();
  }
  
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    dfs(candidates, 0, target, res, temp);
    return res;
  }
};