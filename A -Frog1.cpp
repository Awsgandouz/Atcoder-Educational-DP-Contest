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
    
    int n ;
    cin>>n;
    vi v(n);
    read(v,n);
    int dp[n];
    memset(dp , 0 , sizeof dp);
    dp[0] = 0 , dp[1] = abs(v[1] - v[0]);
    for(int i=2;i<n;i++){
        dp[i] = min(dp[i - 1] + abs(v[i] - v[i-1]) , dp[i-2] + abs(v[i-2] - v[i]));
    }
    cout << dp[n-1] << endl;   
 
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
