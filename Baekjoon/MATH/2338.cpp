#include <iostream>
using namespace std;

#define NUM(a) int(a - 48)

string Plus(string a, string b) {
	string res;

	int max = a.size() > b.size() ? a.size() : b.size();
	int min = a.size() > b.size() ? b.size() : a.size();

	int up = 0;
	int num = 0;

	int numA, numB = 0;

	for (int i = 1; i <= max; i++)
	{
		numA = int(a.size() - i) < 0 ? 0 : NUM(a[int(a.size() - i)]);
		numB = int(b.size() - i) < 0 ? 0 : NUM(b[int(b.size() - i)]);
	
		num = numA + numB + up;
		up = num / 10;

		res.insert(0, string(1, char((num % 10) + 48)));
	}

	if (up > 0) {
		res.insert(0, string(1, char(up + 48)));
	}
	return res;
}



string Minus(string a, string b, bool minus = false) {
	string res;
	string zero = "";

	if (a == b) {
		return res.insert(0, string("0"));
	}

	// B > A -> (B - A) *-1
	if (b.size() > a.size()) {
		minus = true;

		string temp;
		temp = b;
		b = a;
		a = temp;
	}
	// B > A -> (B - A) *-1
	else if (a.size() == b.size()) {
		if (NUM(a[0]) < NUM(b[0])) {
			minus = true;

			string temp;
			temp = b;
			b = a;
			a = temp;
		}
	}

	int max = a.size();
	int min = b.size();

	int down = 0;
	int num = 0;

	int numA, numB = 0;
	int idxA, idxB = 0;

	for (int i = 1; i <= max; i++)
	{
		idxA = int(a.size() - i);
		idxB = int(b.size() - i);

		numA = idxA >= 0 ? NUM(a[idxA]) : 0;
		numB = idxB >= 0 ? NUM(b[idxB]) : 0;

		num = numA - numB + 10 - down;

		if (num >= 10) {
			num %= 10;
			down = 0;
			if (num == 0) {
				zero.push_back(char(num + 48));
			}
			else{
				res.insert(0, zero);
				res.insert(0, string(1, char(num + 48)));
				zero.clear();
			}
		}
		else {
			down = 1;
			if (num == 0) {
				zero.push_back(char(num + 48));
			}
			else {
				res.insert(0, zero);
				res.insert(0, string(1, char(num + 48)));
				zero.clear();
			};
		}
	}
	if (minus) {
		if (res[0] != '0') {
			res.insert(0, string("-"));
		}
		else {
			res[0] = '-';
		}
	}
	else {
		if (res[0] == '0') {
			return res.substr(1, res.size());
		}
	}
	
	return res;
}

string Multi(string a, string b, bool minus = false) {

	string res= "0";
	string temp2 = "0";

	if (a[0] == '0' || b[0] == '0') {
		return res;
	}

	int num = 0;
	int up = 0;
	for (int B = 1; B <= b.size(); B++)
	{
		string temp;
		up = 0;
		for (int A = 1; A <= a.size(); A++)
		{
			num = NUM(a[a.size() - A]) * NUM(b[b.size() - B]) + up;

			up = num / 10;
			char t = char((num % 10) + 48);
			temp.insert(0, string(1, t));
		}
		if (up > 0) {
			temp.insert(0, string(1, char(up + '0')));
		}
		for (int i = 1; i < B; i++)
		{
			temp.push_back('0');
		}

		res = Plus(res, temp);
		
	}
	if (minus) {
		res.insert(0, string("-"));
	}
	return res;
}

int main(int argc, char* argv[])
{
	string _a;
	string _b;


	string plus;
	string minus;
	string multi;


	cin >> _a;
	cin >> _b;



	if (_a[0] == '-' && _b[0] == '-') {
		// -A + -B = -A - B = (A + B) * -1
		plus = Plus(_a.substr(1, _a.size()), _b.substr(1, _b.size()));
		plus.insert(0, string("-"));
		// -A - -B = -A + B = B - A
		minus = Minus(_b.substr(1, _b.size()), _a.substr(1, _a.size()));
		multi = Multi(_a.substr(1, _a.size()), _b.substr(1, _b.size()));
	}
	else if (_a[0] == '-') {
		// -A + B = B - A
		plus = Minus(_b, _a.substr(1, _a.size()));
		// -A - B = (A + B) * -1
		minus = Plus(_a.substr(1, _a.size()), _b);
		minus.insert(0, string("-"));
		multi = Multi(_a.substr(1, _a.size()), _b, true);
	}
	else if (_b[0] == '-') {
		// A + -B = A - B
		plus = Minus(_a, _b.substr(1, _b.size()));
		// A - -B = A + B
		minus = Plus(_a, _b.substr(1, _b.size()));
		multi = Multi(_a, _b.substr(1, _b.size()), true);
	}
	else {
		plus = Plus(_a, _b);
		minus = Minus(_a, _b);
		multi = Multi(_a, _b);
	}

	cout << plus << endl;
	cout << minus << endl;
	cout << multi << endl;
}
