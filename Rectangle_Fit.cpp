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

void compress(vector<int> &v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
}

int main(){
	int n, a;
	cin >> n >> a;

	vector<pair<int, int>> p(n);
	rep(i,n) cin >> p[i].first >> p[i].second;
	sort(all(p));

	vector<int> x(n);
	rep(i,n) x[i] = p[i].first;
	compress(x);

	priority_queue<int> q;
	int ans = 0;
	for(int i = 0, j = 0; i < x.size(); i++){
		while(j < n and x[i] >= p[j].first){
			q.emplace(p[j].second);
			j++;
		}
		while(not q.empty() and a / x[i] < q.top()) q.pop();
		ans = max<int>(ans, q.size());
	}
	cout << ans << endl;
}
