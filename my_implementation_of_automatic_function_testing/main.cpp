#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

template<class T, class ... Args, class ... Input>
void check_the_solution(vector<T> output, T(*func)(Args...), Input ... in) {
	int cnt = min({ in.size() ... });
	bool itsSuccessful = true;

	if (cnt == 0) {
		cout << "testing a function without parameters is impossible";
		return;
	}
	for (int i = 0; i < cnt; i++) {
		if (func(in[i]...) == output[i]) continue;
		else {
			ostringstream buffer;
			buffer << "your function have a problem with this arguments:\n";
			((buffer << in[i] << "   "), ...);
			cout << buffer.str() << endl;
			itsSuccessful = false;
		}
	}
	if (itsSuccessful) cout << "all tests were passed successfully (!)\n\n";
}

// ниже тестируем функцию для тестирования ;D

int sumOfThree(int a, int b, int c) { return a + b + c; }

bool isPalindrome(const string& s) {
	if (s.size() % 2 == 1) {
		int middle = s.size() / 2;
		int il = middle - 1, ir = middle + 1;
		while ((il >= 0) && (ir < s.size())) {
			if (s[il] != s[ir]) return false;
			ir++;
			il--;
		}
		return true;
	}
	else if (s.size() % 2 == 0) {
		int middle = s.size() / 2;
		int il = middle - 1, ir = middle;
		while ((il >= 0) && (ir < s.size())) {
			if (s[il] != s[ir]) return false;
			ir++;
			il--;
		}
		return true;
	}
	else if (s.size() == 0) return true;

	return false;
}

int main() {

	vector<int> a = { 1, 2, 3 };
	vector<int> b = { 1, 2, 3 };
	vector<int> c = { 1, 2, 3 };
	vector<int> output1 = { 3, 6, 9 };
	cout << "sumOfThree: \n";
	check_the_solution(output1, sumOfThree, a, b, c);

	vector<string> palindromeOrNot = { "aaa", "aoa", "aao", "aaaa" };
	vector<bool> output2 = { true,true, false, true };

	cout << "isPalindrome: \n";
	check_the_solution(output2, isPalindrome, palindromeOrNot);

}