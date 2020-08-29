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
int dp[2][100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    vi p(n), pa(n);
    rep(i,n)cin>>p[i];
    rep(i,n)cin>>pa[i];
    memset(dp,0,sizeof(dp));
    
    for(int i =1; i<=n; i++){
        for(int j = 0; j <= k; j++){
            dp[i%2][j] = dp[(i-1)%2][j];
            if(p[i-1] <= j){
                dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j-p[i-1]] + pa[i-1]);   
            }
        }
    }

    db(dp[n %2][k]);


}