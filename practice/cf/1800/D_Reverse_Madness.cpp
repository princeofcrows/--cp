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
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

int l[mx], r[mx], x[mx];
string str;

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> str;

        fr(i, 0, k) cin >> l[i];
        fr(i, 0, k) cin >> r[i];

        cin >> q;

        fr(i, 0, q) cin >> x[i];

        sort(x, x + q);
        vi v(n + 5, 0);

        int idx = 0;
        fr(i, 0, q)
        {
            if (x[i] >= l[idx] && x[i] <= r[idx])
            {
                int a = min(x[i], r[idx] - x[i] + l[idx]);
                int b = max(x[i], r[idx] - x[i] + l[idx]);

                v[a]++;
                v[b + 1]--;
            }
            else
            {
                idx++;
                i--;
            }
        }

        ifr(i, 1, n) v[i] += v[i - 1];

        fr(i, 0, k)
        {
            int left = l[i], right = r[i];
            while (left <= right)
            {
                if (v[left] % 2)
                {
                    swap(str[left - 1], str[right - 1]);
                }

                left++;
                right--;
            }
        }

        cout << str << endl;
    }
    return 0;
}
