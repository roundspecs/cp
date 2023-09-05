
void __print(int x)         { cout << x; };
void __print(double x)      { cout << x; };
void __print(long long x)   { cout << x; };
void __print(long double x) { cout << x; };
void __print(string x)      { cout << '"' << x << '"'; };
void __print(const char* x) { __print(string(x)); };
void __print(char x)        { cout << '\'' << x << '\''; };
void __print(bool x)        { cout << (x?'T':'F'); };
template<typename T1, typename T2>
void __print(pair<T1,T2> x) { 
	cout<<'(';
	__print(x.first);
	cout<<',';
	__print(x.second);
	cout<<')';
};
template<typename T>
void __print(vector<T> x) {
	for(T i: x) {
		__print(i);
		cout << ' ';
	}
}
template<typename T>
void __print(set<T> x) {
	for(T i: x) {
		__print(i);
		cout << ' ';
	}
}

#define deb(X)                                                                 \
	{                                                                            \
		auto _X = (X);                                                             \
		cout << "L" << __LINE__ << ": " << #X << " = ";                            \
		__print(_X);                                                               \
		cout << '\n';                                                              \
	}
#define debn(X, n)                                                             \
	{                                                                            \
		cout << "L" << __LINE__ << ": " << #X << " = ";                            \
		for (int _ = 0; _ < n; _++) {                                              \
			__print(X[_]);                                                           \
			cout << ' ';                                                             \
		}                                                                          \
		cout << '\n';                                                              \
	}