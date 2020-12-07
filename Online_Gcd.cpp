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


int gcd(int x, int y) {
	int r;
	if(x < y) swap(x, y);

	while(y > 0){
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main(){
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	cin >> a;

	int cur = a.front();
	rep(i,n){
		cur = gcd(cur, a[i]);
	}

	rep(i,m){
		int x, y;
		cin >> x >> y;
		a[x - 1] /= y;
		cur = gcd(cur, a[x - 1]);
		cout << cur << endl;
	}
}
