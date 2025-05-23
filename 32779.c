#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	int questionSize = 0;
	cin >> questionSize;

	while (questionSize--) {
		long long powerConsumption = 0, useMinute = 0;
		cin >> powerConsumption >> useMinute;

		long long result = powerConsumption * useMinute * 1056;
		result = result / 600000;

		cout << result << endl;

	}
	return 0;
}
