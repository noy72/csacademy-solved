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

const double EPS = 1e-9;

int main(){
	double h;
	int q;
	cin >> h >> q;

	vector<pair<double, double>> a(q);
	rep(i,q){
		cin >> a[i].first >> a[i].second;
	}
	sort(all(a));

	priority_queue<double> p;

	double time = 0;
	int i = 0;
	while(h > EPS){
		if(i >= q){
			if(p.empty()){
				cout << -1 << endl;
				return 0;
			}else{
				double waterDiff = h - p.top();
				assert(waterDiff >= 0);
				double t = waterDiff / static_cast<double>(p.size());
				time += t;
				h = p.top();
				p.pop();
			}
		}else{
			if(p.empty()){
				time = a[i].first;
				p.emplace(a[i].second);
				i++;
			}else{
				double timeDiff = a[i].first - time;
				assert(timeDiff >= 0);
				if(h - timeDiff * p.size() < p.top()){
					double waterDiff = h - p.top();
					assert(waterDiff >= 0);
					double t = waterDiff / static_cast<double>(p.size());
					time += t;
					h = p.top();
					p.pop();
				}else{
					h -= timeDiff * p.size();
					time = a[i].first;
					p.emplace(a[i].second);
					i++;
				}
			}
		}
		while(not p.empty() and p.top() >= h) p.pop();
		//cout << time << ' ' << i << ' ' << p.top() << endl;
	}
	cout << fixed << setprecision(10) << time << endl;
}
