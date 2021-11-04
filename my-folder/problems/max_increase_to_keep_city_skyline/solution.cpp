class Solution {
public:
    int max(int a, int b){
        return a > b ? a : b;
    }
    
    int min(int a, int b){
        return a < b ? a : b;
    }
    
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxRow[51] = {0};
        int maxCol[51] = {0};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                maxCol[j] = max(grid[i][j], maxCol[j]);
                maxRow[i] = max(maxRow[i], grid[i][j]);
            }
        }
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                int tmp = min(maxRow[i], maxCol[j]) - grid[i][j];
                res += tmp;
            }
        }
        return res;
    }
};