﻿#include <iostream>
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

int main(){
	return 0;
	}
