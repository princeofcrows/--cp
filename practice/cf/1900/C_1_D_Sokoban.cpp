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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

int a[mx], b[mx];

int solve(int n, int m)
{
    int curr = 0, over_lap = 0, ans_p = 0, ans_n = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;

    fr(i, 0, n)
    {
        if (a[i] > 0)
        {
            q.push({a[i], 0});
        }
    }
    fr(i, 0, m)
    {
        if (b[i] > 0)
        {
            q.push({b[i], 1});
            if (binary_search(a, a + n, b[i]))
            {
                over_lap++;
            }
        }
    }

    vi v;
    while (!q.empty())
    {
        auto p = q.top();
        q.pop();

        if (p.se == 0)
        {
            curr++;
        }
        else if (p.se == 1)
        {
            v.pb(p.fi);

            if (binary_search(a, a + n, p.fi))
            {
                over_lap--;
            }

            int idx = upper_bound(v.begin(), v.end(), p.fi - curr) - v.begin();
            int current_ans = over_lap + (int)v.size() - idx;
            ans_p = max(ans_p, current_ans);

            // cout << (int)v.size() - idx << " " << over_lap << " " << p.fi << endl;
        }
    }

    curr = 0, over_lap = 0;

    fr(i, 0, n)
    {
        if (a[i] < 0)
        {
            q.push({-a[i], 0});
        }
    }
    fr(i, 0, m)
    {
        if (b[i] < 0)
        {
            q.push({-b[i], 1});
            if (binary_search(a, a + n, b[i]))
            {
                over_lap++;
            }
        }
    }

    v.clear();
    while (!q.empty())
    {
        auto p = q.top();
        q.pop();

        if (p.se == 0)
        {
            curr++;
        }
        else if (p.se == 1)
        {
            v.pb(p.fi);

            if (binary_search(a, a + n, -p.fi))
            {
                over_lap--;
            }

            int idx = upper_bound(v.begin(), v.end(), p.fi - curr) - v.begin();
            int current_ans = over_lap + (int)v.size() - idx;
            ans_n = max(ans_n, current_ans);

            // cout << (int)v.size() - idx << " " << over_lap << " " << p.fi << endl;
        }
    }

    return ans_p + ans_n;
}

void take_input(int n, int m)
{
    fr(i, 0, n)
    {
        cin >> a[i];
    }

    fr(i, 0, m)
    {
        cin >> b[i];
    }
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
        int n, m, ans = 0;
        cin >> n >> m;
        take_input(n, m);

        cout << solve(n, m) << endl;
    }
    return 0;
}
