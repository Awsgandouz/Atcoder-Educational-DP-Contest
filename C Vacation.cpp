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
	
	int n ;
	cin>>n;
	ll day[n][3];
	for(int i=0;i<n;i++){
		cin>>day[i][0]>>day[i][1]>>day[i][2];
	}
	ll dp[n][3];
	
	dp[0][0] = day[0][0];
	dp[0][1] = day[0][1];
	dp[0][2] = day[0][2];
 
 
	for(int i=1 ; i<n ; i++){
		dp[i][0] = max(dp[i-1][0] , day[i][0] + max(dp[i-1][1] , dp[i-1][2]));
		dp[i][1] = max(dp[i-1][1] , day[i][1] + max(dp[i-1][2] , dp[i-1][0]));
		dp[i][2] = max(dp[i-1][2] , day[i][2] + max(dp[i-1][1] , dp[i-1][0]));
 
	}
	cout << max(dp[n-1][0] , max(dp[n-1][1] , dp[n-1][2])) << endl;
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
 
 
