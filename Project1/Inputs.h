#pragma once
#include "GL/freeglut.h"

class Inputs
{
public:
	Inputs();
	~Inputs();

	bool keys[128];

	static Inputs * m_instance;

	static Inputs *Instance(void);
	static void ManagerMouse_Static(int button, int state, int x, int y);
	static void ManagerKeyboard_Static(unsigned char key, int x, int y);
	static void ManagerKeyboardUp_Static(unsigned char key, int x, int y);
	void ManagerKeyboard(unsigned char key, int x, int y);
	void ManagerKeyboardUp(unsigned char key, int x, int y);
	void ManagerMouse(int button, int state, int x, int y);
};

