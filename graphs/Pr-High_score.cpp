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
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
#define pp pair<ll,ll>
#define ppl pair<ll,pair<ll,ll>>
#define vip vector<pair<ll,ll>>
#define mi map<int,int>
#define dl double
#define sorty(v) sort(v.begin(),v.end())
#define pb push_back
#define coe cout<<endl
const ll inf = LLONG_MAX;
// const int MAXN = 1000005;
const ll mod = 1000000007ll;

//dfs to store the nodes reachable from 1 for call 1 and from n for call 2.
void dfs(int node, vvl &adj, vi &vis)
{
    vis[node] = 1;
    for(auto it:adj[node])
    {
        if(!vis[it])
            dfs(it, adj, vis);
    }
}
int main()
{
    ios::sync_with_stdio(false);  
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vvl adj(n+1), t_adj(n+1);     //t_adj->to check the nodes reachable from node n in reverse.
    vector<tuple<int,int,ll>> edges(n+1);
    f(i,0,m,1)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb(v);
        t_adj[v].pb(u);
        edges.pb({u,v,w});
    }

    vi vis(n+1, 0), t_vis(n+1, 0);
    dfs(1, adj, vis);
    dfs(n, t_adj, t_vis);
    vl dist(n+1, -inf);
    dist[1] = 0;
    f(i,1,n,1)      //bellman ford algo n-1 iterations.
    {
        for(auto it:edges)
        {
            int u,v;
            ll w;
            tie(u, v, w) = it;
            if(vis[u] && t_vis[v] && dist[u] != -inf && dist[u]+w > dist[v])
            {
                dist[v] = dist[u]+w;
            }
        }
    }
    bool cycle = false;
    for(auto it : edges) 
    {
        int u, v;
        ll w;
        tie(u, v, w) = it;
        if(vis[u] && t_vis[v] && dist[u] != -inf && dist[u] + w > dist[v]) 
        {
            cycle = true;   //+ve cycle exists.
            break;
        }
    }
    if(cycle)    cout<<-1<<endl;
    else    cout<<dist[n]<<endl;

    return 0;
}
/*Although the classic Bellman–Ford finds shortest paths by "minimizing" distances, 
you can flip the comparison (i.e. use “if dp[u] + x > dp[v]”) to compute maximum 
scores. This lets you calculate, for every room, the best score you can achieve when
 coming from room 1.
 Since you can traverse tunnels multiple times, you might revisit rooms to accumulate 
 more score. If there’s a cycle that increases your score (a net positive cycle), then 
 you can theoretically boost your score without bound. Bellman–Ford can be extended to 
 detect such cycles—by doing an extra iteration and checking for further improvements, 
 you know if an arbitrarily large score is possible.*/