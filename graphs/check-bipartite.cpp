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
#define min3(x, y, z) min(min(x, y), z)
#define max3(x, y, z) max(max(x, y), z)
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
const ll inf = LLONG_MAX;
const int MAXN = 1000005;
const ll mod = 1000000007ll;
//if graph isn't bipartite that means it has odd length cycle.
//for simple dfs convert the ans vector to vi and remove cnt from the code.
bool isBipartite = true; // Global flag for bipartite checking

void dfs(int node, vvi &adjlist, vi &color) 
{
    for(auto it : adjlist[node]) 
    {
        if(color[it] == 0) 
        {  
            color[it] = (color[node] == 1) ? 2 : 1;  
            dfs(it, adjlist, color);
        }
        else if(color[it] == color[node])  
            isBipartite = false;
    }
}

int main()
{   
    int n,m;    //n->vertices, m->edges
    cin>>n>>m;
    vvi adjlist(n);
    f(i,0,m,1)
    {
        int x,y;
        cin>>x>>y;      //assuming 0-based vertex input.
        adjlist[x].pb(y);
        adjlist[y].pb(x);
    }
    vi color(n,0); //counts how many disconnected components are there.
    f(i,0,n,1)  //can remove this for loop for connected graph and directly call dfs.
    {                   
        if(color[i] == 0)
        {
            color[i] = 1;
            dfs(i, adjlist, color);
        }
        
    }
    if(!isBipartite) 
        cout << "Graph is NOT Bipartite" << endl;
    else
    {
        cout << "Graph is Bipartite" << endl;
        for(auto i : color) 
            cout << i << " ";
        cout << endl;
    }    
    return 0;
}