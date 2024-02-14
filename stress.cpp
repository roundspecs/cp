#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	if (argc < 5) {
		cout << "Usage: ./stress good.cpp bad.cpp tc_generator.cpp count";
		return 0;
	}

	string good_file(argv[1]);
	string bad_file(argv[2]);
	string tc_gen_file(argv[3]);
	int cnt = stoi(argv[4]);

	cout << "Good file: " << good_file << "\n";
	cout << "Bad file: " << bad_file << "\n";
	cout << "TC Generator: " << tc_gen_file << "\n";
	cout << "Count: " << cnt << "\n";
	cout << "\n";
	
	cout << "Compiling:\n";
	cout << "  1. " << good_file << "\n";
	system(("g++ " + good_file + " -o good.out").c_str());
	cout << "  2. " << bad_file << "\n";
	system(("g++ " + bad_file + " -o bad.out").c_str());
	cout << "  3. " << tc_gen_file << "\n";
	system(("g++ " + tc_gen_file + " -o tc_gen.out").c_str());
	cout << "\n";

	ofstream results("results.txt");

	for (int i = 1; i <= cnt; i++) {
		cout << "Try " << i << ":\n";
		results << "Try " << i << ":\n";

		cout << "  Generating test case\n";
		system("./tc_gen.out > tc_gen.txt");
		cout << "  Running " << good_file << "\n";
		system("./good.out < tc_gen.txt > good.txt");
		cout << "  Running " << bad_file << "\n";
		system("./bad.out < tc_gen.txt > bad.txt");

		ifstream good("good.txt"), bad("bad.txt"), tc_gen("tc_gen.txt");

		vector<string> goodlines, badlines, tc_genlines;

		string temp;

		results << "Input:\n";
		while (getline(tc_gen, temp)) {
			results << temp << "\n";
			tc_genlines.push_back(temp);
		}

		results << good_file << ":\n";
		while (getline(good, temp)) {
			results << temp << "\n";
			goodlines.push_back(temp);
		}

		results << bad_file << ":\n";
		while (getline(bad, temp)) {
			results << temp << "\n";
			badlines.push_back(temp);
		}

		if (goodlines == badlines)
			cout << "  AC\n";
		else
			cout << "  FAILED                  X\n";
		cout << "\n";
		results << "\n";
	}

	cout << "Deleting temporary files\n";
	system("rm bad.out bad.txt good.out good.txt tc_gen.out tc_gen.txt");
}