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
ll gcd(ll a, ll b) { return b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

// random
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int ara[mx], cnt[mx];

void init(int n)
{
    fr(i, 0, n + 1) cnt[i] = 0;
}

bool check(int diff, int n, int k)
{
    ifr(i, 1, n - diff)
    {
        int tot = cnt[i + diff] - cnt[i - 1];
        int rest = n - tot;

        if (tot - rest >= k)
        {
            return true;
        }
    }

    return false;
}

void print(int n, int k, int diff)
{
    int x, y;
    ifr(i, 1, n - diff)
    {
        int tot = cnt[i + diff] - cnt[i - 1];
        int rest = n - tot;

        if (tot - rest >= k)
        {
            x = i;
            y = i + diff;
            break;
        }
    }

    cout << x << " " << y << endl;

    int in = 0, out = 0, partCnt = 0, last = 1;
    fr(i, 0, n)
    {
        if (partCnt + 1 == k)
        {
            cout << last << " " << n << "\n";
            break;
        }

        if (ara[i] >= x && ara[i] <= y)
        {
            in++;
        }
        else
        {
            out++;
        }

        if (in > out)
        {
            cout << last << " " << i + 1 << "\n";

            in = out = 0;
            partCnt++;
            last = i + 2;
        }
    }
}

void solve(int n, int k)
{
    int l = 0, h = n;

    ifr(i, 1, n) cnt[i] += cnt[i - 1];

    while (l <= h)
    {
        int m = (l + h) / 2;

        if (check(m, n, k))
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    print(n, k, l);
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        init(n);
        fr(i, 0, n)
        {
            cin >> ara[i];
            cnt[ara[i]]++;
        }

        solve(n, k);
    }
    return 0;
}
