class Solution {
public:
    void DFSUtil(pair<int, int> s, vector<vector<bool>> &visited, int &res, vector<vector<char>>grid){
        stack<pair<int, int>> st;
        st.push(s);
        int m = visited.size();
        int n = visited[0].size();
        
        visited[s.first][s.second] = true;
        
        while(!st.empty()){
            pair<int, int> s = st.top(); st.pop();
            int p = s.first;
            int q = s.second;
            
            vector<int> a = {-1, 1};
            for(auto i: a){
                if(p + i < m && p + i > -1){
                    if(grid[p+i][q] == '1' && !visited[p + i][q]){
                        visited[p+i][q] = true;
                        st.push({p+i, q});
                    }
                }
            }
            for(auto j: a){
                if(q + j < n && q + j > -1){
                    if(grid[p][q+j] == '1' && !visited[p][q+j]){
                        visited[p][q+j] = true;
                        st.push({p, q+j});
                    }
                }
            }
        }
        res++;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j] == '1' && !visited[i][j]) DFSUtil({i, j}, visited, res, grid);
            }
        }
        return res;
    }
};