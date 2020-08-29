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
#define dba(x) for(auto i : x) cout<<i<<" "
#define dbm(x) for(auto i : x){for(auto j : i) cout<<j<<" "; cout<<"\n";}
#define MOD 1000000007
using namespace std;
const int maxN = 100001;
int n, a[10002];
set<int> st;
int dp[maxN];
// void solve(int i, int cur){
//     if(dp[cur][i])return;
//     dp[cur][i] = 1;
//     if(cur != 0)
//         st.insert(cur);
//     if(i >= n)return;
//     solve(i+1, cur);
//     solve(i+1, cur+a[i]);
//     for(int j = i+1; j< n; j++){
//         solve(j, cur + a[i] );
//     }


// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    rep(i,n)cin>>a[i];
    memset(dp,0,sizeof(dp));
    dp[0]  = 1;
    rep(j, n){
        for(int i = maxN; i; i--){
            if(i >= a[j]) dp[i] |= dp[i-a[j]];
        }
    }
    vi b;
    for(int i = 1; i < maxN; i++)if(dp[i])b.push_back(i);

    db(b.size());
    dba(b);


}