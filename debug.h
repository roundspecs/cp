template<class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << "(" << p.first << "," << p.second << ")";
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << "{";
    for (auto it : a)
        os << it << ",";
    return os << "}";
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &a) {
    os << "{";
    for (auto it : a)
        os << it << ",";
    return os << "}";
}

template<class T>
ostream &operator<<(ostream &os, const multiset<T> &a) {
    os << "{";
    for (auto it : a)
        os << it << ",";
    return os << "}";
}

template<class T1, class T2>
ostream &operator<<(ostream &os, const map<T1, T2> &a) {
    os << "{";
    for (auto it : a)
        os << it << ",";
    return os << "}";
}

#define deb(X) cout << __LINE__ << "|" << #X << ": " << (X) << "\n"