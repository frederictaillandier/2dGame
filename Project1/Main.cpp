/*
* main.cpp
*/

#include "InGame.h"
#include "Drawer.h"

/*
* Main
*/
int main(int ac, char* av[])
{
	glutInit(&ac, av);
	InGame::Instance()->Go();
	Drawer::Instance();
	return 0;
}