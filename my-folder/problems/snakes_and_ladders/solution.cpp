class Solution {
public:
    pair<int, int> mapInt2Pair(int x, int n){
        int p = (x-1)/n;
        int r = (x-1)%n;
        int a, b;
        a = n - 1 - p;
        if(p%2 == 0){
            b = r;
        } else {
            b = n-1-r;
        }
        return {a, b};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int num = n*n;
        int res = 0;
        
        queue<pair<int, int>> q;
        vector<bool> visited(num+1, false);
        visited[1] = true;
        q.push({1, 0});
        
        while(!q.empty()){
            pair<int, int> node = q.front(); q.pop();
            int cur = node.first;
            int moves = node.second;
            for(int i=cur+1; i<=min(cur+6, num); i++){
                int next = i;
                pair<int, int> coor = mapInt2Pair(i, n);
                int tmp = board[coor.first][coor.second];
                if(tmp != -1) next = tmp;
                if(next == num) return moves+1;
                // cout << next << endl;
                if(!visited[next]){          
                    visited[next] = true;
                    q.push({next, moves+1});
                }
                
            }
        }
        return -1;
    }
};