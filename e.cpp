#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x)
{
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
struct fast
{
    fast()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;
int N, A, B, C[100000];
vector<int> g[100000];

int d[100000];
ll s = 0, w[100000];

void dfs(int v, int p)
{
    for (int nv : g[v])
    {
        if (nv == p)
            continue;
        d[nv] = d[v] + 1;
        dfs(nv, v);
        w[v] += w[nv];
    }
}

ll f0 = 0;
ll x = 0, c = 0;
void dfs2(int v, int p)
{
    chmin(x, c);
    for (int nv : g[v])
    {
        if (nv == p)
            continue;
        ll t = -w[nv] + (s - w[nv]);
        c += t;
        dfs2(nv, v);
        c -= t;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> A >> B;
        --A, --B;
        g[A].push_back(B);
        g[B].push_back(A);
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> C[i];
        s += C[i];
    }

    for (int i = 0; i < N; ++i)
        w[i] = C[i];

    dfs(0, 0);

    for (int i = 0; i < N; ++i)
        f0 += (ll)d[i] * C[i];

    dfs2(0, 0);
    cout << f0 + x << '\n';
}
