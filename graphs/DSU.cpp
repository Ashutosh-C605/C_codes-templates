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

int main() {
    ios::sync_with_stdio(false);  
    cin.tie(NULL);                
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        dsu d(n);
        f(i,0,m,1)
        {
            int u,v;
            cin>>u>>v;
            d.unionRank(u,v);
        }
        vi ans;
        set<int> st;
        f(i,1,n+1,1)
        {
            int x = d.findpar(i);
            if(st.find(x) == st.end())
            {
                ans.pb(x);
                st.insert(x);
            }
            
            
        }
        cout<<ans.size()-1<<endl;
        f(i,1,ans.size(),1)
        {
            cout<<ans[i-1]<<" "<<ans[i]<<endl;
        }
    }
    return 0; 
}