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
    vector<int> frq(26, 0);
    for (auto c : s)
    {
        frq[c-'a']++;
    }
    
    string a, b;
    for (int i = 0; i < 26; i++)
    {
        if (frq[i] > 0)
        {
            char c = 'a'+i;
            a.push_back (c);
            frq[i]--;
            break;
        }
    }

    for (int i = s.size()-1; i >= 0; i--)
    {
        if (frq[s[i]-'a']-- > 0)
        {
            b.push_back (s[i]);
        }
    }

    reverse (b.begin (), b.end());
    cout << a << " " << b << endl;
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

