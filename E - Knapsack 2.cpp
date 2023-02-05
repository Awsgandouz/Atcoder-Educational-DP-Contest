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
 
ll dp[100001][101];
 
void solve(){
	
	ll n , wt;
  cin >> n >> wt;
  ll v[n] , w[n];
  for(int i=0 ; i < n ;i++) cin>> w[i] >> v[i];
 
	for(int i = 0 ;i <= n;i++) dp[0][i]=0;
	for(int i = 1;i <= 100000; i++) dp[i][n]=wt+1;

  for(int i = 1; i <= 100000; i++){
		for(int j = n-1; j>=0 ;j--){
			dp[i][j] = dp[i][j+1];
			if(i-v[j]>=0) dp[i][j] = min(dp[i][j],w[j]+dp[i-v[j]][j+1]);
		}
	}
  
	ll ans = 0;
	for(int i = 0;i <= 100000; i++) if(dp[i][0]>0&&dp[i][0]<=wt) ans = max(ans,(ll)i);
	cout <<  ans << endl;
 
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
