#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int size;
	int height;
	vector<int> d;

	segtree() : segtree(0){};
	segtree(int n) : segtree(vector<int>(n)){};
	segtree(vector<int> v) {
		size = 1;
		height = 0;
		while (size < v.size())
			size *= 2, height++;
		d.resize(2 * size);
		for (int i = 0; i < v.size(); i++)
			d[i + size] = v[i];
		for (int i = size - 1; i > 0; i--)
			update(i);
	}

    void set(int i, int val) {
        i += size;
        d[i] = val;
        i /= 2;
        while(i > 0) {
            update(i);
            i /= 2;
        }
    }

    void query(int l, int r) {
        
    }

	void update(int idx) {
		d[idx] = d[2 * idx] + d[2 * idx + 1];
	}

	void print() {
		for (int h = 0; h <= height; h++) {
			int lo = 1 << h;
			int hi = 1 << (h + 1);
			for (int i = lo; i < hi; i++) {
				cout << d[i] << " ";
			}
			cout << "\n";
		}
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int &vi : v)
		cin >> vi;
	for (int &vi : v)
		cout << vi << " ";
	cout << "\n";

	segtree s = segtree(v);
	s.print();

    s.set(3, 5);
    s.print();
    


}