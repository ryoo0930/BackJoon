#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int breed = 0;
	cin >> breed;

	unordered_map<int, char> breedArr;
	for (int i = 0; i < breed; i++) {
		char color; cin >> color;
		breedArr[i] = color;
	}

	int people, hasBreed;
	cin >> people >> hasBreed;

	unordered_map<int, char> resultArr;
	for (int i = 0; i < people; i++) {
		bool purple = false;
		int color;
		for (int j = 0; j < hasBreed; j++) {
			cin >> color;
			if (breedArr[color - 1] == 'P') purple = true;
		}

		if (purple) resultArr[i] = 'P';
		else resultArr[i] = 'W';
	}
	
	char result = 'P';
	for (int i = 0; i < people; i++) {
		if (resultArr[i] == 'W') result = 'W';
	}
	cout << result;

	return 0;
}
