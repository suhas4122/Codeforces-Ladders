#include <bits/stdc++.h>  // This will work only for g++ compiler. 
using namespace std;

string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "] :", debug_out(__VA_ARGS__)
#define debarr(a, n) cerr << #a << " : "; for(int i = 0; i < n; i++) cerr << a[i] << " "; cerr << endl;
#define debmat(mat, row, col) cerr << #mat << " :\n"; for(int i = 0; i < row; i++){for(int j = 0; j < col; j++) cerr << mat[i][j] << " "; cerr << endl;}

#define for0(n) for (long long i = 0; i < (long long)(n); ++i) // 0 based indexing
#define for0j(n) for (long long j = 0; j < (long long)(n); ++j) // 0 based indexing
#define for1(n) for (long long i = 1; i <= (long long)(n); ++i) // 1 based indexing
#define for1j(n) for (long long j = 1; j <= (long long)(n); ++j) // 1 based indexing
#define forc(l, r) for (long long i = (long long)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(n) for (long long i = (long long)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(n) for (long long i = (long long)(n); i >= 1; --i) // reverse 1 based

// #define pb push_back
#define fi first
#define se second
// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())
//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())
// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())


// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

ll mod(ll n);
ll gcd(ll a, ll b); 
ll modM(ll n, ll m);
ll modA(ll n, ll m);
ll modS(ll n, ll m);

const long long int N = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    ll lb = 0, lc = 0, ls = 0;

    ll n = s.length();

    for0(n) {
        if(s[i] == 'B') lb++;
        else if(s[i] == 'C') lc++;
        else ls++;
    }

    ll nb, nc, ns;
    ll pb, pc, ps;
    ll r;

    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    ll low = 0;
    ll high = r+110;
    ll ans = 0;

    while(low<=high){
        ll mid = (low+high)/2;

        ll fb = max(mid*lb - nb, (ll)0);
        ll fc = max(mid*lc - nc, (ll)0);
        ll fs = max(mid*ls - ns, (ll)0);
        ll p = fb*pb + fc*pc + fs*ps;
        
        // pr(mid, p);

        if(p == r){
            cout << mid;
            return 0;
        }

        if(p < r){
            low = mid+1;
            ans = mid;
        }

        if(p > r){
            high = mid-1;
        }

    }

    cout << ans;

    return 0;
}


ll gcd(ll a, ll b) {
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll mod(ll n) {return (n % N + N) % N; }
ll modM(ll n, ll m) { return ((n % N * m % N) + N) % N; }
ll modA(ll n, ll m) { return ((n % N + m % N) + N) % N; }
ll modS(ll n, ll m) { return ((n % N - m % N) + N) % N; }
