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
	string s = "123456789";
	set<long long> st;
	do {
		range(i,1,10 - 1){
			range(j,1,10 - i - 1){
				long long a = stoi(s.substr(0,i));
				long long b = stoi(s.substr(i,j));
				long long c = stoi(s.substr(i + j,s.size() - j - i));
				if(a * b == c){
					cout << a << ' ' << b << ' ' << c << endl;
					st.emplace(c);
				}
			}
		}
	} while(next_permutation(all(s)));

	cout << accumulate(all(st), 0LL) << endl;
}
