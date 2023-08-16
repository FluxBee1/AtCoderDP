#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int 		long long int
#define ll			long long
#define ull 		unsigned long long
#define lld 		long long double
#define read(a) 	for(int i = 0 ; i < a.size();i++) cin >> a[i];
#define print(a) 	for(int i = 0 ; i < a.size();i++) cout << a[i] <<" ";
#define rep(i,x,n) 	for(int i = x ; i <=n; i++)
#define vi 			vector<int>
#define vii 		vector<vector<int>>
#define pii 		pair<int,int>
#define msi 		multiset<int>
#define si 			set<int>
#define ff 			first
#define ss 			second
#define pb 			push_back
#define ppb         pop_back
#define in   		insert
#define er 			erase
#define all(x)      x.begin(),x.end()

// Debugger
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
//void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> 			void _print(vector <T> v);
template <class T> 			void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> 			void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> 			void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> 			void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> 			void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// Debugger end
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int mod = 1e9 + 7;
const bool Multiple = true;
int dp[405][405];

int cal(vector<int> &a , int i , int j) {
	if (i == j) return a[i];
	if (i >= a.size()) return 0 ;
	if (j < 0) return 0 ;
	if (dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = min(a[i] + cal(a, i + 1, j), a[j] + cal(a, i, j - 1));
}
void solve() {
	int n ;
	cin >> n ;
	vector<int> a(n);
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}
	// dp[i][j] min cost to merge a from i to j
	memset(dp, -1, sizeof(dp));
	cout << cal(a, 0, n - 1) << endl;


}
signed  main()
{
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1 ;
	if (Multiple) cin >> t;
	for (int i  = 1 ; i <= t ; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
	return 0 ;
}