#pragma once
#include <vector>
#include <iostream>
#include "Character.h"

using namespace std;
class Node
{
public:
	vector<shared_ptr<Node>> _Children;
	Node(Character character);
	bool GetIsEndOfWorld();
	void SetIsEndOfWorld(bool IsEnd);
	
private:
	
	Character _Character;
	bool _IsEndOfWorld;
};

