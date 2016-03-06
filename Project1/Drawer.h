#pragma once
#include "AMap.h"
#include "GL/freeglut.h"
#include "InGame.h"



#define SCREEN_TITLE         "Square rotation by BadproG! :D"
#define SCREEN_WIDTH             1200
#define SCREEN_HEIGHT             600
#define SCREEN_POSITION_X        100
#define SCREEN_POSITION_Y         100
#define TILE_SIZE				50

class Camera : public Behaviour
{
public :
	Camera();
	~Camera();
	void Update();
};


class Drawer
{
	static Drawer *m_instance;

public:
	Drawer();
	~Drawer();
	static  Drawer *Instance(void);

	/*OPENGL SPECIFIC*/
	void Init(void);
	void Draw(AMap *map);
	void Draw(Player *player);
	static void ManagerDisplay_Static(void);
	void ManagerDisplay(void);
	static void ManagerResize(int, int);
	
	/*GAME SPECIFIC*/
	Camera *cam;
};

