#include "player.h"

player::player()
{
}

player::~player()
{
}
void player::Setname(void) { cin >> Pl_Name; };
string player::Getname(void) { return Pl_Name; };