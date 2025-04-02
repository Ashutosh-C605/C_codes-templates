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
//on every iteration, the marked vertex is the one which can never a better
//distance later on.
void dijkstra(int s, vector<vector<pair<int,ll>>>& adjlist,vi &parent, vi &dist)
{
    dist[s] = 0;
    priority_queue<pp, vip, greater<pp>> pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.ss;
        ll e_dist = it.ff;
        if(e_dist != dist[node])    continue;
        for(auto p: adjlist[node])
        {   //in adjlist , dist is p.second but in pq it is p.first
            if(dist[p.ff] > dist[node]+p.ss)
            {
                dist[p.ff] =  dist[node] + p.ss;
                parent[p.ff] = node;
                pq.push({dist[p.ff], p.ff});
            }
        } 
    }
}
int main()
{   
    int n,m;    //n->vertices, m->edges
    cin>>n>>m;
    vector<vector<pair<int,ll>>> adjlist(n);
    f(i,0,m,1)
    {
        int x,y,d;
        cin>>x>>y>>d;
        adjlist[x].pb({y,d});
        adjlist[y].pb({x,d});
    }
    vi dist(n, inf);
    int s = 0;  //source
    vi parent(n,-1);
    dijkstra(s, adjlist, parent, dist);
    for(auto it: dist)      //print shortest distances
        cout<<it<<" ";
    cout<<endl;
    int currNode = 2;       //print shortest path of any vertex.
    vi path;
    while(currNode != -1)
    {
        path.pb(currNode);
        currNode = parent[currNode];
    }
    reverse(all(path));
    for(auto it: path)      //print shortest distances
        cout<<it<<" ";
    return 0;
}