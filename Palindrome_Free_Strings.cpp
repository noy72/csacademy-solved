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

bool isPalindrome(string s, string t){
	for(auto c : s) if(c == '@') return false;
	reverse(all(t));
	return s == t;
}

int main(){
	string s;
	cin >> s;

	int m[300][300] = {};
	range(len,2,s.size() + 1){
		for (int i = 0; i + len <= s.size(); i++) {
			string t = s.substr(i, len);
			if(isPalindrome(t, t)){
				int a = i + len / 2 - 1;
				int b = i + len / 2 + len % 2;
				m[a][b] = m[b][a] = 1;
			}
		}
	}

	int cnt = 0;
	while(true){
		int maxi = 0;
		int remove;
		rep(i,s.size()){
			int sum = 0;
			rep(j,s.size()){
				sum += m[i][j];
			}
			if(maxi < sum){
				maxi = sum;
				remove = i;
			}
		}
		if(maxi != 0){
			cnt++;
			rep(i,s.size()){
				m[remove][i] = m[i][remove] = 0;
			}
		}else{
			break;
		}
	}
	cout << cnt << endl;
}
