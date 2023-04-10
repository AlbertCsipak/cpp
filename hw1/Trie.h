#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

class Trie
{
public:
	Trie();
	void Insert(const string word);
	bool Search(const string word);
private:
	shared_ptr<Node> _Root;
};

