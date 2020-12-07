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

long long p(long long a){
	return a * a;
}

int main(){
	int t;
	cin >> t;

	while(t--){
		vector<long long> a(3);
		cin >> a;

		long long sum = a[0] - a[1] + a[2];
		if(sum % 2 == 0 and 2 * *max_element(all(a)) <= accumulate(all(a), 0LL)){
			long long x = sum / 2;
			cout << 0 << ' ' << 0 << ' ' << a[0] - x << ' ' << a[2] - x << ' ' << a[0] << ' ' << 0 << endl;
			continue;
		}
		cout << -1 << endl;
	}
}
