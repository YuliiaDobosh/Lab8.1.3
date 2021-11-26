#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;


int Count(const char* str, const char* search_str)
{
	int c = 0;
	const char* p = strstr(str, search_str);
	for (; p != NULL; c++)
		p = strstr(str + (p - str) + strlen(search_str), search_str);

	return c;
}

void Replace(char* str, const char* search_str, const char* replace_str)
{
	const char* p = strstr(str, search_str);
	int offset;
	while (p != NULL)
	{
		for (int i = 0; replace_str[i] != '\0'; i++) {
			str[(p - str) + i] = replace_str[i];
		}

		offset = (p - str) + strlen(replace_str) + (strlen(search_str) - strlen(replace_str));
		for (int i = (p - str) + strlen(replace_str); str[i] != '\0'; i++, offset++)
			str[i] = str[offset];

		p = strstr(str, search_str);
	}
}

void main()
{
	char* str = new char[100];
	cin.getline(str, 101);

	cout << "Count words \"while\" are " << Count(str, "while") << endl;

	Replace(str, "while", "***");
	cout << str << endl;


}
