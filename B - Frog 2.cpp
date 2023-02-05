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
 
void solve(){
    
    int n , k ;
    cin>>n>>k;
    int v[n];
    for(int i=0;i<n;i++) cin>>v[i];
    int dp[n];
    memset(dp , 0 , sizeof dp);
    dp[0] = 0;
    for(int i=1;i < min(n,k) ;i++){
        dp[i] = abs(v[i] - v[0]);
    }
    for(int i = min(k , n) ;i < n; i++){
        int mx = INT_MAX;
        for(int j=1;j<=k;j++){
            mx = min(mx , dp[i-j] + abs(v[i-j] - v[i]));
        }
        dp[i] = mx ;
    }
    cout << dp[n-1] ;
    
 
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
 
   // cin >> tc;
    
    for (int t = 1; t <= tc; t++){
       // cout << "case " << t << endl;
        solve();
    }
    return 0;
}
