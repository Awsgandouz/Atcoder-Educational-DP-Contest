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
 
const int N = 3009;
double p[N];
int n;
double dp[N][N];
 
double helper(int i , int j){
    if(i == n){
        if(j >= n - j) return 1.0; 
        return 0.0;
    }
    if(dp[i][j] != -1.0) return dp[i][j];   
    double l = 0 , r = 0;
    return dp[i][j] = p[i] * helper(i+1 , j+1) + (1.0 - p[i]) * helper(i+1 , j);
    
}
 
void solve(){
    cin >> n;
    read(p , n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1.0;
        }
    }
    cout << setprecision(9);
    cout << fixed;
    cout << helper(0 , 0) << endl;
 
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
