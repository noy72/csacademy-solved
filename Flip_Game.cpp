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

void reverse(vector<int>& v){
	for(auto& i : v) i = i ^ 1;
}

long long toLong(vector<int>& v){
	long long res = 0;
	rep(i,v.size()){
		res *= 2;
		res += v[i];
	}
	return res;
}

int main(){
	int n, m;
	cin >> n >> m;

	vector<vector<int>> b(n, vector<int>(m));
	rep(i,n){
		rep(j,m){
			cin >> b[i][j];
		}
	}

	rep(i,n){
		if(b[i][0] == 0){
			reverse(b[i]);
		}
	}

	//rep(i,n){ rep(j,m){ cout << b[i][j] << ' '; } cout << endl; } cout << endl;

	rep(i,m){
		int sum = 0;
		rep(j,n){
			sum += b[j][i];
		}
		if(n - sum > sum){
			rep(j,n){
				b[j][i] = b[j][i] ^ 1;
			}
		}
	}
	//rep(i,n){ rep(j,m){ cout << b[i][j] << ' '; } cout << endl; } cout << endl;

	long long ans = 0;
	rep(i,n){
		//show(toLong(b[i]))
		ans += toLong(b[i]);
	}
	cout << ans << endl;
}
