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
	long double d, l;
	int n;
	cin >> d >> l >> n;

	vector<long double> a(n);
	cin >> a;
	a.emplace_back(0);
	a.emplace_back(d);

	sort(all(a));

	long double ans = 0;
	rep(i,a.size() - 1){
		long double len = a[i + 1] - a[i] - l;
		if(len <= 0) continue;
		ans += len * len / 2.0 / 2.0;
	}
	cout << fixed << setprecision(10) << ans / d << endl;
}
