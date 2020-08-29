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

/* My own editorial 

The optimum strategy would be that the first person reads the shortest book and the 
second person reads the longest book. (sort the array)

Once the second person has finished reading his first book, there are 2 cases :

I -> the first person has finished reading all the n-2 books and is waiting for
    the second person (plausible because the second person is reading the longest book)
    this means the ans will be 2* len of longest book. 

II -> the first person is yet to finish the n-2 book. In this case the first person
    will move on to finish all the books and the second one would still be completing.
    This will result in the time it takes to read all the books. 
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll s =0, ma = INT_MIN;
    rep(i,n){
        ll x;
        cin>>x;
        s += x;
        ma = max(ma,x);
    }
    cout<<(max(s, 2*ma));

}