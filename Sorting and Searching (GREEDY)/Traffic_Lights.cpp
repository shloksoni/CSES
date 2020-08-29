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
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n;
    cin>>x>>n;
    vi a(n);
    rep(i,n){
        cin>>a[i];
    }
    set<int> st; // store the values in order.
    map<int,int> mp; // store the length
    st.insert(0);
    st.insert(x);
    mp[x] = 1; // initiall the count of length 0 to x  is 1;
    for(int i : a){
       auto it = st.lower_bound(i);
       int r = *it; //right will be the next element to the i;
       it--;
       int l = *it;  // left will be the one element before the right
       mp[r-l]--;  // reducing the count of the current length because it is going to change now
       if(mp[r-l] == 0){ 
           mp.erase(r-l); // if there are no more count of length (r-l), remove the element.
        //    this will help us print the max len directly. Check the last line.
       }
       st.insert(i);
       mp[i-l]++;  // increment the two length 
       mp[r-i]++;
       cout<<(mp.rbegin()->first)<<" "; // the max ans will be stored in the map
    }

}