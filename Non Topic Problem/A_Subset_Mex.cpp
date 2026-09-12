#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 



void solve ()
{
    int n;
    cin >> n;
    vector<int> frq(109);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        frq[x]++;
    }
    
    int mex_a = 0;
    while (frq[mex_a] > 0) mex_a++;
    int mex_b = 0;
    while (frq[mex_b] > 1) mex_b++;

    cout << mex_a+mex_b << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--)
        solve ();

    return 0;
}

