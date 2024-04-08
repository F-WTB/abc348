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
int H, W, N, R, C, E[200][200];
pr s, t;
string A[200];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
bool inner(int x, int y) { return 0 <= x && x < H && 0 <= y && y < W && A[x][y] != '#'; }
bool inner(pr r) { return inner(r.first, r.second); }
pr next(int x, int y, int k) { return make_pair(x + dx[k], y + dy[k]); }
pr next(pr r, int k) { return next(r.first, r.second, k); }

int u[200][200];

int main()
{
    cin >> H >> W;
    fill(u[0], u[H], -1);
    for (int i = 0; i < H; ++i)
        cin >> A[i];
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
        {
            if (A[i][j] == 'S')
                s = make_pair(i, j);
            if (A[i][j] == 'T')
                t = make_pair(i, j);
        }

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> R >> C;
        --R, --C;
        cin >> E[R][C];
    }

    queue<pr> q;
    q.push(s);
    u[s.first][s.second] = E[s.first][s.second];

    while (q.size())
    {
        pr r = q.front();
        q.pop();
        auto [x, y] = r;

        cerr << x << ',' << y << ':' << u[x][y] << '\n';

        if (r == t)
        {
            cout << "Yes" << '\n';
            return 0;
        }
        if (!u[x][y])
            continue;
        for (int k = 0; k < 4; ++k)
        {
            pr nr = next(r, k);
            if (!inner(nr))
                continue;
            auto [nx, ny] = nr;
            int nu = max(E[nx][ny], u[x][y] - 1);
            if (nu > u[nx][ny])
            {
                u[nx][ny] = nu;
                q.push(nr);
            }
        }
    }

    cout << "No\n";
}
