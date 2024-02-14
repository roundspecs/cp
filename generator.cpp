#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	random_device rd;
	uniform_int_distribution<int> tc(1, 10);
	uniform_real_distribution<double> X(1, 10);
    
	int T = tc(rd);
	cout << T << "\n";
	while (T--) {
        double x = X(rd);
        cout << x << " ";
    }
}