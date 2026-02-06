#include <bits/stdc++.h>

using namespace std;

// Data type
// #define int long long
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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

// Const
const int mod = 1000000007;
// 28722900390631
const int inf = 1e18 + 19;
const int MX = 2000015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

int r[MX], dp[5005], cnt[5005];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n, m;
    cin >> n >> m;

    fr(i, 0, n)
    {
        cin >> r[i];
    }

    r[n] = 0;
    mem(dp, 0);
    mem(cnt, 0);

    int tot = 0, ans = 0;
    ifr(i, 0, n)
    {
        if (r[i] == 0)
        {
            ifr(i, 1, m)
            {
                cnt[i] += cnt[i - 1];
            }

            ifr(i, 0, m)
            {
                dp[i] += cnt[i];
            }

            rfr(i, m + 1, 1)
            {
                dp[i] = max(dp[i], dp[i - 1]);
            }

            ifr(i, 0, m)
            {
                cnt[i] = 0;
            }
            tot++;
        }
        else if (r[i] > 0)
        {
            if (r[i] > tot)
            {
                continue;
            }
            cnt[r[i]] += 1;
            cnt[tot + 1] -= 1;
        }
        else
        {
            int need = tot + r[i];
            if (need < 0)
            {
                continue;
            }
            cnt[0] += 1;
            cnt[need + 1] -= 1;
        }
    }

    ifr(i, 0, m) ans = max(ans, dp[i]);

    cout << ans << endl;
    return 0;
}
