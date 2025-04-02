#include<bits/stdc++.h>
//authored by ashu_astos
using namespace std;
typedef long long ll;
#define ff first
#define ss second
#define f(i,a,n,x) for(ll i=a;i<n;i+=x)
#define fr(i,a,n,x) for(int i=a;i>n;i-=x)
#define vi vector<int>
#define vs vector<string>
#define all(v) v.begin(), v.end()
#define vii vector<vector<ll>>
#define vip vector<pair<int,int>>
#define mi map<int,int>
#define dl double
#define sorty(v) sort(v.begin(),v.end())
#define pb push_back
#define coe cout<<endl
const int MAXN=1000005;
const ll mod=1000000007ll;

/*
A Minimum Spanning Tree (MST) is a subgraph of a weighted, connected, undirected graph that:

Spans All Vertices: It connects all the vertices together without forming any cycles.
Is a Tree: Being a tree means it has exactly 𝑛−1 edges (where n is the number of vertices) and is acyclic.
Minimizes Total Weight: Out of all possible spanning trees of the graph, the MST is the one where the 
sum of the edge weights is as small as possible.
*/

class dsu
{
    vi parent, size, rank;

public:

    dsu(int n)
    {
        f(i,0,n+1,1)
        {
            parent.pb(i);
            size.pb(1);
            rank.pb(0);
        }
    }
    int findpar(int node)
    {
        if(parent[node] == node)
            return node;
        return parent[node] = findpar(parent[node]);
    }
    void unionSize(int u, int v)
    {
        int pu = findpar(u);
        int pv = findpar(v);
        if(pu == pv)    return;
        //attach smaller to bigger
        if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    void unionRank(int u, int v)
    {
        int pu = findpar(u);
        int pv = findpar(v);
        if(pu == pv)    return;
        //attach smaller to bigger
        if(rank[pv] == rank[pu])
        {
            parent[pu] = pv;
            rank[pv]++;
        }
        else if(rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pv] = pu;
        }
    }
};

void solve(vector<pair<ll ,pair<int,int>>>& edges, dsu &d)
{
    int sum=0;
    for(auto it:edges)
    {
        int w = it.ff;
        int u = it.ss.ff;
        int v = it.ss.ss;
        if(d.findpar(u) != d.findpar(v))      //edges processed from min weight to max and converted to MST.
        {
            sum += w;
            d.unionRank(u,v);
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
    }
    cout<<sum<<endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        int n,m;    //n->vertices, m->edges
        cin>>n>>m;
        vector<pair<ll ,pair<int,int>>> edges;
        f(i,0,m,1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            edges.pb({w, {u,v}});
        }
        sorty(edges);
        dsu d(n);
        solve(edges, d);
    }
    return 0;
}
