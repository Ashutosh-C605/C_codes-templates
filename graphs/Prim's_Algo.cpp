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

/*Prim's algorithm is a greedy algorithm used to find a minimum spanning tree (MST) 
for a weighted, connected graph. The key idea is to build the MST incrementally, 
starting from an arbitrary vertex and repeatedly adding the lightest edge that 
connects a vertex in the growing MST to a vertex outside it.
Use a priority queue (or min-heap) to store edges that connect the MST to vertices 
not yet in the MST. Each edge is prioritized by its weight.
O(ElogV) for a graph with V vertices and E edges.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        int n,m;    //n->vertices, m->edges
        cin>>n>>m;
        vector<vector<pp>> adjlist(n+1);
        f(i,0,m,1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adjlist[u].pb({v,w});
            adjlist[v].pb({u,w});

        }
        priority_queue<vi, vii, greater<vi>> pq;    //stores dist, node, parent.
        vi vis(n+1,0);  //marks nodes which are part of MST.
        vip edges;  //to store the edges of MST.
        ll sum = 0;
        pq.push({0, 1, 0});
        while(pq.size())
        {
            auto it = pq.top();
            pq.pop();
            ll dist = it[0], node = it[1], parent = it[2];
            if(vis[node]==1)    continue;   //already processed earlier.
            vis[node] = 1;
            sum += dist;
            if(parent != 0)     //) was the imaginary vetex to store parent of 1.
            edges.pb({node, parent});
            for(auto it:adjlist[node])
            {
                if(vis[it.ff] == 0) 
                    pq.push({it.ss, it.ff, node});
            }
        } 
        cout<<sum<<endl;
        for(auto it:edges)
        {
            cout<<it.ff<<" "<<it.ss<<endl;
        }
    }
    return 0;
}