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
const ll mod = 28722900390631; // 1000000007;
// 28722900390631
const int inf = 1e18 + 19;
const int MX = 200015;
const int pi = acos(-1.0);
const ll seed = 997;
// 769 919 647 839

string s;
int isPal[5001][5001];
int preSum[5001][5001];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    cin >> s;

    mem(isPal, 0);
    mem(preSum, 0);

    int n = s.length();

    fr(i, 0, n)
    {
        ll frd = 0, bck = 0, base = 1;
        fr(j, i, s.length())
        {
            frd = (frd + s[j] * base) % mod;
            bck = (bck * seed + s[j]) % mod;
            base = (base * seed) % mod;

            if (frd == bck)
            {
                // cout << i << " " << j << endl;
                isPal[i + 1][j + 1] = 1;
            }
        }
    }

    ifr(i, 1, n)
    {
        ifr(j, 1, n)
        {
            preSum[i][j] = (isPal[i][j] + preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1]);
            // cout << preSum[i][j] << " ";
        }
        // cout << endl;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << preSum[r][r] - preSum[l - 1][r] << endl;
    }

    return 0;
}
