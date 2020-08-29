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
vll dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin>>n;

    dp.resize(n+1,INT_MAX);

    for(int i = 1; i < 10; i++)dp[i] = 1;

    for(int i = 10; i<= n; i++){
        int curI = i;
        while(curI){
            dp[i] = min(dp[i], dp[i - (curI % 10)] + 1);
            curI /= 10;
        }
    }
    cout<< dp[n];
}