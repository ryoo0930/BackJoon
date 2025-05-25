#include <iostream>
using namespace std;

int result[1000000] = { 0 };

void makeResult();

int main() {
	makeResult();

	while (true) {
		int targetCount = 0;
		cin >> targetCount;

		if (targetCount == 0) break;
		else cout << result[targetCount - 1] << endl;
	}

	return 0;
}

void makeResult() {
	int currentNumber = 1;
	int count = 0;
	for (int i = 0;; i++) {
		if (count == 1000000) break;
		int arr[10] = { 0 }; int temp = currentNumber;

		bool isSuccess = true;
		while (temp != 0) {
			if (arr[temp % 10] != 0) { isSuccess = false; break; }
			arr[temp % 10]++; temp = temp / 10;
		}

		if (isSuccess) { result[count] = currentNumber; count++; }
		currentNumber++;
	}
}
