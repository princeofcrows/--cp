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
#define mx 400015
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

bool isPrime[mx];
int a[mx];
si notUsed;
vi g[mx];

void nonPrimeGen()
{
    mem(isPrime, true);
    isPrime[0] = isPrime[1] = false;
    fr(i, 2, mx)
    {
        if (isPrime[i])
        {
            for (int j = i + i; j < mx; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int32_t main()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, mx); // distribution in range [1, 6]
    // rin();
    // wrout();
    fst;
    srand(time(0));
    nonPrimeGen();

    int t;
    sild(t);

    while (t--)
    {
        int n;
        sild(n);

        ifr(i, 1, 2 * n)
        {
            notUsed.insert(i);
            g[i].clear();
        }

        fr(i, 1, n)
        {
            int u, v;
            sild(u);
            sild(v);
            g[u].pb(v);
            g[v].pb(u);
        }

        ifr(i, 1, n) a[i] = 0;

        a[1] = 1;
        queue<int> q;
        q.push(1);
        notUsed.erase(1);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            int x = a[v];
            bool done = true;

            for (auto u : g[v])
            {
                if (a[u] != 0)
                {
                    continue;
                }

                bool isOk = false;
                fr(l, 0, 100)
                {
                    int _y = ((rand() * 3478561) % (2 * n)) + 1;
                    auto py = notUsed.lower_bound(_y);
                    if (py == notUsed.end())
                        continue;
                    int y = (*py);

                    if (!isPrime[llabs(x - y)] && notUsed.count(y))
                    {

                        a[u] = y;
                        isOk = true;
                        break;
                    }
                }
                if (!isOk)
                {
                    done = false;
                    break;
                }

                notUsed.erase(a[u]);
                q.push(u);
            }

            if (!done)
            {
                break;
            }
        }

        bool found = true;
        ifr(i, 1, n)
        {
            if (a[i] == 0)
            {
                found = false;
                break;
            }
        }

        if (!found)
        {
            printf("-1\n");
        }
        else
        {
            ifr(i, 1, n)
            {
                printf("%lld ", a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
