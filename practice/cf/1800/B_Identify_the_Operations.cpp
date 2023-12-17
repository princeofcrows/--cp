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
#define mod 998244353
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

int a[mx], b[mx], id[mx], fu[mx];
set<pii> st[2];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, ans = 1;
        cin >> n >> k;

        fr(i, 0, n)
        {
            cin >> a[i];

            st[0].insert({i, a[i]});
            st[1].insert({-i, a[i]});

            id[a[i]] = i;

            fu[i] = fu[i + 1] = 0;
        }
        fr(i, 0, k)
        {
            cin >> b[i];
            fu[b[i]] = 1;
        }

        fr(i, 0, k)
        {
            fu[b[i]] = 0;
            set<pii>::iterator be = st[0].upper_bound({id[b[i]], b[i]});
            set<pii>::iterator ne = st[1].upper_bound({-id[b[i]], b[i]});

            int cnt = 0;

            if (be != st[0].end())
            {
                int x = (*be).second;
                // cout << "be " << x << endl;

                if (!fu[x])
                {
                    cnt++;
                    st[0].erase(be);
                }
            }

            if (ne != st[1].end())
            {
                int x = (*ne).second;
                // cout << "ne " << x << endl;

                if (!fu[x])
                {
                    cnt++;
                    st[1].erase(ne);
                }
            }

            if (cnt == 2)
            {
                st[0].insert({(*be).first, (*be).second});
                st[1].insert({-(*be).first, (*be).second});
            }

            ans = (ans * cnt) % mod;
        }

        st[0].clear();
        st[1].clear();
        cout << ans << endl;
    }
    return 0;
}
