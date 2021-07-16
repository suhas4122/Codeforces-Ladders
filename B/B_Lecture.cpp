#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    map<string, string>mp;
    map<string, int>mpp;

    int n,m,i;
    string s1,s2,s;
    cin>>n>>m;
    while(m--)

    {
        cin>>s1>>s2;
        mp[s1]=s2;
        mp[s2]=s1;

        mpp[s1]=1;
        mpp[s2]=2;
    }
    while(n--)
    {
        cin>>s;
        if(mpp[s]==1)
        s1=s,s2=mp[s];
        else
          s2=s,s1=mp[s];

        if(mp[s2].size()>mp[s1].size())
            cout<<mp[s1];
        else
            cout<<mp[s2];
        if(n)
            cout<<" ";
        else
            cout<<endl;
    }
}