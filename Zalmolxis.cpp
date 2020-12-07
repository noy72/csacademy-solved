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

	vector<int> v(n);
	cin >> v;

	list<int> a = {30};

	int index = 0;
	auto it = a.begin();
	while(index < n){
		if(v[index] == *it){
			index++;
			it++;
		}else if(v[index] < *it){
			(*it)--;
			it = a.emplace(it, *it);
		}else{
			it++;
		}
		//int k;
		//cin >> k;

		//show(distance(a.begin(), it));
		//for(auto i = a.begin(); i != a.end(); i++){
		//	cout << *i << ' ';
		//}
	}

	k = k - (a.size() - n);

	while(k > 0){
		if(*it > 0){
			(*it)--;
			it = a.emplace(it, *it);
			k--;
		}else{
			it++;
		}
	}

	for(auto i = a.begin(); i != a.end(); i++){
		cout << *i << (next(i,1) == a.end() ? '\n' : ' ');
	}
}
