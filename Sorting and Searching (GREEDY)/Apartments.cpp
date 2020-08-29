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
bool suitable(int i, int j, int k){
    if(i < j){
        if(j-k <= i)return true;
        else return false;
    }
    else{
        if(j+k >= i)return true;
        return false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,k;
    cin>>n>>m>>k;
    vi a(n),b(m);
    rep(i,n)cin>>a[i];
    rep(i,m)cin>>b[i];
    sort(all(a), greater<>());
    sort(all(b),greater<>());
    ll cnt = 0;
    int i = 0, j = 0;
    while(i<n && j < m){
        if(suitable(a[i],b[j], k)){
            cnt++;
            i++,j++;
        }
        else if(a[i] > b[j])i++;
        else j++;
    }
    db(cnt);

}