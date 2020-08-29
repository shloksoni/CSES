#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define vvll vector<vll>
#define repa( i,  b,  n) for(int i =b; i< n; i++)
#define rep( i,  n) for(int i =0; i< n; i++)
#define INF 1e9
#define MP make_pair
#define ll long long int
#define M 1000000007
#define all(a) a.begin(),a.end()
// debugging
#define db(x) cout<<x<<"\n";
#define db1(x) cout<<#x<<"="<<x<<"\n"
#define db2(x,y) cout<<#x<<"="<<x<<", "<<#y<<"="<<y<<"\n" 
#define db3(x,y,z) cout<<#x<<"="<<x<<", "<<#y<<"="<<y<<", "<<#z<<"="<<z<<"\n"
#define dba(x) for(auto i : x) cout<<i<<"\t"
#define dbm(x) for(auto i : x){for(auto j : i) cout<<j<<" "; cout<<"\n";}
#define MOD 1000000007
using namespace std;
const int maxN = 100002;
int a[maxN];
int dp[maxN][100];
int n,m;
ll solve(int i, int prev){
    if(i == n)return 1;
    if(dp[i][prev] != -1)return dp[i][prev];
    if(a[i] != 0){
        if(abs(prev-a[i]) > 1) return dp[i][prev] = 0;
        return dp[i][prev] = solve(i+1, a[i]);
    }
    ll ans =0;
    ans += solve(i+1, prev) % MOD;
    if(prev + 1 <= m)ans += solve(i+1, prev +1) % MOD;
    if(prev - 1 > 0)ans += solve(i+1, prev -1) % MOD;
    return dp[i][prev] = ans % MOD;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    rep(i,n)cin>>a[i];
    memset(dp,-1,sizeof(dp));
    ll ans = 0;
    if(a[0] == 0){
        for(int i =1; i<= m; i++){
            ans += solve(1,i) % MOD;
        }
    }
    else ans = solve(1,a[0]) % MOD;

    db(ans % MOD);

}