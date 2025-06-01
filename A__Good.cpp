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

	lli n; cin >> n;
	vector<lli> arr(n) , brr(n);
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<n;i++) {
		cin >> brr[i];
	}

	const lli INF=1e18;
	lli ans=INF;
	for(int mid=0;mid<=200200;mid++){
		lli tot=0;
		lli val=mid;
		for(int i=n/2;i>=0;i--){
			if(arr[i]>val){
				tot+=arr[i]-val;
			}else tot+=val-arr[i];
			val++;
		}
		val=mid;
		for(int i=n/2;i>=0;i--){
			if(brr[i]>val){
				tot+=brr[i]-val;
			}else tot+=val-brr[i];
			val++;
		}
		val=mid+1;
		for(int i=n/2+1;i<n;i++){
			if(arr[i]>val){
				tot+=arr[i]-val;
			}else tot+=val-arr[i];
			val++;
		}
		val=mid+1;
		for(int i=n/2+1;i<n;i++){
			if(brr[i]>val){
				tot+=brr[i]-val;
			}else tot+=val-brr[i];
			val++;
		}
		ans=min(ans, tot);
	}
	cout << ans << endl;
}