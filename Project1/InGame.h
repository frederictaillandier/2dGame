/*
* BadprogRotate.h
*/

#ifndef INGAME_H_
#define INGAME_H_


#include "AMap.h"
#include "Player.h"
#include "Windows.h"
#include <string>
#include <list>


class InGame;

class InGame {
	AMap *m_map;
	Player *m_player;
	std::list<Behaviour *> Behaviours;

	static InGame * m_instance;
public:

	static InGame *Instance(void);
	/*get set*/
	AMap *GetMap();
	Player *GetPlayer();

	InGame();
	virtual ~InGame();
	void Init();
	void Go(void);
	static void Update_Static(void);
	void Update();
	void AddBehaviour(Behaviour *b);
};

#endif /* INGAME_H_ */