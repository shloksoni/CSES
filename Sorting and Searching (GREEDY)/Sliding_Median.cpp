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
multiset<ll> r;
multiset<ll> l; // gives largest

int add(int n){
    l.insert(n);
    auto it = l.end();
    --it;
    r.insert(*it);
    l.erase(it);
    if(r.size()> l.size()){
        l.insert(*r.begin());
        r.erase(r.begin());
    }

    
    return *l.rbegin();
}
void remove(int n){
    auto it = l.find(n);
    if( it != l.end()){
        l.erase(it);
        if(l .size() < r.size()){
            l.insert(*r.begin());
            r.erase(r.begin());
        }
    }
    else{
        if(l.size() > r.size()){
            r.erase(r.find(n));
             it = l.end();
            --it;
            r.insert(*it);
            l.erase(it);
        }
        else{r.erase(r.find(n));}
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    vi a(n);
    rep(i,n){
        int x;
        cin>>x;
        a[i] = x;
        ll ans = add(x);
        if(i >= k-1){
            cout<<ans<<" ";
            remove(a[i-k+1]);

        }
    }
}