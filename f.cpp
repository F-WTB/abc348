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

int N, M, A[2000][2000];
bool cnt[2000][2000];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < M; ++k)
            cin >> A[k][i];

    for (int k = 0; k < M; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (A[k][i] == A[k][j])
                    cnt[i][j] ^= 1;

    int ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (cnt[i][j])
                ++ans;
    cout << ans << '\n';
}
