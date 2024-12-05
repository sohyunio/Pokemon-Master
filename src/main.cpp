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

int main()
{
	// choose pokemons
	int p1, p2;
	cout << "Choose a Pokemon(0~4): ";
	cin >> p1;
	cout << "Choose a Pokemon(0~4): ";
	cin >> p2;
	if (p1 == p2)  // same pokemon
	{
		cout << "You have to choose Pokemons different from each other.";
		exit(1);
	}

	Pokemon mon1(p1), mon2(p2);
	int turn = 0;
	// game loop
	while (true) {
		board(mon1, mon2, turn);
		turn = (turn + 1) % 2;  // next turn
		// check the winner
		if (mon1.HP <= 0)
		{
			cout << "===============================================================\n";
			cout << "Match Result: " << mon2.name << " defeats " << mon1.name << endl;
			break;
		}
		else if (mon2.HP <= 0)
		{
			cout << "===============================================================\n";
			cout << "Match Result: " << mon1.name << " defeats " << mon2.name << endl;
			break;
		}
	}

}
// initialize pokemon data
Pokemon::Pokemon(int p) {
	switch (p) {
	case 0:
		name = "Pikachu";
		type = ELECTRIC;
		HP = 35;
		skills[0] = skill("Tackle", NORMAL, 4, 5);
		skills[1] = skill("Grass Knot", GRASS, 8, 5);
		skills[2] = skill("Thunderbolt", ELECTRIC, 10, 5);
		skills[3] = skill("Megabolt", ELECTRIC, 15, 3);
		break;
	case 1:
		name = "Dratini";
		type = WATER;
		HP = 41;
		skills[0] = skill("Wrap", NORMAL, 4, 10);
		skills[1] = skill("Aqua Tail", WATER, 3, 5);
		skills[2] = skill("Water Pulse", WATER, 13, 2);
		skills[3] = skill("Hyper Beam", NORMAL, 20, 1);
		break;
	case 2:
		name = "Eevee";
		type = NORMAL;
		HP = 55;
		skills[0] = skill("Tackle", NORMAL, 4, 5);
		skills[1] = skill("Sand Attack", GROUND, 8, 3);
		skills[2] = skill("Bite", NORMAL, 12, 3);
		skills[3] = skill("Rain Dance", WATER, 15, 1);
		break;
	case 3:
		name = "Charmander";
		type = FIRE;
		HP = 39;
		skills[0] = skill("Tackle", NORMAL, 4, 5);
		skills[1] = skill("Flamethrower", FIRE, 11, 5);
		skills[2] = skill("Dig", GROUND, 7, 5);
		skills[3] = skill("Heat Wave", FIRE, 14, 5);
		break;
	case 4:
		name = "Palkia";
		type = WATER;
		HP = 90;
		skills[0] = skill("Hydro Pump", WATER, 12, 10);
		skills[1] = skill("Earth Power", GROUND, 15, 10);
		skills[2] = skill("Surf", WATER, 13, 10);
		skills[3] = skill("Spatial Rend", NORMAL, 30, 10);
		break;
	}
}

