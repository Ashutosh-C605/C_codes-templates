class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int m = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);    
        }
        vector<int> indeg(numCourses);
        for(int i=0; i<numCourses; i++)
        {
            for(auto it: adj[i])
                indeg[it]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(indeg[i] ==0)
                q.push(i);
        }
        int cnt = 0;            
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node])
            {
                indeg[it]--;
                if(indeg[it] ==0)   q.push(it);
            }
        }
        if(cnt == numCourses)    return true;
        else return false;  
    }
};