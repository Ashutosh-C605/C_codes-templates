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

bool cycleFound = false;
//for simple dfs convert the ans vector to vi and remove cnt from the code.
void dfs(int node,vector<bool>& vis, vii &adjlist, int parent, vi &path)
{
    vis[node] = true;
    path.pb(node);
    for(auto it: adjlist[node])
    {
        if(it == parent)    continue;   //it also has node in its adjlist , so we are skipping that.
        if(!vis[it])
        {
            dfs(it, vis, adjlist, node, path);
            if (cycleFound) return;
        }
        else 
        {
            // Found a visited neighbor that is not the parent.
            // This neighbor should be in the current path (i.e. an ancestor).
            auto idx = find(path.begin(), path.end(), it);
            if (idx != path.end()) 
            {
                cycleFound = true;
                cout << "Cycle is present: ";
                // Print the cycle vertices: from the neighbor's position in the path to the current node.
                for (auto iter = idx; iter != path.end(); ++iter) 
                    cout <<*iter<< " ";
                // To show the cycle clearly, print the starting neighbor again.
                cout <<it<< "\n";
                return;
            }
        }       
    }
    path.pop_back();
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
    vector<bool> vis(n,false);
    vi path;
    f(i,0,n,1)  //can remove this for loop for connected graph and directly call dfs.
    {                   
        if(!vis[i])
        {
            dfs(i, vis, adjlist, -1, path);
            if(cycleFound) break;
        }
            
        
    } 
    if (!cycleFound)
        cout<<"No cycle present."<<endl;      
    return 0;
}