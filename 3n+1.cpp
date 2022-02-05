#include<iostream>
#include<stdio.h>

using namespace std;

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}
int countCycle(int a) {
	int result = 1;
	while (a != 1) {
		if (a % 2 == 0) a /= 2;
		else a = a * 3 + 1;
		result++;
	}
	return result;
}
int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) == 2) {
		cout << a << " " << b << " ";
		if (a > b) {
			swap(a, b);
		}
		int maximum = 0;
		for (int i = a; i <= b; i++) {
			maximum = max(maximum, countCycle(i));
		}
		cout << maximum << '\n';
	}
	return 0;
}