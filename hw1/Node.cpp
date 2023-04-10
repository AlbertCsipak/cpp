#include "Node.h"
#include "Character.h"

Node::Node(Character character) : _Character(character), _IsEndOfWorld(false)
{
	for (size_t i = 0; i < 27; i++)
	{
		_Children.push_back(std::shared_ptr<Node>());
	}
}

//std::vector<std::shared_ptr<Node>> Node::GetChildren()
//{
//	return _Children;
//}
bool Node::GetIsEndOfWorld()
{
	return _IsEndOfWorld;
}
void Node::SetIsEndOfWorld(bool IsEnd)
{
	_IsEndOfWorld = true;
}
