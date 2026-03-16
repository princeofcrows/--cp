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

int a[MX];
map<int, vi> mp;
si s;

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

        fr(i, 0, n)
        {
            cin >> a[i];
            mp[a[i] % k].pb(a[i]);
            s.insert(a[i] % k);
        }

        int ans = 0;
        int isPos = 0;
        for (auto u : s)
        {
            auto v = mp[u];
            sort(v.begin(), v.end());

            vi cur, _cur;
            int tmp = 0;
            for (int i = 1; i < (int)v.size(); i += 2)
            {
                cur.pb((v[i] - v[i - 1]) / k);
                if (cur.size() > 1)
                {
                    cur[(int)cur.size() - 1] += cur[(int)cur.size() - 2];
                }
            }

            isPos += (((int)v.size()) % 2);

            if (((int)v.size()) % 2 && v.size() > 1)
            {
                for (int i = 2; i < (int)v.size(); i += 2)
                {
                    _cur.pb((v[i] - v[i - 1]) / k);
                }

                rfr(i, ((int)_cur.size()) - 1, 0)
                {
                    _cur[i] += _cur[i + 1];
                }

                for (int i = 0; i < (int)cur.size(); i++)
                {
                    if (i == 0)
                    {
                        tmp = _cur[i];
                    }
                    else
                    {
                        tmp = min(cur[i - 1] + _cur[i], tmp);
                    }
                }

                tmp = min(tmp, cur.back());
            }
            else if (v.size() > 1)
            {
                tmp = cur.back();
            }

            ans += tmp;
        }

        if (isPos > 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }

        mp.clear();
        s.clear();
    }
    return 0;
}
