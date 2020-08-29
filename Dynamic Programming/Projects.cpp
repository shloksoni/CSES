#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vpii vector<pair<ll,ll>>
#define pii pair<ll,ll>
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
#define ar array
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ar<ll,3>> a(n);
    rep(i,n){
        cin>>a[i][1]>>a[i][0]>>a[i][2];
    }

    sort(all(a));

    set<ar<ll,2>> dp;
    dp.insert({0,0});
    ll ans = 0;
    rep(i,n){
        auto it = dp.lower_bound({a[i][1]});
        --it;
        ans  = max(ans, (*it)[1]+a[i][2]);
        dp.insert({a[i][0], ans});
    }
    db(ans);
    


}