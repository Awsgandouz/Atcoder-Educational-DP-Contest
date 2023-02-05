#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll eps = 1e-9;
typedef vector<int>vi;
typedef vector<ll>vl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define read(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define aff(v) for(int i : v) cout << i << ' ';
 
void solve(){
    int n , m ;
    cin >> n >> m;
    char grid[n][m];
    for(int i= 0 ;i < n ;i++) for(int j = 0 ;j < m; j++) cin>>grid[i][j];
    int dp[n][m];
    memset(dp , 0 , sizeof dp);
    dp[0][0] = 1;
    for(int i = 1;i<n;i++){
        if(dp[i-1][0] == 0){
            dp[i][0] = 0;
            continue;
        }
        dp[i][0] = (grid[i][0] =='.' ? 1 : 0);
    }
    for(int i = 1;i<m;i++){
        if(dp[0][i-1] == 0){
            dp[0][i] = 0;
            continue;
        }
        dp[0][i] = (grid[0][i] =='.' ? 1 : 0);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(grid[i][j] == '#'){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i-1][j] % mod + dp[i][j-1] % mod) % mod;
        }
    }
    cout << dp[n-1][m-1] << endl;
 
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
