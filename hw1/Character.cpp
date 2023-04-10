#include "Character.h"

Character::Character(const char character) : _CurrentCharacter(character) {}
char Character::GetCurrentCharacter() const
{
	return _CurrentCharacter;
}
;
