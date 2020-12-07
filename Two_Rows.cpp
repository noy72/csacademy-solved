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

	int m[2][100005];
	rep(i,2) rep(j,n) cin >> m[i][j];

	long long dp[2][100005];
	rep(i,2) rep(j,n) dp[i][j] = (i + j) % 2 ? 1LL << 60 : -(1LL << 60);
	dp[1][n - 1] = m[1][n - 1];

	for(int j = n - 1; j >= 0; j--){
		for(int i = 1; i >= 0; i--){
			if((i + j) % 2){
				long long res = 0;
				dp[i ^ 1][j] = max(dp[i ^ 1][j], dp[i][j] + m[i ^ 1][j]);
				if(j + 1 < n) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + m[i][j + 1]);
			}else{
				dp[i ^ 1][j] = min(dp[i ^ 1][j], dp[i][j] + m[i ^ 1][j]);
				if(j + 1 < n) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + m[i][j + 1]);
			}
			rep(x,2){
				rep(y,n) {
					cout << dp[x][y] << ' ';
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	cout << dp[1][n - 1] << endl;
}
