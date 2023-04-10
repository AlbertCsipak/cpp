#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"
#include "Character.h"
#include <algorithm>

using namespace std;

int main()
{
	ifstream inputFile("wordsEn.txt");
	Trie trie;
	while (!inputFile.eof())
	{
		string line;
		getline(inputFile, line);
		trie.Insert(line);
	}
	string input;
	getline(cin, input);
	input = input + " ";

	vector<string> words{};
	string space = " ";
	size_t pos = 0;
	while ((pos = input.find(space)) != string::npos) {
		words.push_back(input.substr(0, pos));
		input.erase(0, pos + space.length());
	}
	for (size_t i = 0; i < words.size(); i++)
	{
		if (trie.Search(words[i]))
		{
			cout << words[i] << " correct " << endl;
		}
		else
		{
			cout << words[i] << " incorrect " << endl;
		}
	}
}
