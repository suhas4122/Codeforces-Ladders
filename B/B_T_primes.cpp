#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define for0(i, n) for (long long i = 0; i < (long long)(n); ++i) // 0 based indexing
#define for1(i, n) for (long long i = 1; i <= (long long)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (long long i = (long long)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (long long i = (long long)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (long long i = (long long)(n); i >= 1; --i) // reverse 1 based

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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

bool isperf(ll x){

    if (x >= 0) {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    ll n;
    cin >> n;
    vll array;
    set<long long int> st;
    vector<bool> primes(1000001,true);
    primes[0]=primes[1]=false;

 
    ll i, j;
    ll m = 1000001;

    for(i=2;i*i<=m;i++) {
        if(primes[i]) {
            for(j=i;i*j<=m;j++) {
                primes[i*j]=false;
            }
        }
    }

    for(i=2;i<=m;i++) {
        if(primes[i])
            st.insert(i*i);
    }
    
    for0(i, n) {
        ll x;
        cin >> x;
        
        if(isperf(x) && (st.find(x)!=st.end())){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

}