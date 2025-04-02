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
    vi ans;
    vector<bool> vis(n,false);
    vector<int> parent(n, -1);
    bool cycleFound = false;
    for (int i=0; i<n && !cycleFound; i++) 
    {
        if (!vis[i]) 
        {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            parent[i] = -1;
            
            while (!q.empty() && !cycleFound) 
            {
                int node = q.front();
                q.pop();
                
                for (int it : adjlist[node]) 
                {
                    if (!vis[it]) 
                    {
                        vis[it] = true;
                        parent[it] = node;
                        q.push(it);
                    } 
                    // If the neighbor is visited and is not the parent,
                    // we found a cycle.
                    else if (it != parent[node]) 
                    {
                        cycleFound = true;
                        break;
                    }
                }
            }
        }
    }
    
    if (cycleFound)
        cout << "Cycle is present." << "\n";
    else
        cout << "No cycle present." << "\n";
    
    return 0;
}