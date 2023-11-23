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
ll gcd(ll a, ll b) { b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

#define MAXN 200005

int sizeSet[MAXN], parent[MAXN];

void initSet(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sizeSet[i] = 1;
    }
}

int findSet(int i)
{
    if (parent[i] == i)
        return i;

    return parent[i] = findSet(parent[i]);
}

bool isSameset(int i, int j)
{
    return (findSet(i) == findSet(j));
}

void unionSet(int i, int j)
{
    int a = findSet(j);
    int b = findSet(i);

    if (a == b)
        return;

    if (sizeSet[a] >= sizeSet[b])
    {
        sizeSet[a] += sizeSet[b];
        parent[b] = a;
    }
    else
    {
        sizeSet[b] += sizeSet[a];
        parent[a] = b;
    }
}

vector<piii> v[2];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        fr(i, 0, m)
        {
            int a, b, c;
            cin >> a >> b >> c;

            if (c > k)
            {
                v[0].pb({c, {a, b}});
            }
            else
            {
                v[1].pb({c, {a, b}});
            }
        }

        sort_all(v[0]);
        sort_all(v[1]);
        rev_all(v[1]);
        initSet(n);

        int cluster = n, ans = mod;
        for (auto u : v[1])
        {
            if (!isSameset(u.se.fi, u.se.se))
            {
                unionSet(u.se.fi, u.se.se);
                cluster--;
            }
        }

        if (cluster == 1)
        {
            ans = k - v[1][0].fi;

            if (v[0].size() > 0)
            {
                ans = min(ans, v[0][0].fi - k);
            }
        }
        else
        {
            ans = 0;
            for (auto u : v[0])
            {
                if (!isSameset(u.se.fi, u.se.se))
                {
                    unionSet(u.se.fi, u.se.se);
                    cluster--;
                    ans += u.fi - k;
                }
            }
        }

        cout << ans << endl;

        v[0].clear();
        v[1].clear();
    }
    return 0;
}
