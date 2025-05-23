#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<char, int> map;
	map['U'] = 0; map['D'] = 0; map['P'] = 0; map['C'] = 0;

	string input; 
	cin >> input;

	for (int i = 0; i < input.size(); i++) { map[input[i]]++; }
	map['U'] += map['C'];
	map['D'] += map['P'];

	if (map['U'] > (map['D'] + 1) / 2) cout << "U";
	if (map['D'] > 0) cout << "DP";

	return 0;
}
