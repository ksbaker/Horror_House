#pragma once

#include <ois/ois.h>
#include "Ogre.h"

class World;
class InputHandler;

class Player
{
public:
	Player(World *world);
	~Player(void);
	void Think(float time, InputHandler *mInputHandler);

	Ogre::SceneManager *SceneManager() { return mSceneManager; }


	Ogre::SceneNode *mTank;
	Ogre::Entity *tankEntity;

private:

	World *mWorld;
	
 
	Ogre::SceneManager *mSceneManager;
	Ogre::Real mRotate;
	Ogre::Real mMove;
	Ogre::SceneNode* mCamNode;
	Ogre::Vector3 mDirection;
};

