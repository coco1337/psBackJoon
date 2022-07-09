#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

string str, t;
set<string> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		for (int j = 1; j <= str.size() - i; ++j)
		{
			t = "";
			for (int k = 0; k < j; ++k)
			{
				t += str[i + k];
			}
			s.insert(t);
		}
 	}

	cout << s.size();

	return 0;
}