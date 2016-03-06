#include "Inputs.h"
#include <iostream>
#include "InGame.h"
#include "Behaviour.h"
#include "Drawer.h"


Inputs *Inputs::m_instance = nullptr;

Inputs::Inputs()
{
	for (int i = 0; i < 128; ++i)
		keys[i] = false;

}


Inputs::~Inputs()
{
}


Inputs *Inputs::Instance(void)
{
	if (m_instance == nullptr)
	{
		m_instance = new Inputs();

	}
	return m_instance;
}


/**
* Manage the mouse, if the left button is clicked, we revive the animation.
* If the right button is clicked, we stop the animation.
*/
void Inputs::ManagerMouse_Static(int button, int state, int x, int y)
{
	Instance()->ManagerMouse(button, state, x, y);
}

void Inputs::ManagerMouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
		}
		//glutIdleFunc(&ManagerIdle);
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
		{
		}
		//glutIdleFunc(nullptr);
		break;
	default:
		break;
	}
	(void)(x);
	(void)(y);
}

/**
* Manage the keyboard, 27 = ESC key.
*/
void Inputs::ManagerKeyboard_Static(unsigned char key, int x, int y)
{
	Instance()->ManagerKeyboard(key, x, y);
}

void Inputs::ManagerKeyboard(unsigned char key, int x, int y)
{
	keys[key] = true;
	switch (key)
	{
	case 27:
	{
			   exit(0);
			   break;
	}
		
	}
	(void)(x);
	(void)(y);
}

void Inputs::ManagerKeyboardUp_Static(unsigned char key, int x, int y)
{
	Instance()->ManagerKeyboardUp(key, x, y);
}

void Inputs::ManagerKeyboardUp(unsigned char key, int x, int y)
{
	keys[key] = false;
	switch (key)
	{
	case 27:
	{
			   exit(0);
			   break;
	}
		
	}
	(void)(x);
	(void)(y);
}