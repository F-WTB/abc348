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
int N, X[100], Y[100];

int c(int i, int j)
{
    return (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> X[i] >> Y[i];

    for (int i = 0; i < N; ++i)
    {
        int idx = 0;
        for (int j = 0; j < N; ++j)
            if (c(j, i) > c(idx, i))
                idx = j;
        cout << idx + 1 << '\n';
    }
}
