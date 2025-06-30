#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using lli = long long;
using pii = pair<lli, lli>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	const int mxN=200000;

	srand(time(0)); 

	int n=100;
	cout << n << endl;
	for(int i=0;i<n;i++){
		lli val=1+(rand()%mxN);
		cout<<val<<" ";
	}
	cout << endl;
	for(int i=0;i<n;i++){
		lli val=1+(rand()%mxN);
		cout<<val<<" ";
	}
	cout << endl;
}