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
const ll INF = LLONG_MAX;

// Bellman-Ford function that computes shortest paths from 'source'.
// The graph is represented as a vector of pairs:
// Each edge is {u, {v, w}}, representing an edge from u to v with weight w.
// Returns true if no negative-weight cycle is detected, and false otherwise.
bool bellmanFord(int n, const vector<pair<int, pair<int, ll>>>& edges, int source,vi& dist, vi& parent, vi& negativeCycle) 
{
    // Initialize distance and parent vectors.
    dist.assign(n, INF);
    parent.assign(n, -1);
    dist[source] = 0;

    // Relax all edges (n - 1) times.
    f(i,1,n,1) 
    {
        for(const auto &edge : edges) 
        {
            int u = edge.ff;
            int v = edge.ss.ff;
            ll w = edge.ss.ss;
            if (dist[u] != INF && dist[u] + w < dist[v]) 
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative-weight cycles.
    int cycle_start = -1;
    for (const auto &edge : edges) 
    {
        int u = edge.ff;
        int v = edge.ss.ff;
        ll w = edge.ss.ss;
        if (dist[u] != INF && dist[u] + w < dist[v]) 
        {
            cycle_start = v;
            break;
        }
    }

    // No negative cycle found.
    if (cycle_start == -1)
    return true;

    // Negative cycle detected.
    // To ensure we are on a vertex in the cycle, walk back n times.
    f(i,0,n,1)
    cycle_start = parent[cycle_start];

    // Reconstruct the cycle.
    int cur = cycle_start;
    negativeCycle.pb(cur);
    cur = parent[cur];
    while (cur != cycle_start) 
    {
        negativeCycle.pb(cur);
        cur = parent[cur];
    }
    negativeCycle.pb(cycle_start);
    reverse(all(negativeCycle));

    return false;  // Negative cycle detected.
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
        cin >> u >> v >> w;
        edges.pb({u, {v, w}});
    }
    
    int source = 0;  // Set the source vertex (modify as needed)
    vi dist;
    vi parent;
    vi negativeCycle;
    
    // Run the Bellman-Ford algorithm.
    bool noNegativeCycle = bellmanFord(n, edges, source, dist, parent, negativeCycle);
    
    if (noNegativeCycle) 
    {
        cout << "No negative cycle detected!" << endl;
        // Output shortest distances from the source.
        f(i,0,n,1) 
            cout << "Distance from " << source << " to " << i << " is " << dist[i] << endl;
    } 
    else 
    {
        cout << "Negative cycle detected:" << endl;
        // Print the cycle.
        for (int v : negativeCycle)
            cout << v << " ";
        cout << endl;
    }
     
    return 0;
}
