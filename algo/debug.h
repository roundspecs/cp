void __PRINT(int X)                  { cout << X; };
void __PRINT(unsigned int X)         { cout << X; };
void __PRINT(float X)                { cout << X; };
void __PRINT(double X)               { cout << X; };
void __PRINT(long X)                 { cout << X; };
void __PRINT(unsigned long X)        { cout << X; };
void __PRINT(long long X)            { cout << X; };
void __PRINT(unsigned long long X)   { cout << X; };
void __PRINT(long double X)          { cout << X; };
void __PRINT(string X)               { cout << '"' << X << '"'; };
void __PRINT(const char* X)          { __PRINT(string(X)); };
void __PRINT(char X)                 { cout << '\'' << X << '\''; };
void __PRINT(bool X)                 { cout << (X?'T':'F'); };
template <typename T1, typename T2> void __PRINT(pair<T1, T2> X) {
	cout << '(';
	__PRINT(X.first);
	cout << ',';
	__PRINT(X.second);
	cout << ')';
};
template <typename T>
void __PRINTWITHDELIM(T X, string DELIM=" ") {
	__PRINT(X);
	cout<<DELIM;
}

template <typename TupleT, std::size_t... Is>
void printTupleImp(const TupleT& tp, std::index_sequence<Is...>) {
    size_t INDEX = max({Is...});
    cout << "(";
    (__PRINTWITHDELIM(std::get<Is>(tp), (INDEX-->0 ? ",":"")), ...);
    cout << ")";
}

template <typename TupleT, std::size_t TupSize = std::tuple_size_v<TupleT>>
void __PRINT(const TupleT& tp) {
    printTupleImp(tp, std::make_index_sequence<TupSize>{});
}

#define GET_MACRO(_1, _2, NAME, ...) NAME
#define deb(...) GET_MACRO(__VA_ARGS__, DEB2, DEB1)(__VA_ARGS__)

#define DEB1(X)                                                                \
	{                                                                            \
		auto _X = (X);                                                             \
		cout << "L" << __LINE__ << ": " << #X << " = ";                            \
		__PRINT(_X);                                                               \
		cout << '\n';                                                              \
	}
#define DEB2(F, L)                                                             \
	{                                                                            \
		string _S = #F;                                                            \
		cout << "L" << __LINE__ << ": " << _S.substr(0, _S.find('.'))              \
		     << " = [";                                                            \
		for (auto _ = F; _ != L; _++) {                                            \
			auto __ = _; __++;                                                       \
			if(__==L) __PRINT(*_);                                                   \
			else __PRINTWITHDELIM(*_,",");                                           \
		}                                                                          \
		cout << "]\n";                                                             \
	}