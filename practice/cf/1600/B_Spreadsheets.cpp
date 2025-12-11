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
const int mod = 1000000007;
// 28722900390631
const int inf = 1e18 + 19;
const int MX = 200015;
const int pi = acos(-1.0);
const int seed = 997;
// 769 919 647 839

string v2_v1(string s) {
    int cur = 0;
    int col = 0;
    while (cur < s.length() && s[cur] >= 'A' && s[cur] <= 'Z')
    {
        col = (col * 26 + ((int)(s[cur] - 'A')) + 1);
        cur++;
    }

    if (cur >= s.length()) {
        return "";
    }

    string colStr = to_string(col);

    string row = "";
    while (cur < s.length() && s[cur] >= '0' && s[cur] <= '9')
    {
        if (!(s[cur] >= '0' && s[cur] <= '9')) {
            return "";
        }

        row += s[cur];
        cur++;
    }

    if (cur != s.length()) {
        return "";
    }

    return "R" + row + "C" + colStr;
}

string v1_v2(string s) {
    int cur = 0;
    if (s[cur] != 'R') {
        return "";
    }

    cur++;
    string row = "";
    while (cur < s.length() && s[cur] != 'C')
    {
        if (!(s[cur] >= '0' && s[cur] <= '9')) {
            return "";
        }
        row += s[cur];
        cur++;
    }

    if (cur >= s.length() || row == "") {
        return "";
    }

    cur++;
    int col = 0;
    while (cur < s.length())
    {
        if (!(s[cur] >= '0' && s[cur] <= '9')) {
            return "";
        }
        col = col * 10 + ((int)(s[cur] - '0'));
        cur++;
    }

    if (cur != s.length()) {
        return "";
    }

    string colStr = "";
    if (col == 0) {
        colStr = "A";
    }

    while (col)
    {
        col--;
        int rem = (col + 26) % 26;
        col /= 26;

        // rem--;
        // if (rem == -1) { rem = 26; }

        colStr += ((char)(rem + 'A'));
    }
    rev_all(colStr);
    return colStr + row;

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
        string s;
        cin >> s;

        auto v2 = v1_v2(s);

        if (v2 == "")
            cout << v2_v1(s) << endl;
        else cout << v2 << endl;
    }
    return 0;
}
