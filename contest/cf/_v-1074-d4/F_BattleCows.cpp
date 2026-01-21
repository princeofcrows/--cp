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
int Set(int N, int pos) { return N = N | (1LL << pos); }
int reset(int N, int pos) { return N = N & ~(1LL << pos); }
bool check(int N, int pos) { return (bool)(N & (1LL << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

// Const
const int mod = 1000000007;
// 28722900390631
const int inf = 1e18 + 19;
const int MX = 200015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

vi g[22];
int a[(1LL << 20)];

void init(int id) {
    if (id == 0) return;
    if (g[id - 1].size() <= 1) return;

    for (int i = 0; i < g[id - 1].size(); i += 2) {
        int x = g[id - 1][i] ^ g[id - 1][i + 1];
        //cout << x << "-- ";
        g[id].pb(x);
    }

    init(id + 1);
}

int update(int n, int idx, int val) {
    int before = 0, cur = idx;

    ifr(i, 1, n) {
        int other = (cur % 2 ? cur - 1 : cur + 1);

        if (val > g[i - 1][other]) {

        }
        else if (g[i - 1][other] > val) {
            before += (1LL << (i - 1));
        }
        else {
            if (cur > other) before += (1LL << (i - 1));
        }

        val = g[i - 1][other] ^ val;
        cur = min(other, cur) / 2;

        //  cout << val << " " << cur << endl;
    }

    return before;
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
        int n, q; cin >> n >> q;

        fr(i, 0, (1LL << n)) {
            cin >> a[i];
            g[0].pb(a[i]);
        }

        init(1);

        // fr(i, 0, n + 1) {
        //     for (auto u : g[i]) cout << u << " ";
        //     cout << endl;
        // }

        while (q--)
        {
            int b, c;
            cin >> b >> c;

            cout << update(n, b - 1, c) << endl;
        }

        ifr(i, 0, 20) g[i].clear();
    }
    return 0;
}
