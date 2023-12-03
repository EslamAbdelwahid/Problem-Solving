#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define int long long
#define get_bit(n,i) ((n>>i)& 1LL)
#define all(x) x.begin(),x.end()
const int N = 1e5 + 5,M = 15001, LG = 19 , SQRTN = 175;
const long long mod = 1e9 + 7, OO = 6ll * 1e18;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int dx[8] = {0,  0, 1, -1,  1, -1, 1, -1};
int dy[8] = {1, -1, 0,  0, -1,  1, 1, -1};
int chessX[8] = {-1,1,-1,1 , -2,-2,2,2};
int chessY[8] = {-2 , -2 ,2,2 ,1,-1,1,-1};

int n , k , arr[N], dp[N];
int best(int i){
    if(i == n) return 0;
    if(i > n) return OO;
    int &ret = dp[i];
    if(~ret) return ret;
    ret = OO;
    for(int j = 1;j <= 2 && i + j <= n;++j){
        ret = min(ret,best(i + j) + abs(arr[i] - arr[i + j]));
    }
    return ret;
}
void solve(){
    cin >> n ;
    for(int i = 1;i <= n;++i){
        cin >> arr[i];
    }
    memset(dp,-1,sizeof (dp));
    cout << best(1);
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    int t = 1;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    // cin >> t;

    for(int i = 1;i <= t;++i){
        solve();
    }
    return 0;
}