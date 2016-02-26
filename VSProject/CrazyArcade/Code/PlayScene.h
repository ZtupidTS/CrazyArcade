#pragma once

#include "LGHead.h"
#include "Scene.h"
#include "Block.h"
#include "Role.h"
#include "Bubble.h"
#include "AI.h"

const int XLENGTH = 15;
const int YLENGTH = 13;

class PlayScene : public Scene
{
	SINGLETON(PlayScene);
public:
	//�������Ǽ̳�״̬��Ĵ��麯��
	void Enter(LGCenter*);
	void Execute(LGCenter*, float deltaTime = 0.0f);
	void Exit(LGCenter*);

	void ChangeMap(int posX, int posY, MapType::E_MapType blockType);
	void Explosion(int x, int y, int power);
private:
	void CreateMapBlock();
	void KeyboardControl();
	void CollisionDetection(Role* obj, float deltaTime);
	bool OnMessage(LGCenter* agent, const Telegram& msg);
	bool DestoryMapPos(int x, int y, Bubble::E_StateType stateType,Bubble::E_Direction direction);
private:
	MapType::E_MapType m_MapBlock[XLENGTH][YLENGTH]; //�����ͼ��ԭ�������½�
	Role* m_pPlayer;
	AI* m_pEnemy;
};