#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll eps = 1e-9;
typedef vector<int>vi;
typedef vector<ll>vl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define read(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define aff(v) for(int i : v) cout << i << ' ';
 
vi adj[100001];
int dp[100005];
 
int dfs(int u , vi& dp){
    if(dp[u] != -1) return dp[u];
    int ans = 0;
    for(int v : adj[u]){
        ans = max(ans , 1 + dfs(v , dp));
    }
    return dp[u] = ans;
}
 
void solve(){
    int n , m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u , v;
        cin>>u>>v;
        adj[--u].push_back(--v);
    }  
    vi dp(n , -1);
    int ans = 0;
    for(int i=0;i<n;i++){
        ans  = max(ans , dfs(i , dp));
    }
    cout << ans << endl;
    
 
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
 
    //cin >> tc;
    
    for (int t = 1; t <= tc; t++){
       // cout << "case " << t << endl;
        solve();
    }
    return 0;
}
