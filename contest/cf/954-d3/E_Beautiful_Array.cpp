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
#define mx 100015
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

map<int, int> mp;
si st[mx];

void solve(int k, int c)
{
    int te = 0, ans = 0;
    for (int i = 1; i <= c; i++)
    {
        int sz = ((int)st[i].size());

        // cout << sz << " " << i << endl;
        if (sz % 2)
        {
            te++;

            if (te > 1)
            {
                break;
            }

            vi v, p(sz + 1, 0), s(sz + 1, 0);
            for (auto u : st[i])
            {
                v.pb(u);
            }
            sort_all(v);

            // for (auto u : v)
            //     cout << u << " ";

            for (int j = 1; j < sz; j += 2)
            {
                p[j] = v[j] - v[j - 1];
                p[j] += p[j - 1];
                p[j + 1] = p[j];
            }

            for (int j = sz - 1; j >= 0; j -= 2)
            {
                s[j] = v[j] - v[j - 1];
                s[j] += s[j + 1];
                if (j - 1 >= 0)
                {
                    s[j - 1] = s[j];
                }
            }

            int x = inf;
            for (int j = 0; j <= sz; j += 2)
            {
                int a = j ? p[j - 1] : 0;
                int b = j + 1 > sz ? 0 : s[j + 1];

                // cout << j << " " << a << " " << b << endl;

                x = min(x, a + b);
            }

            if (x == inf)
            {
                x = 0;
            }

            ans += x;
        }
        else
        {
            vi v;
            for (auto u : st[i])
            {
                v.pb(u);
            }

            sort_all(v);

            for (int j = 1; j < v.size(); j += 2)
            {
                ans += (v[j] - v[j - 1]);
            }
        }
    }

    if (te > 1)
    {
        cout << -1 << "\n";
    }
    else
    {
        // ans = (ans * k);
        cout << ans << "\n";
    }

    fr(i, 1, c) st[i].clear();
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
        int n, k, c = 1;
        cin >> n >> k;

        fr(i, 0, n)
        {
            int a;
            cin >> a;

            int r = (a % k);
            int d = (a / k);

            // cout << r << " " << a << endl;
            if (!mp[r])
            {
                mp[r] = c;
                st[c].clear();
                // cout << "--" << r << " " << c << endl;
                c++;
            }

            int x = mp[r];

            if (st[x].count(d))
            {

                st[x].erase(d);
            }
            else
            {
                st[x].insert(d);
            }
        }

        solve(k, c);

        mp.clear();
    }
    return 0;
}
