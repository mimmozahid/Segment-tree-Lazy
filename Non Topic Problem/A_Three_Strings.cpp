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
    string a, b, c;
    cin >> a >> b >> c;

    int n = (int)a.size();
    bool flg = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == c[i] && c[i] == b[i])
        {
            continue;
        }
        else if (a[i] == b[i] && c[i] != a[i])
        {
            flg = false;
            break;
        }
        else if (a[i] != b[i] && a[i] != c[i] && b[i] != c[i])
        {
            flg = false;
            break;
        }
        else if (a[i] != b[i])
        {
            // cout << i << endl;
            if (a[i] != c[i]) swap (a[i], c[i]);
            else if (b[i] != c[i]) swap (b[i], c[i]);
        }
    }
    

    if (!flg)
    {
        cout << "NO" << endl;
        return;
    }

    if (a == b)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
        // cout << a << " " << b << endl;
    }
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

