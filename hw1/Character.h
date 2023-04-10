#pragma once
class Character
{
public:
	Character(const char character);
	char GetCurrentCharacter() const;
private:
	char _CurrentCharacter;
};

