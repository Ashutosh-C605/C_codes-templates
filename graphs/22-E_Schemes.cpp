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
#define vii vector<vector<ll>>
#define vil vector<vector<int>>
#define pp pair<ll,ll>
#define ppl pair<ll,pair<ll,ll>>
#define vip vector<pair<ll,ll>>
#define mi map<int,int>
#define dl double
#define sorty(v) sort(v.begin(),v.end())
#define pb push_back
#define coe cout<<endl
const ll infl = LLONG_MAX;
const int infi = INT_MAX;
const int MAXN = 1000005;
const ll mod = 1000000007ll;

// DFS in our functional graph.
// Starting from member 'node', we follow next until we reach a node that is already visited.
// The function returns the representative (i.e. the member where the cycle is detected).
int dfs(int node, vi& next, vi &vis_baap)
{
    vis_baap[node] = 1;
    if(!vis_baap[next[node]])
        return vis_baap[node] = dfs(next[node], next, vis_baap);
    return vis_baap[node]   = node;
}

int main() {
    ios::sync_with_stdio(false);  
    cin.tie(NULL);                
    int t = 1;
    // cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vi next(n+1);
        vi indegree(n+1);
        f(i,0,n,1)
        {
            int x;
            cin>>x;
            next[i] = x;
            indegree[x]++;
        }
        int cycle = 0;
        int indeg0cycle = 0;
        vi c_end(n+1), c_start(n+1);
        vi vis_baap(n+1);       //dual function, used as visited array and to store cycle repres.
        int j=0;
        f(i,1,n+1,1)
        {
            if(indegree[i]==0)
            {
                c_end[cycle] = dfs(i, next, vis_baap);
                c_start[cycle] = i;
                cycle++; 
            }
        }
        indeg0cycle = cycle;
        f(i,1,n+1,1)
        {
            if(!vis_baap[i])
            {
                c_end[cycle] = dfs(i, next, vis_baap);
                c_start[cycle] = i;
                cycle++; 
            }
        }
        // If there is exactly one cycle (cycleCount==1) and 
        //none of the cycles started at a zero indegree node,
        // it means the whole graph is a single cycle (already strongly connected), 
        //so no extra instructions are needed.
        if(cycle ==1 && indeg0cycle==0)
            cycle=0;

        cout<<cycle<<endl;
        f(i,0,cycle,1)
            cout<<c_end[i]<<" "<<c_start[(i+1)%cycle]<<endl;
          
    }
    return 0;
}
/*why 2nd loop was needed.
In the first loop, we only start a DFS from nodes with zero indegree. These nodes are natural 
"entry points" because no one calls them, so they are guaranteed to not be part of any other DFS chain.
However, in a functional graph (where each member calls exactly one other), it is very common 
to have cycles where every node has an indegree of exactly 1. In such cycles, none of the nodes have zero
indegree.
Example:
Consider a cycle: 2 → 3, 3 → 4, 4 → 2. Here, every node has indegree 1, so the first loop will skip all of them.*/