/**
* BadprogRotate.cpp
*/


#include "InGame.h"

InGame *InGame::m_instance = nullptr;

/**
* Constructor
*/
InGame::InGame() 
{	
	m_instance = this;
	m_map = new AMap();
	m_player = new Player();
}

/**
* Deleting
*/
InGame::~InGame() {}

InGame *InGame::Instance(void)
{
	if (m_instance == nullptr)
	{
		new InGame();
		m_instance->Init();
	}
	return m_instance;
}

void InGame::Go(void)
{
}

void InGame::Init(void)
{

}

AMap *InGame::GetMap()
{
	return m_map;
}

Player *InGame::GetPlayer()
{
	return m_player;
}

/**
* What's happening when the animation is activated.
For Windows, replace usleep() by Sleep().
*/
void InGame::Update_Static(void)
{
	InGame::Instance()->Update();
}

void InGame::Update(void)
{
	for (std::list<Behaviour*>::iterator it = Behaviours.begin(); it != Behaviours.end(); ++it)
	{
		(*it)->Update();
	}
	Sleep(16); // change it to  Sleep(5.0); for Windows
}

void InGame::AddBehaviour(Behaviour *b)
{
	Behaviours.push_front(b);
}