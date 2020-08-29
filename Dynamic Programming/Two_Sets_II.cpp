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
const int maxN = 100000;
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll ans =0;
 
    ll t = (n * (n+1))/2;
    if(t&1){
        cout<<0<<"\n";
        exit(0);
    }
    ll dp[(t/2)+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i =1; i<= n; i++){
        for(int j = t/2; j>=i; j--){
            dp[j]  =  (dp[j] + dp[j-i]) %MOD;
        }
    }
    // cout<<"he";
    db(dp[t/2] * ((MOD + 1)/ 2) % MOD);

 
}