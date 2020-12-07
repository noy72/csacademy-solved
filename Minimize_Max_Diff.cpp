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

// 幅がkである区間から最小値を求める
template <class T>
std::vector<int> slideMinimum(const std::vector<T> &a, int k) {
	int n = a.size();
	std::deque<int> deq;
	std::vector<int> res;
	for (int i = 0; i < n; i++) {
		while (deq.size() && a[deq.back()] >= a[i]) deq.pop_back();
		deq.push_back(i);
		if (i - k + 1 >= 0) {
			res.push_back(deq.front());
			if (deq.front() == i - k + 1) deq.pop_front();
		}
	}
	return res;
}

int main(){
	int n, k;
	cin >> n >> k;

	vector<long long> a(n);
	cin >> a;

	vector<long long> d(n - 1);
	rep(i,n - 1){
		d[i] = a[i + 1] - a[i];
		d[i] *= -1;
	}

	vector<int> mini = slideMinimum(d, n - k - 1);

	long long ans = 1e9;
	for(auto i : mini) ans = min(ans, -d[i]);
	cout << ans << endl;
}
