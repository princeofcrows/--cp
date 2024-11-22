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
#define mx 1000015
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

string str;
int tot[mx], ones[mx];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, ans = mod, sum = 0;
        cin >> n >> k >> str;

        fr(i, 0, n) sum += (int)(str[i] - '0');

        fr(i, 0, k)
        {
            vi dp1((n + k - 1) / k + 1, 0);
            vi dp0((n + k - 1) / k + 1, 0);
            int totOne = 0, res = mod, last = 0;
            for (int j = i, l = 0; j < n; j += k, l++)
            {
                int isCur = 0;
                if (str[j] == '1')
                {
                    totOne++;
                    isCur = 1;
                }

                dp0[l + 1] = dp0[l] + isCur;
                dp1[l + 1] = min(dp1[l], dp0[l]) + (1 - isCur);
                last = l;
            }

            int co = sum - totOne;
            for (int l = 0; l <= last; l++)
            {
                int curr = dp1[l + 1] + dp0[last + 1] - dp0[l + 1];
                ans = min(ans, curr + co);
            }

            ans = min(ans, dp0[last + 1] + co);
        }

        cout << ans << "\n";
    }
    return 0;
}
