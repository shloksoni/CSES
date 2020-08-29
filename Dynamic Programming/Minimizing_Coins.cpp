#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
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
int n, total;
vll a,dp;
ll solve(ll curSum)
{
    if(curSum == total)return 0;
    if(curSum > total)return INT_MAX;
    if(dp[curSum] != -1)return dp[curSum];
    ll cnt = INT_MAX;
    for(int i = 0; i < n; i++){
        if(a[i] <= total){
            cnt = min(cnt, solve(curSum + a[i])+1); 
        }
    }
    return dp[curSum] = cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>total;
    a.resize(n);
    dp.resize(total + 1, -1);
    rep(i,n)cin>>a[i];
    int ans = solve(0);
    if(ans >= INT_MAX)ans = -1;
    cout<<ans;
}