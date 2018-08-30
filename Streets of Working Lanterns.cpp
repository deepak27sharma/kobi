/*
** http://codeforces.com/gym/101149/problem/H **
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;

string inp;

int main() {
	bool impossible = false;
	cin >> inp;
	stack<int> openStack, qstack;
	int len = inp.length();
	if (len % 2 != 0 || len == 0) {
		impossible = true;
	}
	else {
		for (int i = 0; i < len; i++) {
			if (inp[i] == '(') {
				openStack.push(i);
			}
			else if (inp[i] == '?') {
				qstack.push(i);
			}
			else {
				if (!openStack.empty()) {
					openStack.pop();
				}
				else {
					if (qstack.empty()) {
						impossible = true;
						break;
					}
					else {
						int idx = qstack.top();
						inp[idx] = '(';
						qstack.pop();
					}
				}
			}
		}
	}
	if(openStack.size() > qstack.size()) impossible = true;
	while (!impossible && !openStack.empty()) {
		if (qstack.empty() || qstack.top() < openStack.top()) {
			impossible = true;
		}
		else {
			inp[qstack.top()] = ')';
			qstack.pop();
			openStack.pop();
		}
	}

    if (!impossible && !qstack.empty()) {
    	if (qstack.size() % 2 != 0) {
    		impossible = true;
    	}
    	else {
    		while (!qstack.empty()) {
    			int idx = qstack.top();
    			inp[idx] = ')';
    			qstack.pop();
    			idx = qstack.top();
    			inp[idx] = '(';
    			qstack.pop();
    		}
    	}
    }
    if (impossible) {
    	cout << "Impossible" << endl;
    }
    else {
    	cout << inp << endl;
    }
	return 0;
}