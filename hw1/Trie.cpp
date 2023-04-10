#include "Trie.h"
using namespace std;

Trie::Trie()
{
	_Root = shared_ptr<Node>(new Node('\0'));
}

void Trie::Insert(string word)
{
	shared_ptr<Node> current = _Root;
	for (size_t i = 0; i < word.length(); i++)
	{
		int currWord;
		if (word.at(i)!='\'')
		{
			currWord = word.at(i) - 'a';
		}
		else
		{
			currWord = 26;
		}
		if (current->_Children[currWord]==shared_ptr<Node>(nullptr))
		{
			current->_Children[currWord] = std::make_shared<Node>(Node(Character(word.at(i))));
		}
		current = (current->_Children[currWord]);
	}
	current->SetIsEndOfWorld(true);
}

bool Trie::Search(string word)
{
	shared_ptr<Node> current = _Root;
	for (size_t i = 0; i < word.length(); i++)
	{
		int currWord = word.at(i) - 'a';
		if (current->_Children[currWord] == shared_ptr<Node>(nullptr))
		{
			return false;
		}
		current = current->_Children[currWord];
	}
	if (current->GetIsEndOfWorld())
	{
		return true;
	}
	return false;
}
