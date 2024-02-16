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

double c, m, p, v;
double eps = 0.0000000001;

double solve()
{

    double ans = 0.0;
    fr(itr, 0, 19)
    {
        for (int i = 0; i < (1 << itr); i++)
        {
            double c_p = 1.0;
            double cc = c, cm = m, cp = p;
            bool flag = true;

            fr(j, 0, itr)
            {
                int cnt = 0;
                double diff;
                if (check(i, j))
                {
                    if (cc < eps)
                    {
                        flag = false;
                        break;
                    }
                    c_p = c_p * cc;

                    if (cc > v)
                    {
                        cc -= v;
                        diff = v;
                    }
                    else
                    {
                        diff = cc;
                        cc = 0.0;
                    }

                    if (cm > eps)
                    {
                        cnt++;
                    }
                    if (cp > eps)
                    {
                        cnt++;
                    }

                    double x = diff / (cnt * 1.0);
                    if (cm > eps)
                    {
                        cm += x;
                    }
                    if (cp > eps)
                    {
                        cp += x;
                    }
                }
                else
                {
                    if (cm < eps)
                    {
                        flag = false;
                        break;
                    }
                    c_p = c_p * cm;
                    if (cm > v)
                    {
                        cm -= v;
                        diff = v;
                    }
                    else
                    {
                        diff = cm;
                        cm = 0.0;
                    }

                    if (cc > eps)
                    {
                        cnt++;
                    }
                    if (cp > eps)
                    {
                        cnt++;
                    }

                    double x = diff / (cnt * 1.0);
                    if (cc > eps)
                    {
                        cc += x;
                    }
                    if (cp > eps)
                    {
                        cp += x;
                    }
                }
            }

            if (flag)
            {
                ans = (ans + c_p * cp * ((itr + 1) * 1.0));
            }
        }
    }

    return ans;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int t;
    cin >> t;

    while (t--)
    {
        cin >> c >> m >> p >> v;

        cout << fixed;
        cout << setprecision(12) << solve() << endl;
    }
    return 0;
}
