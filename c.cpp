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

int N, A, C;
map<int, vector<int>> mp;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A >> C;
        mp[C].push_back(A);
    }
    int ans = 1;
    for (auto [k, v] : mp)
    {
        sort(v.begin(), v.end());
        chmax(ans, v[0]);
    }
    cout << ans << '\n';
}
