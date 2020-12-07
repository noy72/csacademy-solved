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
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	cin >> a;

	map<int,int> m;
	rep(i,a.size()){
		m[a[i]] = a[i];
	}

	vector<bool> used(n + 1, false);
	int mini = 1, l = 0, r = 0;
	set<int> b;
	rep(i,a.size()){
		if(i - l >= k){
			used[m[a[l]]] = false;
			while(mini > 1 and not used[mini - 1]) mini--;
		}
		used[m[a[r]]] = true;
		while(used[mini]) mini++;
	}
}
