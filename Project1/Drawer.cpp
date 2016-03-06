#include "Drawer.h"
#include "Inputs.h"

Drawer *Drawer::m_instance = nullptr;

Drawer::Drawer()
{
	cam = new Camera();
}

Drawer::~Drawer()
{
}

/**
* Init
*/
void Drawer::Init(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(SCREEN_POSITION_X, SCREEN_POSITION_Y);
	glutCreateWindow(SCREEN_TITLE);
	glutDisplayFunc(&ManagerDisplay_Static);
	glutReshapeFunc(&ManagerResize);
	glutMouseFunc(&Inputs::ManagerMouse_Static);
	glutKeyboardFunc(&Inputs::ManagerKeyboard_Static);
	glutKeyboardUpFunc(&Inputs::ManagerKeyboardUp_Static);
	glutIdleFunc(&InGame::Update_Static);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glutMainLoop();
}

Drawer *Drawer::Instance(void)
{
	if (m_instance == nullptr)
	{
		m_instance = new Drawer();
		m_instance->Init();
	}
	return m_instance;
}


void Drawer::Draw(AMap* map)
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			glPushMatrix();
			if (map->m_raw[y][x] == '1')
			{
				glColor3f(0, 1, 0);
			}
			else
			{
				glColor3f(0, 0, 0);
			}
			glTranslatef(-TILE_SIZE / 2, - TILE_SIZE/2, 0);

			glRectf( x * TILE_SIZE, y * TILE_SIZE,
				 (x + 1) * TILE_SIZE,  (y + 1) * TILE_SIZE);
			glPopMatrix();
		}
	}
	
}


void Drawer::Draw(Player* player)
{
	glPushMatrix();
	glTranslatef(player->transform.position.x * TILE_SIZE, player->transform.position.y * TILE_SIZE, 0);
	glColor3f(1, 0, 0);
	glRectf(-TILE_SIZE/2, -TILE_SIZE/2, TILE_SIZE/2, TILE_SIZE/2);
	glPopMatrix();
}

/**
* Display 3 squares on the screen, one rotating from left to right,
* another from right to left and the last reducing all their dimensions
* to 0 before recovering its original values.
*/
void Drawer::ManagerDisplay_Static(void)
{
	Instance()->ManagerDisplay();
}

void Drawer::ManagerDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(-cam->transform.position.x * TILE_SIZE, -cam->transform.position.y * TILE_SIZE, 0);
	Drawer::Instance()->Draw(InGame::Instance()->GetMap());
	Drawer::Instance()->Draw(InGame::Instance()->GetPlayer());
	glPopMatrix();
	glutSwapBuffers();
	glutPostRedisplay();
}

/**
* Allow the resizing of the window, perspective is not respected.
*/
void Drawer::ManagerResize(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-SCREEN_WIDTH / 2, SCREEN_WIDTH / 2, -SCREEN_HEIGHT / 2, SCREEN_HEIGHT / 2, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::Update()
{
	Vector3 v = InGame::Instance()->GetPlayer()->transform.position;
	transform.position = transform.position + (v - transform.position) * 0.1f;
}
