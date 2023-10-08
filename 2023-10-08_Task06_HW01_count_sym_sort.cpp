#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

struct comp
{
	template<typename T>
	bool operator()(const T& l, const T& r) const
	{
		if (l.second != r.second) {
			return l.second > r.second;
		}

		return l.first > r.first;
	}
};

int main() {

	string str{ "Hello world!!" };
	cout << "[IN]: " << str << endl << "[OUT]:" << endl;
	map<char, int> m;

	auto f_obj{ [&](char ch) { m[ch]++; } };

	for_each(begin(str), end(str), f_obj);

	set<pair<char, int>, comp> set(m.begin(), m.end());
    for (const auto& p : set) cout << p.first << ": " << p.second << endl;

	system("pause");
	return 0;
}