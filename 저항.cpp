#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

int main() {
	
	map<string, int> r = {
	{ "black",0 },
	{ "brown",1 },
	{ "red",2 },
	{ "orange",3 },
	{ "yellow",4 },
	{ "green",5 },
	{ "blue",6 },
	{ "violet",7 },
	{ "grey",8 },
	{ "white",9 },
	};

	string s[3];
	for (int i = 0; i < 3; i++) {
		cin >> s[i];
	}
	long long int r1;
	long long int r2;
	long long int m=1;
		r1 = r[s[0]]*10;
		r2 = r[s[1]];
		for (int i = 0; i < r[s[2]]; i++) {
			m = m * 10;
		}
		long long result = (r1 + r2)*m;
		printf("%lld",result);
}