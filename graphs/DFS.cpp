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
void dfs(int node,vector<bool>& vis, vii &adjlist, vip &ans, int cnt)
{
    vis[node] = true;
    ans.pb({node, cnt});
    for(auto it: adjlist[node])
    {
        if(!vis[it])
        {
            dfs(it, vis, adjlist, ans, cnt);
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
        adjlist[y].pb(x);
    }
    vip ans;
    vector<bool> vis(n,false);
    int cnt=1;  //counts how many disconnected components are there.
    f(i,0,n,1)  //can remove this for loop for connected graph and directly call dfs.
    {                   
        if(!vis[i])
        {
            dfs(i, vis, adjlist, ans, cnt);
            cnt++;
        }
        
    }
    
    for(auto i:ans) //prints the node with its component number
    {
        cout<<i.ff<<" "<<i.ss<<endl;
    }
        
    return 0;
}