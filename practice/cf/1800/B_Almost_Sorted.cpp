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
int Set(int N, int pos) { return N = N | (1LL << pos); }
int reset(int N, int pos) { return N = N & ~(1LL << pos); }
bool check(int N, int pos) { return (bool)(N & (1LL << pos)); }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

int ara[mx];

void init(int n)
{
    ifr(i, 1, n)
    {
        ara[i] = i;
    }
}

bool solve(int n, int k)
{
    rfr(i, 62, 0)
    {
        int co = (1LL << i);

        if (co < k)
        {
            int start = n - i - 1, en = -1, cnt = 0;
            if (start <= 0 || start > n)
            {
                return false;
            }

            k -= co;
            int left = n - start;
            int idf = left;
            // cout << "n->" << n << " s->" << start << " l->" << left << endl;

            ifr(j, 1, left)
            {

                int cur = left - j - 1 >= 0 ? (1LL << (left - j - 1)) : 1;

                if (cur + cnt < k)
                {
                    cnt += cur;
                }
                else
                {
                    // cout << cnt << " " << j << endl;
                    idf = j;
                    break;
                }
            }

            k -= cnt;
            en = start + idf;

            // cout << "co->" << co << " k->" << k << " i->" << i << " s->" << start
            //      << " e->" << en << " cnt->" << cnt << endl;

            if (en > n || en < 0)
            {
                return false;
            }

            while (start <= en)
            {
                swap(ara[start], ara[en]);
                start++;
                en--;
            }
        }
    }

    return k <= 1;
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
        int n, k;
        cin >> n >> k;

        init(n);
        bool res = solve(n, k);

        if (!res)
        {
            cout << -1 << endl;
        }
        else
        {
            ifr(i, 1, n)
            {
                cout << ara[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
