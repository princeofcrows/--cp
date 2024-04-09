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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int a, b, k;
    cin >> a >> b >> k;
    swap(a, b);

    if (a == 1)
    {
        if (k == 0)
        {
            cout << "Yes\n1";
            fr(i, 0, b) cout << 0;
            cout << "\n";
            cout << "1";
            fr(i, 0, b) cout << 0;
            cout << "\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    else
    {
        if (b == 0 && k != 0)
        {
            cout << "No\n";
        }
        else if (b >= k)
        {
            string x = "", y = "";

            int lft = b - k;
            fr(i, 0, lft)
            {
                x += "0";
                y += "0";
            }

            y += "1";

            fr(i, 0, k)
            {
                x += "0";
                y += "0";
            }

            x += "1";

            fr(i, 1, a)
            {
                x += "1";
                y += "1";
            }

            rev_all(x);
            rev_all(y);

            cout << "Yes\n";
            cout << x << "\n"
                 << y << "\n";
        }
        else if (b + a - 2 >= k)
        {
            string x = "", y = "";
            y += "1";
            x += "0";

            int lft = k - b;
            fr(i, 1, b)
            {
                x += "0";
                y += "0";
            }

            fr(i, 0, lft)
            {
                x += "1";
                y += "1";
            }

            y += "0";
            x += "1";

            int lft1 = a - lft - 1;
            fr(i, 0, lft1)
            {
                x += "1";
                y += "1";
            }

            rev_all(x);
            rev_all(y);

            cout << "Yes\n";
            cout << x << "\n"
                 << y << "\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
