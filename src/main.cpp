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

// update HP value
int Pokemon::HP_change(int damage, int attacktype = 0) {
	if (damage == 0) {
		return HP;
	}
	HP -= damage + TYPE[attacktype][type];
	return HP;
}

// print game board
void board(Pokemon &p1, Pokemon &p2, int turn) {
	// title
	string temp = "+";
	temp.resize(62, '-');
	cout << temp << "+" << endl;
	cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
	// Pokemon info
	// first line print
	temp = "";
	temp.resize(30, '-');
	cout << "+" << temp << "+" << temp << "+" << endl;

	// name
	temp = "| ";
	temp.append(p1.name);
	if (turn == 0)
		temp.append(" (*)");
	temp.resize(31, ' ');
	temp.append("| ").append(p2.name);
	if (turn == 1)
		temp.append(" (*)");
	temp.resize(62, ' ');
	cout << temp << "|\n";
	// type
	temp = "| Type: ";
	temp.append(type[p1.type]);
	temp.resize(31, ' ');
	temp.append("| Type: ").append(type[p2.type]);
	temp.resize(62, ' ');
	cout << temp << "|\n";
	// HP
	temp = "| HP: ";
	temp.append(to_string(p1.HP)); // here
	temp.resize(31, ' ');
	temp.append("| HP: ").append(to_string(p2.HP));
	temp.resize(62, ' ');
	cout << temp << "|\n";

	// second line print
	temp = "";
	temp.resize(30, '-');
	cout << "+" << temp << "+" << temp << "+" << endl;
	// latest skill --- > 수정하기
	temp = "| Latest Skill: ";
	if (p1.skill_data == -1)
		temp.append("-");
	else
		temp.append(p1.skills[p1.skill_data].name);
	temp.resize(31, ' ');
	temp.append("| Latest Skill: ");
	if (p2.skill_data == -1)
		temp.append("-");
	else
		temp.append(p2.skills[p2.skill_data].name);
	temp.resize(62, ' ');
	cout << temp << "|\n";
	// effectivess
	temp = "| ";
	if (p1.skill_data != -1) {
		temp.append(p1.effectiveness(p2, p1.skills[p1.skill_data].type));
	}
	temp.resize(31, ' ');
	temp.append("| ");
	if (p2.skill_data != -1) {
		temp.append(p2.effectiveness(p1, p2.skills[p2.skill_data].type));
	}
	temp.resize(62, ' ');
	cout << temp << "|\n";
	// third line print
	temp = "";
	temp.resize(30, '-');
	cout << "+" << temp << "+" << temp << "+" << endl;
	// print all skills
	for (int i = 0; i < 4; i++) {
		temp = "";
		temp.append("| (").append(to_string(i)).append( ") ").append(p1.skills[i].name);
		temp.resize(31, ' ');
		temp.append("| (").append(to_string(i)).append(") ").append(p2.skills[i].name);
		temp.resize(62, ' ');
		cout << temp << "|\n";

		temp = "|     - Type: ";
		temp.append(type[p1.skills[i].type]);
		temp.resize(31, ' ');
		temp.append("|     - Type: ").append(type[p2.skills[i].type]);
		temp.resize(62, ' ');
		cout << temp << "|\n";

		temp = "|     - Damage: ";
		temp.append(to_string(p1.skills[i].damage));
		temp.resize(31, ' ');
		temp.append("|     - Damage: ").append(to_string(p2.skills[i].damage));
		temp.resize(62, ' ');
		cout << temp << "|\n";

		temp = "|     - Count: ";
		temp.append(to_string(p1.skills[i].count)).append("(").append(to_string(p1.skills[i].maxTry)).append(")");
		temp.resize(31, ' ');
		temp.append("|     - Count: ").append(to_string(p2.skills[i].count)).append("(").append(to_string(p2.skills[i].maxTry)).append(")");
		temp.resize(62, ' ');
		cout << temp << "|\n";
	}
	// last line print
	temp = "";
	temp.resize(30, '-');
	cout << "+" << temp << "+" << temp << "+" << endl;

	// next turn
	int skillNum;
	cout << "Choose a skill (0~3): ";
	cin >> skillNum;
	if (turn == 0)
	{
		p1.skill_data = skillNum;
		if (p1.skill_count(skillNum)) {
			cout << p1.name << " used " << p1.skills[skillNum].name << ".\n";
			cout << p1.effectiveness(p2, p1.skills[skillNum].type) << "\n\n";
			p2.HP_change(p1.skills[skillNum].damage, p1.skills[skillNum].type);
		}
	}
	else
	{
		p2.skill_data = skillNum;
		if (p2.skill_count(skillNum)) {
			cout << p2.name << " used " << p2.skills[skillNum].name << ".\n";
			cout << p2.effectiveness(p1, p2.skills[skillNum].type) << "\n\n";
			p1.HP_change(p2.skills[skillNum].damage, p2.skills[skillNum].type);
		}
	}

}

// check skill count
int Pokemon::skill_count(int attacktype) {
	skill_data = attacktype;
	if (skills[attacktype].count == 0) {
		cout << name << " failed to perform " << skills[attacktype].name << ".\n\n";
		return 0;
	}
	skills[attacktype].count--;
	return 1;
}

