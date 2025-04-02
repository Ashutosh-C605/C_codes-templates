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
#define vip vector<pair<ll,ll>>
#define mi map<int,int>
#define pp pair<ll, ll>
#define dl double
#define sorty(v) sort(v.begin(),v.end())
#define pb push_back
#define coe cout<<endl
const int MAXN=1000005;
const ll mod=1000000007ll;
const ll inf = LLONG_MAX;
//Designed to handle negative edges aswell.
// Bellman-Ford function that computes shortest paths from 'source'.
// The graph is represented as a vector of pairs:
// Each edge is {u, {v, w}}, representing an edge from u to v with weight w.
// Returns true if no negative-weight cycle is detected, and false otherwise.
bool bellmanFord(int n, const vector<pair<int, pair<int, ll>>>& edges, int source, vector<ll>& dist, vector<int>& parent) {
    // Initialize distance and parent vectors.
    dist.assign(n, inf);
    parent.assign(n, -1);
    dist[source] = 0;
    
    // Relax all edges (n - 1) times.
    f(i,1,n,1) 
    {
        for (const auto &edge : edges) 
        {
            int u = edge.ff;
            int v = edge.ss.ff;
            ll w = edge.ss.ss;
            if (dist[u] != inf && dist[u]+w < dist[v]) 
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    
    // Check for negative-weight cycles.
    for (const auto &edge : edges) 
    {
        int u = edge.ff;
        int v = edge.ss.ff;
        ll w = edge.ss.ss;
        if (dist[u] != inf && dist[u]+w < dist[v]) 
            return false;  // Negative cycle detected.
    }
    
    return true;  // No negative cycle found.
}

int main() {
    int n, m;  // n -> number of vertices, m -> number of edges
    cin >> n >> m;
    vector<pair<int, pair<int, ll>>> edges;
    
    // Input edges: each edge as u v w.
    f(i,0,m,1) 
    {
        int u, v;
        ll w;
        cin >>
        
        
        u>>v>>w;
        edges.pb({u, {v, w}});
    }
    
    int source = 0;  // Set the source vertex (modify as needed)
    vector<ll> dist;
    vector<int> parent;

    // Run the Bellman-Ford algorithm.
    bool noNegativeCycle = bellmanFord(n, edges, source, dist, parent);
    
    if (!noNegativeCycle)
        cout << "Negative cycle detected!" << endl;
    else 
    {
        // Output shortest distances from the source.
        f(i,0,n,1)
            cout<<dist[i]<<" "; 
        cout<<endl;
    } 
    return 0;
}
