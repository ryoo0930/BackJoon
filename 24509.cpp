#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int arrSize = 0; cin >> arrSize;
	vector<int> StudentId;
	vector<int> Korean;
	vector<int> English;
	vector<int> Math;
	vector<int> Science;

	for (int i = 0; i < arrSize; i++) {
		int studentId, korean, english, math, science;
		cin >> studentId >> korean >> english >> math >> science;

		StudentId.push_back(studentId); Korean.push_back(korean); English.push_back(english); Math.push_back(math); Science.push_back(science);
	}

	int KoreanMax = -1, EnglishMax = -1, MathMax = -1, ScienceMax = -1;
	int KoreanMaxIndex = -1, EnglishMaxIndex = -1, MathMaxIndex = -1, ScienceMaxIndex = -1;

	for (int i = 0; i < arrSize; i++) {
		if (KoreanMax < Korean[i]) { KoreanMax = Korean[i]; KoreanMaxIndex = i; }
		else if (KoreanMax == Korean[i]) { if (StudentId[KoreanMaxIndex] > StudentId[i]) KoreanMaxIndex = i; }
	}

	for (int i = 0; i < arrSize; i++) {
		if (EnglishMax < English[i] && KoreanMaxIndex != i) { EnglishMax = English[i]; EnglishMaxIndex = i; }
		else if (EnglishMax == English[i] && KoreanMaxIndex != i) { if (StudentId[EnglishMaxIndex] > StudentId[i]) EnglishMaxIndex = i; }
	}

	for (int i = 0; i < arrSize; i++) {
		if (MathMax < Math[i] && KoreanMaxIndex != i && EnglishMaxIndex != i) { MathMax = Math[i]; MathMaxIndex = i; }
		else if (MathMax == Math[i] && KoreanMaxIndex != i && EnglishMaxIndex != i) { if (StudentId[MathMaxIndex] > StudentId[i]) MathMaxIndex = i; }
	}

	for (int i = 0; i < arrSize; i++) {
		if (ScienceMax < Science[i] && KoreanMaxIndex != i && EnglishMaxIndex != i && MathMaxIndex != i) { ScienceMax = Science[i]; ScienceMaxIndex = i; }
		else if (ScienceMax == Science[i] && KoreanMaxIndex != i && EnglishMaxIndex != i && MathMaxIndex != i) { if (StudentId[ScienceMaxIndex] > StudentId[i]) ScienceMaxIndex = i; }
	}

	cout << StudentId[KoreanMaxIndex] << " " << StudentId[EnglishMaxIndex] << " " << StudentId[MathMaxIndex] << " " << StudentId[ScienceMaxIndex] << endl;
	return 0;
}
