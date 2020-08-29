#include <bits/stdc++.h>
#define vi vector<ll>
#define vvi vector<vi>
#define vll vector<ll>
#define vpii vector<pair<ll,ll>>
#define pii pair<ll,ll>
#define vvll vector<vll>
#define repa( i,  b,  n) for(ll i =b; i< n; i++)
#define rep( i,  n) for(ll i =0; i< n; i++)
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


struct cmp{
    bool operator()(const pii & x, const pii &y){
        return x.first > y.first;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<tuple<ll,ll,ll>> a;
    rep(i,n){
        ll start,end;
        cin>>start>>end;
        a.push_back(make_tuple(start,end,i));
    }

    sort(all(a), [](const tuple<ll,ll,ll> &x, const tuple<ll,ll,ll> &y){
        if(get<0>(x) == get<0>(y)) return get<1>(x) < get<1>(y);
        return get<0>(x) < get<0>(y);
    });


    priority_queue<pii, vpii, cmp> pq;

    
    vi ans(n);
    pq.push({get<1>(a[0]), 1});
    ll cnt = 1;
    ans[get<2>(a[0])] = 1;
    repa(i,1,n){
  
        if(pq.top().first >= get<0>(a[i])){
            pq.push({get<1>(a[i]), ++cnt});
            ans[get<2>(a[i])] = cnt;
        }
        else{
            auto t = pq.top();
            pq.pop();
            pq.push({get<1>(a[i]), t.second});
            ans[get<2>(a[i])] = t.second;
        }
       

     
    }

    db(cnt);
    dba(ans);

}