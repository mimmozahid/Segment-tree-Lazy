#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int mxN = 1e5+9, inf = 1e18;
ll a[mxN], t[4*mxN], lazy[4*mxN];

void push (int n, int b, int e)
{
    if (lazy[n] == 0) return;
    t[n] += lazy[n];
    if (b != e)
    {
        int l = 2*n, r = 2*n + 1;
        lazy[l] += lazy[n];
        lazy[r] += lazy[n];
    }
    lazy[n] = 0;
}

void build (int n, int b, int e)
{
    if (b == e)
    {
        t[n] = a[b];
        return;
    }
    int mid = (b+e)/2, l = 2*n, r = 2*n + 1;
    build (l, b, mid);
    build (r, mid+1, e);
    t[n] = min (t[l], t[r]);
}

void update (int n, int b, int e, int i, int j, int v)
{
    push (n, b, e);
    if (e < i || b > j)
    {
        return;
    }
    if (b >= i && e <= j)
    {
        lazy[n] = v;
        push (n, b, e);
        return;
    }
    int mid = (b+e)/2, l = 2*n, r = 2*n + 1;
    update (l, b, mid, i, j, v);
    update (r, mid+1, e, i, j, v);
    t[n] = min (t[l], t[r]);
}

ll query (int n, int b, int e, int i, int j)
{
    push (n, b, e);
    if (e < i || b > j)
    {
        return inf;
    }
    if (b >= i && e <= j)
    {
        return t[n];
    }

    int mid = (e+b)/2, l = 2*n, r = 2*n+1;
    return min (query (l, b, mid, i, j), query (r, mid+1, e, i, j));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;

    build (1, 1, n);

    while (q--)
    {
        int t; cin >> t;
        if (t == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            ++l;
            update (1, 1, n, l, r, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            ++l;
            cout << query (1, 1, n, l, r) << endl;
        }
    }
    
    return 0;
}