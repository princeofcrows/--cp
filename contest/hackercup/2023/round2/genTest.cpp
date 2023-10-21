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
#define mod 875168479
// 28722900390631
#define inf 1e18 + 19
#define mx 6000005
#define pi acos(-1.0)
int seed = 997;
int z[] = {997, 769, 919, 647, 839};

// Input Output
#define sild(x) scanf("%lld", &x)
#define sid(x) scanf("%d", &x)
#define rin() freopen("ready_go_part_2_validation_input.txt", "r", stdin)
#define wrout() freopen("in.txt", "w", stdout)
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
    return b ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
// bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

// random
// mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

int32_t main()
{
    // rin();
    wrout();
    fst;

    cout << 150 << endl;
    fr(i, 0, 150)
    {
        cout << 3000 << " " << 3000 << endl;
        fr(j, 0, 3000)
        {
            fr(l, 0, 3000)
            {
                int c = rand() % 3;
                if (c == 0)
                    cout << "B";
                else if (c == 1)
                    cout << "W";
                else
                    cout << ".";
            }
            cout << endl;
        }
    }
    return 0;
}
