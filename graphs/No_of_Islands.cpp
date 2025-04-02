class Solution {
    private:
        void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis)
        {
            queue<pair<int,int>> q;
            vis[row][col] = 1;
            q.push({row,col});
            int n = grid.size();
            int m = grid[0].size();
            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
            while(!q.empty())
            {
                row = q.front().first;
                col = q.front().second;
                q.pop();
       
               for(auto [dr, dc] : directions)      //traverse all directions 
                {
                    int nrow = row + dr;
                    int ncol = col + dc;
                    if((nrow >=0 && nrow<n) && (ncol >= 0 && ncol<m) 
                        && (!vis[nrow][ncol]) && (grid[nrow][ncol]=='1'))
                    {
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                        
                }
            }
    
        }
    public:
        int numIslands(vector<vector<char>>& grid) 
        {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> vis(n, vector<int>(m,0));  //visited map for checking visited nodes
    
            int count = 0;
            for(int row=0; row<n; row++)
            {
                for(int col=0; col<m; col++)
                {
                    if(!vis[row][col] && grid[row][col] == '1')
                    {
                        count++;                        //no of new starts = islands
                        bfs(row, col, grid, vis);
                    }
                }
            }
           return count;     
        }
    };
    