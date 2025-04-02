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

//TopSort only work on directed Acyclic Graphs (DAGs)
void dfs(int node,vector<bool>& vis, vii &adjlist, stack<int>& st)
{
    vis[node] = true;
    for(auto it: adjlist[node])
    {
        if(!vis[it])
        {
            dfs(it, vis, adjlist, st);
        }
    }
    st.push(node);
}

int main()
{   
    int n,m;    //n->vertices, m->edges
    cin>>n>>m;
    vii adjlist(n+1);
    f(i,0,m,1)
    {
        int x,y;
        cin>>x>>y;
        adjlist[x].pb(y);
    }
    vi ans;
    vector<bool> vis(n+1,false); 
    stack<int> st; 
    f(i,1,n+1,1)  
    {                   
        if(!vis[i])
        {
            dfs(i, vis, adjlist, st);
        }
        
    }
    while(st.size()) //prints the node with its component number
    {
        ans.pb(st.top());
        cout<<st.top()<<" ";
        st.pop();
    }    
    return 0;
}