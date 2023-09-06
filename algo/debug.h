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
template <typename T>
void __printwithdelim(T x, string delim=" ") {
	__print(x);
	cout<<delim;
}

template <typename TupleT, std::size_t... Is>
void printTupleImp(const TupleT& tp, std::index_sequence<Is...>) {
    size_t index = max({Is...});
    cout << "(";
    (__printwithdelim(std::get<Is>(tp), (index-->0 ? ",":"")), ...);
    cout << ")";
}

template <typename TupleT, std::size_t TupSize = std::tuple_size_v<TupleT>>
void __print(const TupleT& tp) {
    printTupleImp(tp, std::make_index_sequence<TupSize>{});
}

#define GET_MACRO(_1, _2, NAME, ...) NAME
#define deb(...) GET_MACRO(__VA_ARGS__, deb2, deb1)(__VA_ARGS__)

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
		     << " = [";                                                            \
		for (auto _ = F; _ != L; _++) {                                            \
			auto __ = _; __++;                                                       \
			if(__==L) __print(*_);                                                   \
			else __printwithdelim(*_,",");                                           \
		}                                                                          \
		cout << "]\n";                                                             \
	}