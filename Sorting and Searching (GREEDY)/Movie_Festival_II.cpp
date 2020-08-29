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
struct cmp { 
    bool operator()( const ll &x, const ll &y) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return x > y; 
    } 
}; 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    vpii a(n);
    for(auto &i : a)cin>>i.first>>i.second;
    sort(all(a), [](const pii &x, const pii &y){
        if(x.second == y.second)return x.first < y.first;
        return x.second < y.second;
    });

    multiset<ll> mp;
    int cnt =0;
    for(auto i : a){
        auto it = mp.lower_bound(i.first + 1);
        if(it == mp.begin() && k > 0){
            mp.insert(i.second);
            k--;
            cnt++;
        }
        else if(it != mp.begin()){
            it--;
            mp.erase(it);
            mp.insert(i.second);
            cnt++;
        }
    }
    db(cnt);
}