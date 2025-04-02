class Solution {
    public:
        void dfs(vector<vector<int>>& adjList, vector<int>& vis, int node)
        {
            vis[node] = 1;
            for(auto it: adjList[node])
            {
                if(!vis[it])
                    dfs(adjList, vis, it);
            }
        }
    
        int findCircleNum(vector<vector<int>>& isConnected) 
        {
            int n = isConnected.size();
            vector<vector<int>> adjList(n);
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(j != i && isConnected[i][j] == 1)
                    {
                        adjList[i].push_back(j);
                        adjList[j].push_back(i);
                    }                   
                }
            }
    
            vector<int> vis(n,0);
            int count = 0;
            for(int i=0; i<n; i++)
            {
                if(!vis[i])
                {
                    count++;
                    dfs(adjList, vis, i);
                }
            }
            return count;       
        }
    };