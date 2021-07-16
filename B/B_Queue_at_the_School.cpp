
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define bg begin()
#define ed end()
#define ll long long
#define mt make_tuple
#define ld long double
#define INF pow(10, 18)
#define newl cout << '\n'; 
#define ne cout << "NO" << '\n' 
#define ye cout << "YES" << '\n' 
#define all(v) v.begin(), v.end()
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define ub(a, x) upper_bound(all(a), x)
#define lb(a, x) lower_bound(all(a), x)
#define fill(a) memset(a, 0, sizeof(a))
#define sumv(v) accumulate(all(v),(ll)0)
#define fill1(a) memset(a, -1, sizeof(a))
#define f(a, b) for (ll i = a; i < b; i++)
#define fj(a, b) for (ll j = a; j < b; j++)
#define fk(a, b) for (ll k = a; k < b; k++)
#define fb(b, a) for (ll i = b; i > a; i--)
#define fe(a, b) for (ll i = a; i <= b; i++)
#define tr(it, v) for (auto it = v.bg; it != v.ed; it++)
#define pr(x) cout << #x << " " << (x) << '\n';
#define pp(x) cout << x.first << " " << x.second << '\n';
#define pr1(x) cout << (x) << " ";
#define prv(a) for(auto x : a) cout << x << " "; cout << '\n'; 
#define dout(x) cout << x << '\n';
#define scan(a, n) vector<ll> a(n); f(0, n) cin >> a[i];
#define prvp(a) for(auto x : a) cout << x.F << " " << x.S << '\n';                           
#define pr2(x, y) cout << #x << " " << (x) << "  " << #y << " " << (y) << '\n';
#define dout2(x, y) cout << x << " " << y << '\n';
#define pr3(x, y, z) cout << #x << " " << (x) << "  " << #y << " " << (y) << "  " << #z << " " << (z) << '\n';
#define dout3(x, y, z) cout << x << " " << y << " " << z << '\n';

ll min(ll a, ll b) { if(a < b) return a; else return b; } 
ll max(ll a, ll b) { if(a < b) return b; else return a; } 
ll min3(ll a, ll b, ll c) { return min(a, min(b, c)); } 
ll max3(ll a, ll b, ll c) { return max(a, max(b , c)); } 
ll ceil1(ld x, ld y)
{
	ld q = x / y;
	if((ll)q == q) return q;
	return q + 1;
}

ll NC = 100; 
ll N = 1e9 + 7;
const ll S = 3e5 + 7;

ll mod(ll n);
ll gcd(ll a, ll b); 
ll modM(ll n, ll m);
ll modA(ll n, ll m);
ll modS(ll n, ll m);
ll power(ll a, ll b);
void pra(ll a[], ll n);
void ipgraph(ll n, ll m);

vector < vector < ll > > v ;
vector<bool> vis;
//==============================================================================================


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << setprecision(15);

#ifndef ONLINE_JUDGE
	freopen("", "r", stdin);
	freopen("", "w", stdout);
#endif

    int n, t;
    string s,s1;

	cin >> n >> t >> s;
    s1 = s;
	f(0,t) {
        s = s1;
		fj(0, s.length()-1) {
			if(s[j] == 'B' && s[j+1] == 'G')
                s1[j] = s[j+1], s1[j+1] = s[j];
		}
	}

    cout << s1; 
}

void ipgraph(ll n, ll m)
{ 
	v.assign(n, vector<ll>()); 
	vis.assign(n, 0);
	ll x, y;
	f(0, m)
	{
		cin >> x >> y;
		x--, y--;
		v[y].push_back(x);
		v[x].push_back(y); 
	}
}

ll gcd(ll a, ll b)
{
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll power(ll a, ll b)
{
	if (b == 0) return 1;
	ll c = power(a, b / 2);
	if (b % 2 == 0) return modM(c, c);
	else return modM(modM(c, c), a);
}

void pra(ll a[], ll n)
{
	f(0, n) cout << a[i] << " ";
	cout << '\n';
}

ll mod(ll n) {return (n % N + N) % N; }
ll modM(ll n, ll m) { return ((n % N * m % N) + N) % N; }
ll modA(ll n, ll m) { return ((n % N + m % N) + N) % N; }
ll modS(ll n, ll m) { return ((n % N - m % N) + N) % N; }
