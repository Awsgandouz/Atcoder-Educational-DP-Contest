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
 
string s , t;
int n , m ;
 
const int N = 3001;
int  dp[N][N];
 
 
int helper(int i , int j){
    if(i >= n || j >= m){
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]){
        return dp[i][j] = 1 + helper(i + 1 , j + 1); 
    }else {
        return dp[i][j] = max(helper(i+1 , j) , helper(i , j + 1));   
    }
}
 
void solve(){
    cin >> s >> t;
    n = s.size() , m = t.size();
    memset(dp , -1 , sizeof dp);
    int lcs = helper(0 , 0);
    
    int i = 0 , j = 0;
    while(lcs){
        if(s[i] == t[j]){
            cout << s[i] ;
            i++;
            j++;
            lcs--;
        }else if(dp[i+1][j] > dp[i][j+1]){
            i++;
        }else {
            j++;
        }
    }
 
 
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
