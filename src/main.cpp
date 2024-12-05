#include <iostream>
#include <string>
using namespace std;

// interaction effecs in type
const int TYPE[6][6] =
{ {0, 0, 0, 0, 0, 0},
	{0, 0, 5, 0,-3, 5},
	{0,-3,-3, 5,-3, 0},
	{0, 5, 0,-3,-3, 5},
	{0,-3, 0, 5,-3,-3},
	{0, 0, 0,-3, 5,-3} };
	
// type const
const char NORMAL = 0;
const char GROUND = 1;
const char ELECTRIC = 2;
const char WATER = 3;
const char GRASS = 4;
const char FIRE = 5;
// type naes as strings
string type[6] = { "Normal", "Ground", "Electric", "Water", "Grass", "Fire" };

// define skill
class skill {
public:
	string name;
	int type;
	int damage;
	int maxTry;
	int count = maxTry;
	skill() : name(""), type(0), damage(0), maxTry(0), count(0) {} // default constructor
	skill(string n, int t, int d, int m)  // parameterized constructor
		: name(n), type(t), damage(d), maxTry(m), count(m) {}
};

class Pokemon {
public:
	Pokemon(int p);  // constructor
	int HP_change(int damage, int attacktype);  // modify pokemon's HP
	int skill_count(int attacktype);  // reduce count of used skill
	string effectiveness(Pokemon mon, int attacktype);  // effectiveness of attack

	string name;
	int HP;
	int type;
	int skill_data = -1;
	skill skills[4];
};

// display battle board
void board(Pokemon &p1, Pokemon &p2, int turn);

int main(){
	return 0;
	}
