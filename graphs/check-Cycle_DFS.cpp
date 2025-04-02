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
#define vip vector<pair<int,int>>
#define mi map<int,int>
#define dl double
#define sorty(v) sort(v.begin(),v.end())
#define pb push_back
#define coe cout<<endl
const int MAXN=1000005;
const ll mod=1000000007ll;

//for simple dfs convert the ans vector to vi and remove cnt from the code.
void dfs(int node,vector<bool>& vis, vii &adjlist, int parent, bool &cycleFound)
{
    vis[node] = true;
    for(auto it: adjlist[node])
    {
        if(it == parent)    continue;   //it also has node in its adjlist , so we are skipping that.
        if(!vis[it])
            dfs(it, vis, adjlist, node, cycleFound);
        else        //if it is visited but its not the parent(node) , then it is in a cycle.
        if (!cycleFound) 
        {  // Print only once.
            cout << "Cycle is present." << endl;
            cycleFound = true;
        }
    }
}

int main()
{   
    int n,m;    //n->vertices, m->edges
    cin>>n>>m;
    vii adjlist(n);
    f(i,0,m,1)
    {
        int x,y;
        cin>>x>>y;
        adjlist[x].pb(y);
        adjlist[x].pb(y);
    }
    vector<bool> vis(n,false);
    bool cycleFound = false;
    f(i,0,n,1)  //can remove this for loop for connected graph and directly call dfs.
    {                   
        if(!vis[i])
            dfs(i, vis, adjlist, -1, cycleFound);
    } 
    if (!cycleFound)
        cout<<"No cycle present."<<endl;      
    return 0;
}