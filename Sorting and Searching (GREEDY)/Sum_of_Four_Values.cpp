#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vpii vector<pair<ll,int>>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,t;
    cin>>n>>t;
    vpii a(n);
    rep(i,n){
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(all(a));
    rep(h,n)
        repa(i,h+1,n){
        int j = i+1, k = n-1;
        while(j < k){
            ll sum = a[i].first + a[j].first + a[k].first + a[h].first;
            if(sum == t){
                cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second<<" "<<a[h].second<<"\n";
                exit(0);
            }
            if(sum < t) j++;
            else k--;
        }
    }
    cout<<"IMPOSSIBLE\n";
}