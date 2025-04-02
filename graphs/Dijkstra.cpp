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
void dijkstra(int s, vector<vector<pair<int,ll>>>& adjlist, vi &dist)
{
    dist[s] = 0;
    priority_queue<pp, vip, greater<pp>> pq;
    pq.push({0,s});
    while(!pq.empty())      //O(n)
    {
        auto it = pq.top();
        pq.pop();       //O(logn)
        int node = it.ss;
        ll e_dist = it.ff;
        if(e_dist != dist[node])    continue;
        for(auto p: adjlist[node])      //O(m)
        {   //in adjlist , dist is p.second but in pq it is p.first
            if(dist[p.ff] > dist[node]+p.ss)
            {
                dist[p.ff] =  dist[node] + p.ss;
                pq.push({dist[p.ff], p.ff});
            }
        } 
    }
}       //TC => O((n+m)logn)
int main()
{   
    int n,m;    //n->vertices, m->edges
    cin>>n>>m;
    vector<vector<pair<int,ll>>> adjlist(n);        //0-based vertex start.
    f(i,0,m,1)
    {
        int x,y,d;
        cin>>x>>y>>d;
        adjlist[x].pb({y,d});
        adjlist[y].pb({x,d});
    }
    vi dist(n, inf);
    int s = 0;  //source
    dijkstra(s, adjlist, dist);
    for(auto it: dist)
        cout<<it<<" ";
    return 0;
}

/*variations :-
->To print all the nodes that occur on the shortest paths from node a to node b
1.run dijkstra from node a to x(all nodes).
2.run dijjkstra from node b to x.
3.if dist from node a to x + dist from node b to x = dist from node a to b.
then x lies on the path.


->i have a graph in which i have to reach a node b from node a before the enemy E 
can catch me.
so my approach is to first do dijkrstra to find the min dist 
from node a to all nodes, and then do same for all nodes from enemy node e , 
then for those nodes whose dist from a is more than dist from e , we will mark 
them danger, and then for the rest of the nodes , we will do a dijkstra to reach node b.

->No of shortest paths to every node from a source.
*/