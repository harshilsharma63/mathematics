#include <iostream>
using namespace std;

unsigned long long reverseNumber(unsigned long long number) {
    unsigned long long reverse = 0;
    while(number)
    {
        reverse *= 10;
        reverse += number % 10;
        number /= 10;
    }
    return reverse;
}

bool isPalindrome(unsigned long long number) {
	return number == reverseNumber(number);
}

int main() {
	unsigned long long number, reverse;
	cout << "Enter a number: ";
	cin >> number;
	reverse = reverseNumber(number);

	unsigned int steps = 0;
	while (!isPalindrome(number)) {
		++steps;
		cout << number << " + " << reverse << " = " << (number + reverse) << "\n";
		number += reverseNumber(number);
		reverse = reverseNumber(number);
	}
	cout << "\n\nTotal steps required: " << steps << "\n";

	return 0;
}

// 98765436788097654 - 248 steps