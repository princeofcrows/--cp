#include <bits/stdc++.h>

using namespace std;

// Data type
#define int long long
#define ll long long
#define pii pair<int, int>
#define piii pair<int, pii>
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pii>
#define mii map<int, int>
#define msi map<string, int>
#define si set<int>
#define spi set<pii>

// Method or var shorthands
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define sort_all(v) sort(all(v));
#define rev_all(v) reverse(all(v));
#define mem(ara, x) memset(ara, x, sizeof ara)

// Const
#define mod 1000000007
// 28722900390631
#define inf 1e18 + 19
#define mx 200015
#define pi acos(-1.0)
#define seed 997
// 769 919 647 839

// Input Output
#define sild(x) scanf("%lld", &x)
#define sid(x) scanf("%d", &x)
#define rin() freopen("in.txt", "r", stdin)
#define wrout() freopen("out.txt", "w", stdout)
#define fst                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// Loops
#define fr(i, s, e) for (int i = s; i < e; i++)
#define ifr(i, s, e) for (int i = s; i <= e; i++)
#define rfr(i, e, s) for (int i = e - 1; i >= s; i--)

// Functions
ll gcd(ll a, ll b) { b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

int dp[2][mx][2], x[mx], n;

int solve_min(int idx, int last)
{
    if (idx > n)
    {
        return last;
    }
    if (dp[0][idx][last] != -1)
    {
        return dp[0][idx][last];
    }

    int ret = 0;

    if (last)
    {
        ret = solve_min(idx + 2, 0) + 1;
        ret = min(ret, solve_min(idx + 1, 0) + 1);

        if (x[idx])
        {
            ret = min(ret, solve_min(idx + 1, 1) + 1);
        }
    }
    else
    {
        if (x[idx])
        {
            if (x[idx + 1])
            {
                ret = solve_min(idx + 2, 0) + 1;
                ret = min(ret, solve_min(idx + 1, 1));
            }
            else
            {
                ret = solve_min(idx + 1, 0) + 1;
                ret = min(ret, solve_min(idx + 1, 1));
            }
        }
        else
        {
            ret = solve_min(idx + 1, 0);
        }
    }

    // cout << idx << " " << last << " " << ret << endl;
    return dp[0][idx][last] = ret;
}

int solve_max(int idx, int last)
{
    if (idx > n + 1)
    {
        return 0;
    }
    if (dp[1][idx][last] != -1)
    {
        return dp[1][idx][last];
    }

    int ret = 0;

    if (!last)
    {
        if (x[idx + 1] == 0)
        {
            if (x[idx] >= 3)
            {
                ret = solve_max(idx + 2, 1) + 3;
            }
            else if (x[idx] == 2)
            {
                ret = solve_max(idx + 1, 1) + 2;
            }
            else if (x[idx] == 1)
            {
                ret = solve_max(idx + 1, 0) + 1;
            }
            else
            {
                ret = solve_max(idx + 1, 0);
            }
        }
        else
        {
            if (x[idx] >= 3)
            {
                x[idx + 1]++;
                ret = solve_max(idx + 1, 1) + 2;
                x[idx + 1]--;
            }
            else if (x[idx] == 2)
            {

                ret = solve_max(idx + 1, 1) + 2;
            }
            else if (x[idx] == 1)
            {
                ret = solve_max(idx + 1, 0) + 1;
            }
            else
            {
                ret = solve_max(idx + 1, 0);
            }
        }
    }
    else
    {
        if (x[idx] == 1)
        {
            ret = solve_max(idx + 1, 1) + 1;
        }
        else if (x[idx] >= 2)
        {
            if (x[idx + 1] == 0)
            {
                ret = solve_max(idx + 2, 1) + 2;
            }
            else
            {
                x[idx + 1]++;
                ret = solve_max(idx + 1, 1) + 1;
                x[idx + 1]--;
            }
        }
        else
        {
            ret = solve_max(idx + 1, 0);
        }
    }

    return dp[1][idx][last] = ret;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;
    mem(dp, -1);
    mem(x, 0);

    cin >> n;
    fr(i, 0, n)
    {
        int a;
        cin >> a;
        x[a]++;
    }

    cout << solve_min(1, 0) << " " << solve_max(1, 0) << endl;
    return 0;
}
