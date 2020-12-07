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

template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first1 ,
		BidirectionalIterator last1 ,
		BidirectionalIterator first2 ,
		BidirectionalIterator last2 ){
	if (( first1 == last1 ) || ( first2 == last2 )) {
		return false ;
	}
	BidirectionalIterator m1 = last1 ;
	BidirectionalIterator m2 = last2 ; --m2;
	while (--m1 != first1 && !(* m1 < *m2 )){
	}
	bool result = (m1 == first1 ) && !(* first1 < *m2 );
	if (! result ) {
		while ( first2 != m2 && !(* m1 < * first2 )) {
			++ first2 ;
		}
		first1 = m1;
		std :: iter_swap (first1 , first2 );
		++ first1 ;
		++ first2 ;
	}
	if (( first1 != last1 ) && ( first2 != last2 )) {
		m1 = last1 ; m2 = first2 ;
		while (( m1 != first1 ) && (m2 != last2 )) {
			std :: iter_swap (--m1 , m2 );
			++ m2;
		}
		std :: reverse (first1 , m1 );
		std :: reverse (first1 , last1 );
		std :: reverse (m2 , last2 );
		std :: reverse (first2 , last2 );
	}
	return ! result ;
}

template < class BidirectionalIterator > bool next_combination ( BidirectionalIterator first , BidirectionalIterator middle , BidirectionalIterator last )
{
	return next_combination (first , middle , middle , last );
}

int n, c, s;
pair<int, int> f[5];

int solve(vector<int>& v, int r){
	int time = 0, cookie = 0, per = s;
	int i = 0;
	while(cookie < c){
		cookie += per;
		while(i < r and f[v[i]].first <= cookie){
			cookie -= f[v[i]].first;
			per += f[v[i]].second;
			i++;
		}
		time++;
	}
	return time;
}

//要素vからr個取り出す組み合わせ
int func(vector<int>& v, int r){
	int ans = INT_MAX;
	do{
		vector<int> temp(all(v));
		do{
			ans = min(ans, solve(temp, r));
		}while(next_permutation(temp.begin(), temp.begin() + r));
	}while(next_combination(v.begin(), v.begin() + r, v.end()));
	return ans;
}

int main(){
	cin >> n >> c >> s;
	rep(i,n){
		cin >> f[i].first >> f[i].second;
	}

	vector<int> v(n);
	iota(all(v),0);
	int ans = solve(v, 0);
	range(i,1,n + 1){
		ans = min(ans, func(v, i));
	}
	cout << ans << endl;
}
