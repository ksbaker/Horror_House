#include "Player.h"
#include "World.h"
#include "InputHandler.h"
#include "OgreSceneManager.h"
#include "OgreSceneNode.h"
#include "Ogre.h"

Player::Player(World *world) : mWorld(world)
{
	tankEntity = world->SceneManager()->createEntity("Tank.mesh");
	mTank = world->SceneManager()->getRootSceneNode()->createChildSceneNode();
	mTank->attachObject(tankEntity);
	mTank->setPosition(0, 0, 20);
	mTank->scale(.5,.5,.5);
}


Player::~Player(void)
{
}


void 
Player::Think(float time, InputHandler *mInputHandler)
{

	const float RADIANS_PER_SECOND = 1;
	const float SPEED = 30;

	mInputHandler->mMouse->capture();

	int mx =mInputHandler->mMouse->getMouseState().X.rel;
	int my = mInputHandler->mMouse->getMouseState().Y.rel;
	mTank->yaw((Ogre::Degree) mx*-10 / 30, Ogre::Node::TS_WORLD);

	Ogre::Radian oldPitch = mTank->getOrientation().getPitch();
	Ogre::Radian newPitch = Ogre::Math::Abs((Ogre::Degree)(my*-10 / 30) + oldPitch);

	if(newPitch < Ogre::Radian(Ogre::Math::PI/2)) {
		mTank->pitch((Ogre::Degree) my*-10 / 30);
	}

	if (mInputHandler->IsKeyDown(OIS::KC_RIGHT))
	{
		mTank->translate(time * SPEED, 0, 0, Ogre::Node::TS_LOCAL);
	}
	else if (mInputHandler->IsKeyDown(OIS::KC_LEFT))
	{
		mTank->translate(-time * SPEED, 0, 0, Ogre::Node::TS_LOCAL);
	}
	if (mInputHandler->IsKeyDown(OIS::KC_UP))
	{
		mTank->translate(0, 0, -time * SPEED, Ogre::Node::TS_LOCAL);
	}
	else if (mInputHandler->IsKeyDown(OIS::KC_DOWN))
	{
		mTank->translate(0, 0, time * SPEED, Ogre::Node::TS_LOCAL);
	}

}