#include <iostream>
#include <string>

int main() 
{
	std::string s;
	int res = 1;

	getline(std::cin, s);

	if (s.length() == 1 && s[0] == ' ') {
		std::cout << 0;
		return 0;
	}

	for (int i = 1; i < s.length() - 1; i++) {
		if (s[i] == ' ') res++;
	}

	std::cout << res;

	return 0;
}
 