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

int f(int x){
	int res = 0;
	while(x != 0){
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main(){
	int x;
	cin >> x;

	int cnt = 1;
	while(x != 0){
		x -= f(x);
		cnt++;
		show(x)
	}
	cout << cnt << endl;
}
