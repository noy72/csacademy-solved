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
	int n, k;
	cin >> n >> k;
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}

	if(n <= 3 and k == 0){
		cout << -1 << endl;
		return 0;
	}

	cout << (n - 1) * 2 - k << endl;
	rep(i,n - 1){
		cout << i + 1 << ' ' << i + 2 << ' ' << i + 1 << endl;
	}
	if(k == 0){
		cout << 1 << ' ' << n - 1 << ' ' << n + n << endl;
		k++;
	}
	rep(i,n - 1 - k){
		cout << i + 1 << ' ' << n << ' ' << n + i << endl;
	}
	//if(n - 1 - k >= 0) cout << (k == 0 ? 1 : n) << ' ' << n - k - 1 << ' ' << n + (n - 2 - k) << endl;
}
