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
	n *= 2;

	vector<int> a(n);
	cin >> a;
	sort(all(a));

	vector<int> x(n - 1);
	rep(i, n - 1){
		x[i] = a.back() - a[i];
	}

	map<int,int> num;
	rep(i,n) num[a[i]]++;

	rep(i,x.size()){
		vector<int> ans;
		map<int,int> m = num;

		for(int j = n; j >= 0; j--){
			if(m[ a[j] ] <= 0) continue;
			if(a[j] - x[i] < 0) break;

			ans.emplace_back(a[j]);
			m[ a[j] ]--;

			m[ a[j] - x[i] ]--;
		}

		bool f = true;
		for(auto& p : m){
			if(p.second != 0){
				f = false;
				break;
			}
		}

		if(f){
			cout << x[i] << endl;
			for(auto i : ans) cout << i << ' ';
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
