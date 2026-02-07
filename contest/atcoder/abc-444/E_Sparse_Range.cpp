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
const int MX = 400015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

#define MAXN 400005
#define K 24
using namespace std;

int table[MAXN][K], ara[MAXN];

int callBackFn(int a, int b)
{
    return min(a, b);
}

void initSparseTable(int n)
{
    fr(i, 0, K) fr(j, 0, MAXN) table[j][i] = mod;

    for (int i = 0; i < n; i++)
    {
        table[i][0] = ara[i];
    }

    for (int j = 1; j <= K; j++)
    {
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = callBackFn(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }
}

int query(int L, int R)
{
    int ans = mod;
    for (int j = K; j >= 0; j--)
    {
        if (L + (1 << j) - 1 <= R)
        {
            ans = callBackFn(ans, table[L][j]);
            L += 1 << j;
        }
    }
    return ans;
}

int a[MX];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int n, d;
    cin >> n >> d;

    fr(i, 0, n)
    {
        cin >> a[i];
    }

    si s;
    mii mp;
    int cur = 0;

    fr(i, 0, n)
    {
        if (cur < i)
            cur = i;
        while (cur < n)
        {

            auto it = s.upper_bound(a[cur]);

            if (it != s.end())
            {
                int diff = abs(a[cur] - (*it));

                if (diff < d)
                    break;
            }

            if (it != s.begin())
            {
                --it;
                int diff = abs(a[cur] - (*it));

                if (diff < d)
                    break;
            }

            s.insert(a[cur]);
            mp[a[cur]]++;
            cur++;
        }

        ara[i] = cur;
        mp[a[i]]--;
        if (mp[a[i]] == 0)
            s.erase(a[i]);
    }

    // fr(i, 0, n) cout << ara[i] << " ";

    initSparseTable(n);

    ll ans = 0;

    fr(i, 0, n)
    {
        int x = query(i, n - 1);

        ans += (x - i);
    }

    cout << ans << endl;
    return 0;
}
