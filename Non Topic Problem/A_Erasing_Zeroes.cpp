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
    string s;
    cin >> s;

    int ans = 0, zeros = 0;

    int i = 0;
    while (i < s.size() && s[i] != '1') i++;
    
    for (int j = i; j < s.size(); j++)
    {
        if (s[j] == '0') zeros++;
        else
        {
            ans += zeros;
            zeros = 0;
        }
    }
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

