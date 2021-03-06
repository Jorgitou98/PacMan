#include "Level_Load.h"

Level::Level()
{
	row = 0;
	col = 0;
	elem = nullptr;
}

void Level::LoadLevel(const int & r, const int & c)
{
	std::ifstream file;
	char aux;
	tGame_Element aux1;

	elem = new tGame_Element * [r];
	for (int i = 0; i < r; ++i) {
		elem[i] = new tGame_Element[c];
	}

	file.open(LEVEL_PATH);
	if (file.is_open()) {
		file.get(aux);
		if (!file.eof()) {
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < c; ++j) {
					aux1 = CharacterTransform(aux);
					elem[i][j] = aux1;
					file.get(aux);
				}
			}
		}	
	}
	file.close();
}

void Level::SetSize(const int & r, const int & c) {
	row = r;
	col = c;
}

int Level::GetRow() const {
	return row;
}

int Level::GetCol() const {
	return col;
}

Level::~Level()
{
	delete[] elem;
}

tGame_Element CharacterTransform(const char& c) {
	tGame_Element aux;
	switch (c)
	{
	case 'a': aux = CLOSED_WALL;
		break;
	case 'b': aux = HORIZ_OPEN_WALL;
		break;
	case 'c': aux = VERT_OPEN_WALL;
		break;
	case 'd': aux = CLOSED_WALL_3_0DEG;
		break;
	case 'e': aux = CLOSED_WALL_3_90DEG;
		break;
	case 'f': aux = CLOSED_WALL_3_180DEG;
		break;
	case 'g': aux = CLOSED_WALL_3_270DEG;
		break;
	case 'h': aux = CLOSED_WALL_2_0DEG;
		break;
	case 'i': aux = CLOSED_WALL_2_90DEG;
		break;
	case 'j': aux = CLOSED_WALL_2_180DEG;
		break;
	case 'k': aux = CLOSED_WALL_2_270DEG;
		break;
	case 'l': aux = CLOSED_WALL_1_0DEG;
		break;
	case 'm': aux = CLOSED_WALL_1_90DEG;
		break;
	case 'n': aux = CLOSED_WALL_1_180DEG;
		break;
	case 'o': aux = CLOSED_WALL_1_270DEG;
		break;
	case 'p': aux = INTERIOR_WALL;
		break;
	case 'q': aux = BLUE_GHOST;
		break;
	case 'r': aux = RED_GHOST;
		break;
	case 's': aux = ORANGE_GHOST;
		break;
	case 't': aux = PINK_GHOST;
		break;
	case 'u': aux = CHERRY;
		break;
	case 'v': aux = PINEAPPLE;
		break;
	case 'P': aux = PLAYER;
		break;
	case '.': aux = PELLET;
		break;
	case '+': aux = POWER_UP;
		break;
	default:
		aux = ERROR;
	}
	return aux;
}
