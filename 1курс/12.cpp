#include <iostream>
#include<string>
using namespace std;

bool checkSymmetry(string text, int start_index, int end_index) {
	if (start_index >= end_index)
		return true;
	if (text[start_index] != text[end_index])
		return false;
	return checkSymmetry(text, start_index + 1, end_index - 1);
}

int main()
{
	string input_string;
	getline(cin, input_string);

	if (checkSymmetry(input_string, 0, input_string.length() - 1))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}