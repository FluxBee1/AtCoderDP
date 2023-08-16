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
const bool Multiple = false;
long long inf = 1e15 + 4;

void solve() {
	long long n ;
	cin >> n ;
	vector<long long> a(n);
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<long long>> sum(n, vector<long long> (n, 0ll));
	for (int i = 0 ; i < n ; i++) {
		long long cur = 0 ;
		for (int j = i ; j < n ; j++) {
			cur += a[j];
			sum[i][j] = cur;
		}
	}
	vector<vector<long long>>  dp(n, vector<long long>(n, inf));
	for (int i = 0 ; i < n ; i++) {
		dp[i][i] = 0ll ;
	}
	for (int size = 1; size <= n ; size++) {
		for (int left = 0 ; left < n ; left++) {
			int right = left + size;
			if (right < n ) {
				for (int k = left ; k < right ; k++) {
					dp[left][right] = min(dp[left][right], max(sum[left][right], sum[right][left]) + dp[left][k] + dp[k + 1][right]);
				}
			}
		}
	}
	/*for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}*/
	cout << dp[0][n - 1] << endl;

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