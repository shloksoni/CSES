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
int n;
vector<string>a;
vector<vll> dp;
ll dfs(int i, int j){
    if(i < 0 || j<0 || i==n || j==n || a[i][j] == '*')return 0;
    if(i == n-1 && j == n-1)return 1;
    if(dp[i][j] != -1)return dp[i][j];
    return dp[i][j] = (dfs(i,j+1)%MOD + dfs(i+1,j)%MOD)%MOD; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    a.clear();
    a.resize(n);
    dp.resize(n,vll(n,-1));
    rep(i,n)cin>>a[i];
    cout<<dfs(0,0);
}