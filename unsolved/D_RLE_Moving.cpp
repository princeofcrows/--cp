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

string st[MX], sa[MX];
int at[MX], aa[MX];

bool isSame(pii a, pii b)
{
    return a == b;
}

bool doesIntersect(pii a1, pii a2, pii b1, pii b2)
{
    if (a1.fi <= b1.fi && a2.fi >= b2.fi)
    {
        if (b1.se <= a1.se && b2.se >= a2.se)
        {
            return true;
        }
    }

    if (a1.se <= b1.se && a2.se >= b2.se)
    {
        if (b1.fi <= a1.fi && b2.fi >= a2.fi)
        {
            return true;
        }
    }

    return false;
}

int32_t main()
{
    // rin();
    // wrout();
    fst;

    int rt, ct, ra, ca, ans = 0;
    cin >> rt >> ct >> ra >> ca;

    int n, m, l;
    cin >> n >> m >> l;

    fr(i, 0, m) cin >> st[i] >> at[i];
    fr(i, 0, l) cin >> sa[i] >> aa[i];

    pii ts = {rt, ct};
    pii as = {ra, ca};
    pii te, ae;

    int idxA = 0, timeA = 0, timeT = 0;

    fr(i, 0, m)
    {
        te = ts;
        if (st[i] == "R")
        {
            te.se += at[i];
            ts.se++;
        }
        else if (st[i] == "L")
        {
            te.se -= at[i];
            ts.se--;
        }
        else if (st[i] == "D")
        {
            te.fi += at[i];
            ts.fi++;
        }
        else if (st[i] == "U")
        {
            te.fi -= at[i];
            ts.fi--;
        }

        int timeL = timeT;
        timeT += at[i];

        // cout << "T: " << ts.fi << " " << ts.se << " -- " << te.first << " " << te.se << endl;

        while (idxA < l)
        {
            ae = as;
            int plusA = aa[idxA];
            string indA = sa[idxA];

            if (aa[idxA] + timeA > timeT)
            {
                plusA = timeT - timeA;
                aa[idxA] -= plusA;
            }
            else
            {
                idxA++;
            }

            // cout << plusA << " " << timeA << " " << timeT << endl;

            if (indA == "R")
            {
                ae.se += plusA;
                as.se++;
            }
            else if (indA == "L")
            {
                ae.se -= plusA;
                as.se--;
            }
            else if (indA == "D")
            {
                ae.fi += plusA;
                as.fi++;
            }
            else if (indA == "U")
            {
                ae.fi -= plusA;
                as.fi--;
            }

            if (as.fi == ae.fi)
            {
                if (ts.fi == te.fi)
                {
                    if (ts.fi == as.fi)
                    {
                        int takS = ts.se + (st[i] == "R" ? (timeA - timeL) : (timeL - timeA));
                        int takE = ts.se + (st[i] == "R" ? (timeA + plusA - timeL - 1) : -(timeA + plusA - timeL - 1));

                        if (takS == as.se && takE == ae.se)
                        {
                            ans += plusA;
                        }
                        else if (takS <= as.se && takE >= ae.se)
                        {
                            ans += 1;
                        }
                        else if (takS >= as.se && takE <= ae.se)
                        {
                            ans += 1;
                        }
                    }
                }
                else
                {
                    int takS = ts.fi + (st[i] == "D" ? (timeA - timeL) : -(timeA - timeL));
                    int takE = ts.fi + (st[i] == "D" ? (timeA + plusA - timeL - 1) : -(timeA + plusA - timeL - 1));

                    if (takS <= as.fi && takE >= as.fi)
                    {
                        if (as.se <= ts.se && ae.se >= ts.se)
                        {
                            ans++;
                        }
                        else if (as.se >= ts.se && ae.se <= ts.se)
                        {
                            ans++;
                        }
                    }

                    else if (takS >= as.fi && takE <= as.fi)
                    {

                        if (as.se >= ts.se && ae.se <= ts.se)
                        {
                            ans++;
                        }
                        else if (as.se <= ts.se && ae.se >= ts.se)
                        {
                            ans++;
                        }
                    }

                    // cout << timeA << " " << timeT << endl;
                    // cout << as.fi << " " << as.se << " | " << ae.fi << " " << ae.se << endl;
                    // cout << takS << " " << ts.se << " | " << takE << " " << te.se << endl;
                }
            }
            else
            {
                if (ts.se == te.se)
                {
                    if (ts.se == as.se)
                    {
                        int takS = ts.fi + (st[i] == "D" ? (timeA - timeL) : -(timeA - timeL));
                        int takE = ts.fi + (st[i] == "D" ? (timeA + plusA - timeL - 1) : -(timeA + plusA - timeL - 1));

                        if (takS == as.fi && takE == ae.fi)
                        {
                            ans += plusA;
                        }
                        else if (takS <= as.fi && takE >= ae.fi)
                        {
                            ans += 1;
                        }
                        else if (takS >= as.fi && takE <= ae.fi)
                        {
                            ans += 1;
                        }
                    }
                }
                else
                {
                    int takS = ts.se + (st[i] == "R" ? (timeA - timeL) : (timeL - timeA));
                    int takE = ts.se + ((st[i] == "R" ? (timeA + plusA - timeL - 1) : -(timeA + plusA - timeL - 1)));
                    if (takS <= as.se && takE >= as.se)
                    {
                        if (as.fi <= ts.fi && ae.fi >= ts.fi)
                        {
                            ans++;
                        }
                        else if (as.fi >= ts.fi && ae.fi <= ts.fi)
                        {
                            ans++;
                        }
                    }

                    else if (takS >= as.se && takE <= as.se)
                    {
                        if (as.fi >= ts.fi && ae.fi <= ts.fi)
                        {
                            ans++;
                        }
                        else if (as.fi <= ts.fi && ae.fi >= ts.fi)
                        {
                            ans++;
                        }
                    }
                }
            }

            as = ae;
            timeA += plusA;

            if (timeA == timeT)
            {
                break;
            }
        }

        ts = te;
    }

    cout << ans << endl;
    return 0;
}
