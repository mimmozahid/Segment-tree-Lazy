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
    ll sum = 0, product = 1;
    vector<ll> v(n);
    for (auto &x : v)
    {
        cin >> x;
        sum += x;
        product *= x;
    }

    // cout << sum << endl;
    // cout << product << endl;
    
    if (sum != 0 && product != 0)
    {
        cout << 0 << endl;
        return;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            v[i] = 1;
            ans++;
        }
    }
    sum = 0, product = 1;
    for (auto x : v)
    {
        sum += x;
        product *= x;
    }
    
    if (sum == 0 && product == 0)
    {
        cout << 1 << endl;
        return;
    }
    if (sum == 0 && product != 0)
        cout << ans+1 << endl;
    else
        cout << ans << endl;
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

