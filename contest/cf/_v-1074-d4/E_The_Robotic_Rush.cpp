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
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
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

int a[MX], b[MX], ind[MX];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k; cin >> n >> m >> k;
        fr(i, 0, n) cin >> a[i];
        fr(i, 0, m) cin >> b[i];

        sort(b, b + m);

        priority_queue <pii, vpi, greater<pii>> left, right;
        fr(i, 0, n) {
            int up = upper_bound(b, b + m, a[i]) - b;

            if (up >= m)left.push({ inf, i });
            else left.push({ b[up] - a[i], i });

            if (up <= 0)right.push({ inf, i });
            else right.push({ a[i] - b[up - 1], i });

            ind[i] = 1;
        }

        string s; cin >> s;

        int pos = 0, _min = MX, _max = -MX, cur = n;
        for (auto c : s) {
            if (c == 'R') pos++;
            else pos--;

            _min = min(_min, pos);
            _max = max(_max, pos);

            //cout << _min << " " << _max << endl;

            while (!left.empty() && left.top().fi <= _max)
            {
                auto idx = left.top().se;
                if (ind[idx]) {
                    cur--;
                    ind[idx] = 0;
                }

                //cout << left.top().se << " " << left.top().fi << endl;
                left.pop();
            }

            while (!right.empty() && right.top().fi <= -_min)
            {
                auto idx = right.top().se;
                if (ind[idx]) {
                    cur--;
                    ind[idx] = 0;
                }

                //cout << right.top().se << " " << right.top().fi << endl;
                right.pop();
            }

            cout << cur << " ";
        }
        cout << endl;
    }
    return 0;
}
