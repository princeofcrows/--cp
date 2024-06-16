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

string res[55];
int col[55];

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, a, b;
        bool isFlipped = false;
        cin >> n >> m >> a >> b;

        if (n < m)
        {
            swap(n, m);
            swap(a, b);
            isFlipped = true;
        }

        if (n * a != m * b)
        {
            no();
            continue;
        }

        string str = "";

        fr(i, 0, m)
        {
            if (i < a)
            {
                str += "1";
            }
            else
            {
                str += "0";
            }
        }

        bool isOkay = false;

        fr(shift, 1, m + 1)
        {

            mem(col, 0);
            fr(i, 0, n)
            {
                fr(j, 0, m)
                {
                    col[j] += (str[j] - '0');
                }

                res[i] = str;
                // cout << "-----" << str << endl;
                fr(l, 0, shift)
                {
                    char ch = str.back();
                    str.pop_back();
                    str = ch + str;
                }

                // cout << str << endl;
            }

            isOkay = true;
            fr(i, 0, m)
            {
                if (col[i] != b)
                {
                    isOkay = false;
                    break;
                }
            }

            if (isOkay)
            {
                break;
            }
        }

        if (isOkay)
        {
            yes();
            if (!isFlipped)
            {
                fr(i, 0, n) { cout << res[i] << "\n"; }
            }
            else
            {
                fr(i, 0, m)
                {
                    fr(j, 0, n)
                    {
                        cout << res[j][i];
                    }
                    cout << "\n";
                }
            }
        }
        else
        {
            no();
        }
    }
    return 0;
}
