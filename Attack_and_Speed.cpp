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
	long long a, s, k, x, y;
	cin >> a >> s >> k >> x >> y;

	long long right = k + 1, left = 0;
	rep(i,100){
		long long mid = (right + left) / 2;
		if(a - s + x * mid == (k - mid) * y){
			cout << mid << endl;
			return 0;
		}
		if( (a - s + x * mid) <= (k - mid) * y) left = mid;
		else right = mid;
	}
	cout << -1 << endl;
}
