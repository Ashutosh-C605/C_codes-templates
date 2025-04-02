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

/*Dynamic Programming Transition:
The key idea is to try using each vertex k (from 1 to n) as an intermediate vertex for every pair of vertices i and j.
For each k, update:
dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j])
This step checks if the path from i to j is shorter when passing through 
k than the current known distance.*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        int n,m;    //n->vertices, m->edges
        cin>>n>>m;
        vii cost(n+1, vi(n+1));
        f(i,1,n+1,1)
        {
            f(j,1,n+1,1)
            {
                if(i==j)    cost[i][j] = 0;
                else    cost[i][j] = inf;
            }
        }
        f(i,0,m,1)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            cost[u][v] = min(cost[u][v], w);
        }
        f(k,1,n+1,1)
        {
            f(i,1,n+1,1)
            {
                f(j,1,n+1,1)
                {
                    if(cost[i][k] == inf || cost[k][j] == inf)  continue;
                    cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
                }
            }
        }
        f(i,1,n+1,1)
        {
            if(cost[i][i] < 0)
                cout<<"Negative loop is present."<<endl;
        }
    }
    return 0;
}