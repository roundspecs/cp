void __print(int x)         { cout << x; };
void __print(double x)      { cout << x; };
void __print(long long x)   { cout << x; };
void __print(long double x) { cout << x; };
void __print(string x)      { cout << '"' << x << '"'; };
void __print(const char* x) { __print(string(x)); };
void __print(char x)        { cout << '\'' << x << '\''; };
void __print(bool x)        { cout << (x?'T':'F'); };
template <typename T1, typename T2> void __print(pair<T1, T2> x) {
	cout << '(';
	__print(x.first);
	cout << ',';
	__print(x.second);
	cout << ')';
};
template <typename T> void __print(vector<T> x) {
	for (T i : x) {
		__print(i);
		cout << ' ';
	}
}
template <typename T> void __print(set<T> x) {
	for (T i : x) {
		__print(i);
		cout << ' ';
	}
}

#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define deb(...) GET_MACRO(__VA_ARGS__, deb1, deb2)(__VA_ARGS__)

#define deb1(X)                                                                \
	{                                                                            \
		auto _X = (X);                                                             \
		cout << "L" << __LINE__ << ": " << #X << " = ";                            \
		__print(_X);                                                               \
		cout << '\n';                                                              \
	}
#define deb2(F, L)                                                             \
	{                                                                            \
		string _N = #F;                                                            \
		cout << "L" << __LINE__ << ": " << _N.substr(0, _N.find('.'))              \
		     << " = ";                                                             \
		for (auto _ = F; _ != L; _++) {                                            \
			__print(*_);                                                             \
			cout << ' ';                                                             \
		}                                                                          \
		cout << '\n';                                                              \
	}