#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define for0(n) for (long long i = 0; i < (long long)(n); ++i) // 0 based indexing
#define for0j(n) for (long long j = 0; j < (long long)(n); ++j) // 0 based indexing
#define for1(n) for (long long i = 1; i <= (long long)(n); ++i) // 1 based indexing
#define for1j(n) for (long long j = 1; j <= (long long)(n); ++j) // 1 based indexing
#define forc(l, r) for (long long i = (long long)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(n) for (long long i = (long long)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(n) for (long long i = (long long)(n); i >= 1; --i) // reverse 1 based

#define pb push_back
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


using namespace std;

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

ll N = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;

    bool odd[26] = {false};
    for (size_t i = 0; i < s.length(); ++i)
    {
        odd[s[i]-'a'] = !odd[s[i]-'a'];
    }
    int oddcount = count(odd, odd + sizeof(odd) / sizeof(odd[0]), true);
    cout << (oddcount == 0 || oddcount % 2 == 1 ? "First" : "Second") << endl;

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
