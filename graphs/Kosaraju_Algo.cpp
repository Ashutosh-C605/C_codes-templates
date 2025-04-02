#include<bits/stdc++.h>
//authored by ashu_astos
using namespace std;
typedef long long ll;
#define ff first
#define ss second
#define f(i,a,n,x) for(ll i=a;i<n;i+=x)
#define fr(i,a,n,x) for(int i=a;i>n;i-=x)
#define vi vector<ll>
#define vs vector<string>
#define all(v) v.begin(), v.end()
#define vii vector<vector<ll>>
#define pp pair<ll,ll>
#define ppl pair<ll,pair<ll,ll>>
#define vip vector<pair<ll,ll>>
#define mi map<int,int>
#define dl double
#define sorty(v) sort(v.begin(),v.end())
#define pb push_back
#define coe cout<<endl
const ll inf = LLONG_MAX;
const int MAXN=1000005;
const ll mod=1000000007ll;

stack<int> st;
vi temp;
vii scc;

void dfs(int node, vi& vis, vii& adj)
{
    vis[node] =1;
    for(auto it: adj[node])
    {
        if(vis[it]==0)
            dfs(it, vis, adj);
    }
    st.push(node);
}

void dfs2(int node, vi& vis, vii& t_adj)
{
    vis[node] = 1;
    temp.pb(node);
    for(auto it:t_adj[node])
    {
        if(vis[it]==0)
            dfs2(it, vis, t_adj);
    }
}
int main() {
    ios::sync_with_stdio(false);  
    cin.tie(NULL);                
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vii adj(n+1),t_adj(n+1);    //t_adj ->transpose adj reversed edges.
        f(i,0,m,1)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            t_adj[v].pb(u);
        }
        vi vis(n+1,0);
        f(i,1,n+1,1)
        {
            if(vis[i] == 0)
                dfs(i,vis,adj);
        }
        fill(all(vis), 0);      // Reset visited array for second DFS.
        while(st.size())
        {
            auto node = st.top();
            st.pop();
            if(vis[node]==0)
            {
                dfs2(node, vis, t_adj);
                scc.pb(temp);
                temp.clear();
            }   
        }
        cout<<scc.size()<<endl;
        for(auto it : scc)
        {
            for(auto j:it)
                cout<<j<<" ";
            coe;
        }
    }
    return 0;
}