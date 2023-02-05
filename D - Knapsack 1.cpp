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
 
void solve() {
	
	int n , w;
    cin >> n >> w;
    ll v[n][2];
    for(int i = 0 ; i < n ;i++){
        cin>> v[i][0] >> v[i][1] ;
    }
 
    ll dp[n][w+1];
    for(int i = 0 ; i < n; i++){
        dp[i][0] = 0;
    }
    for(int i = 0 ; i <= w; i++){
        dp[0][i] = (v[0][0] <= i ? v[0][1] : 0);
    }
    for(int i = 1 ; i < n ;i++){
        for(int j = 1 ; j <= w ;j++){
            if(j - v[i][0] >= 0)
                dp[i][j] = max(v[i][1] + dp[i-1][j-v[i][0]] , dp[i-1][j]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }      
    cout << dp[n-1][w] << endl;
 
 
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
