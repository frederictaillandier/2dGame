/*
* BadprogRotate.h
*/

#ifndef BADPROGROTATE_H_
#define BADPROGROTATE_H_

#include "GL/freeglut.h"

#include <string>

#define SCREEN_TITLE         "Square rotation by BadproG! :D"
#define SCREEN_WIDTH             600
#define SCREEN_HEIGHT             600
#define SCREEN_POSITION_X        100
#define SCREEN_POSITION_Y         100

class BadprogRotate {
public:
	static GLfloat S_ANGLE;

	BadprogRotate(int *ac, char *av[]);
	virtual ~BadprogRotate();

	void init(void);
	static void managerDisplay(void);
	static void managerIdle(void);
	static void managerResize(int, int);
	static void managerMouse(int, int, int, int);
	static void managerKeyboard(unsigned char, int, int);
};

#endif /* BADPROGROTATE_H_ */