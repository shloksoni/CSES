#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define pii pair<ll,int>
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
deque<pii> dq;

void push( pii n){
    while(!dq.empty() && dq.back().first >= n.first)dq.pop_back();
    dq.push_back(n);
}
void pop( pii n){
    if(dq.front().second == n.second)dq.pop_front();
}

ll getMin(){
    return dq.front().first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l,r;
    cin>>n>>l>>r;
    ll ans = -1e18;
    vll a(n+1);
    rep(i,n)cin>>a[i+1], a[i+1] += a[i];
    for(int i = l; i<=n ; i++){
       push({a[i-l], i-l});
        ans = max(ans, a[i] - getMin());
        if(i >= r) pop({a[i-r], i-r});
    }
    db(ans);
}