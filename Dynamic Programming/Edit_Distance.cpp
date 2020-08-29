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

 int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        //word1 = col, word 2 = row
        vector<vector<int>> dp(n2+1,vector<int>(n1+1,0));
        
        // when word1 is empty
        for(int i =0; i <= n2; i++)
            dp[i][0] = i;
        //when word2 is empty
        for(int i =0; i <= n1; i++)
            dp[0][i] = i;
        
        for(int i =1; i<=n2; i++){
            for(int j = 1; j<=n1; j++){
                if(word2[i-1] == word1[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    //replace
                    dp[i][j] = 1+dp[i-1][j-1];
    
                    //delete
                    dp[i][j] = min(dp[i][j], 1+ dp[i][j-1]);
                    //insert
                    dp[i][j] = min(dp[i][j], 1+dp[i-1][j]);
                }
            }
        }
        return dp[n2][n1];
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    db( minDistance(s1,s2));
}