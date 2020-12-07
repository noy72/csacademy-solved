#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

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

	int v = 0;
	double cnt = 0, ans = 0;
	rep(i,a.size()){
		if(v == 1 and a[i] == 1){
			ans = max(ans, cnt + 0.5);
			cnt = 0;
			v = 0;
			continue;
		}else if(v == 0 and a[i] != -1){
			ans = max(ans, cnt);
			cnt = 0;
			v = 0;
			continue;
		}

		if(a[i] == -1){
			v += 2;
		}else if(a[i] == 0){
			v -= 1;
		}else{
			v -= 2;
		}
		cnt++;
		//cout << v << ' ' << cnt << endl;
	}
	if(cnt != 0) ans = max(ans, cnt);
	cout << ans << endl;
}
