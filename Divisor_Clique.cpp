#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

int main(){
	int n;
	cin >> n;

	vector<int> a(n);
	cin >> a;
	sort(all(a));

	vector<int> dp(n, 0);//, vector<int>(n));
	dp[0] = 1;
	rep(i,n){
		range(j,i + 1,n){
			if(a[j] % a[i] == 0){
				dp[j] = max(dp[j], dp[i] + 1);
			}
		}
	}
	cout << *max_element(all(dp)) << endl;
}
