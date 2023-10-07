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

// Const
#define mod 1000000007
// 28722900390631
#define inf 1e18 + 19
#define mx 4000015
#define pi acos(-1.0)
#define seed 997
// 769 919 647 839

// Input Output
#define sild(x) scanf("%lld", &x)
#define sid(x) scanf("%d", &x)
#define rin() freopen("back_in_black_chapter_1_input.txt", "r", stdin)
#define wrout() freopen("out_C1.txt", "w", stdout)
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
// mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

vi pr[mx];

void sieve()
{

    ifr(i, 1, mx - 1)
    {
        for (int j = i; j < mx; j += i)
        {
            pr[j].pb(i);
        }
    }
}

string str;
mii mp;

int32_t main()
{
    rin();
    wrout();
    fst;

    int t, cs = 1;
    sid(t);

    sieve();

    while (t--)
    {
        int n, q;
        cin >> n >> str >> q;

        fr(i, 0, q)
        {
            int b;
            cin >> b;

            mp[b]++;
        }

        int ans = 0;
        ifr(i, 1, n)
        {
            int cnt = 0;
            for (auto u : pr[i])
            {
                cnt += mp[u];
            }

            if (str[i - 1] == '0')
            {
                if (cnt % 2)
                {
                    ans++;
                    mp[i]++;
                }
            }
            else
            {
                if (cnt % 2 == 0)
                {
                    ans++;
                    mp[i]++;
                }
            }
        }

        printf("Case #%d: %d\n", cs++, ans);
        mp.clear();
    }
    return 0;
}
