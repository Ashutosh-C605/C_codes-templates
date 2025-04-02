#include<bits/stdc++.h>
//authored by ashu_astos
using namespace std;
typedef long long ll;
#define ff first
#define ss second
#define f(i,a,n,x) for(ll i = a; i < n; i += x)
#define fr(i,a,n,x) for(int i = a; i > n; i -= x)
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define all(v) v.begin(), v.end()
#define vii vector<vector<ll>>
#define vil vector<vector<int>>
#define pp pair<ll,ll>
#define ppl pair<ll,pair<ll,ll>>
#define vip vector<pair<ll,ll>>
#define mi map<int,int>
#define dl double
#define sorty(v) sort(v.begin(),v.end())
#define pb push_back
#define coe cout<<endl
const ll inf = LLONG_MAX;
const int MAXN = 1000005;
const ll mod = 1000000007ll;

// Global variables for Kosaraju's algorithm
stack<int> st;   // Stack for finishing times.
vi comp;         // comp[i] will hold the SCC id of vertex i.
int cnt = 0;     // Count of SCCs

// Standard DFS on original graph.
void dfs(int node, vi &vis, vii &adj) 
{
    vis[node] = 1;
    for(auto it: adj[node]) 
    {
        if(vis[it] == 0)
            dfs(it, vis, adj);
    }
    st.push(node);
}

// DFS on the transpose graph, assigning component no.
void dfs2(int node, vi &vis, vii &t_adj) 
{
    vis[node] = 1;
    comp[node] = cnt;
    for(auto it: t_adj[node]) 
    {
        if(vis[it] == 0)
            dfs2(it, vis, t_adj);
    }
}

int main() {
    ios::sync_with_stdio(false);  
    cin.tie(NULL);                
    int t = 1;
    // Uncomment below if there are multiple test cases.
    // cin >> t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        // Graphs: adj for original, t_adj for transpose (reversed edges).
        vii adj(n+1), t_adj(n+1);
        vi coins(n+1);
        
        // Read coins in each room (1-indexed).
        f(i, 1, n+1, 1) 
            cin>>coins[i];
    
        
        // Read tunnels (directed edges).
        f(i,0,m,1) 
        {
            int u, v;
            cin>>u>>v;
            adj[u].pb(v);
            t_adj[v].pb(u);
        }
        
        // First DFS pass to compute finishing order.
        vi vis(n+1, 0);
        f(i, 1, n+1, 1) 
        {
            if(vis[i]==0)
                dfs(i, vis, adj);
        }
        
        // Reset visited array for second DFS.
        fill(all(vis), 0);
        comp.resize(n+1);
        // Process nodes in order given by the stack.
        while(!st.empty()) 
        {
            int node = st.top();
            st.pop();
            if(vis[node] == 0) 
            {
                dfs2(node, vis, t_adj);
                cnt++;  // Increase component count after finishing one SCC.
            }   
        }
        
        // Compute the sum of coins for each SCC.
        vi sum(cnt, 0);
        f(i,1,n+1,1) 
        {
            sum[comp[i]] += coins[i];
        }
        
        // Build the condensed graph (DAG) for the components.
        // b[i] will hold all distinct SCCs reachable from component i.
        vector<unordered_set<int>> b(cnt);
        f(i,1,n+1,1) 
        {
            for(auto j: adj[i]) 
            {
                if(comp[i] != comp[j])
                    b[comp[i]].insert(comp[j]);
            }
        }
        
        // Now we perform DP on the DAG.
        // dp[i] = maximum coins that can be collected ending at component i.
        vl dp(cnt+1, 0);
        // Compute indegree for each component in the condensed graph.
        vector<int> indegree(cnt+1, 0);
        f(i,0,cnt,1) 
        {
            for(auto j : b[i]) 
                indegree[j]++;
        }
        
        // Initialize dp for each component with its own coin sum.
        f(i,0,cnt,1)
            dp[i] = sum[i];
        
        // Topological order processing using Kahn's algorithm.
        queue<int> q;
        f(i,0,cnt,1) 
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) 
        {
            int cur = q.front();
            q.pop();
            for(auto nxt : b[cur]) 
            {
                // Try to relax the dp value of nxt.
                dp[nxt] = max(dp[nxt], dp[cur] + sum[nxt]);
                indegree[nxt]--;
                if(indegree[nxt] == 0)
                    q.push(nxt);
            }
        }
        
        // The answer is the maximum dp value among all components.
        ll ans = 0;
        for(auto x : dp)
            ans = max(ans, x);
        cout<<ans<<endl;
    }
    return 0;
}
