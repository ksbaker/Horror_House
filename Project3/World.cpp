// My header file.  This should go first!
#include "World.h"

// Ogre header files
#include "Ogre.h"
#include "OgreMath.h"
#include "OgreSceneManager.h"
#include "OgreSceneNode.h"
#include "OgreOverlayManager.h"
#include "OgreOverlay.h"
#include "OgreFontManager.h"
#include "OgreTextAreaOverlayElement.h"
#include "OgreRenderWindow.h"

// IOS (Input system) header files

#include <ois/ois.h>

// Other input files for my project
#include "Camera.h"
#include "InputHandler.h"

World::World(Ogre::SceneManager *sceneManager, InputHandler *input) : mSceneManager(sceneManager), mInputHandler(input)
{
	mSceneManager->setAmbientLight(Ogre::ColourValue(1,1,1));
	//mInputManager = OIS::InputManager::createInputSystem((size_t)m_scMainWindow().GetWindowHandle());

	// Yeah, this should be done automatically for all fonts referenced in an overlay file.
	//  But there is a bug in the OGRE code so we need to do it manually.
	Ogre::ResourceManager::ResourceMapIterator iter = Ogre::FontManager::getSingleton().getResourceIterator();
	while (iter.hasMoreElements()) 
	{ 
		iter.getNext()->load(); 
	}

	Ogre::Entity *NorthWall = SceneManager()->createEntity("NorthWall.mesh");
	Ogre::Entity *EastWall = SceneManager()->createEntity("EastWall.mesh");
	Ogre::Entity *SouthWall = SceneManager()->createEntity("SouthWall.mesh");
	Ogre::Entity *WestWall = SceneManager()->createEntity("WestWall.mesh");

	Ogre::SceneNode *nWall = SceneManager()->getRootSceneNode()->createChildSceneNode();
	nWall->attachObject(NorthWall);
	nWall->setPosition(0,0,0);
	nWall->scale(5,5,5);

	Ogre::SceneNode *eWall = SceneManager()->getRootSceneNode()->createChildSceneNode();
	eWall->attachObject(EastWall);
	eWall->setPosition(0,0,0);
	eWall->scale(5,5,5);

	Ogre::SceneNode *sWall = SceneManager()->getRootSceneNode()->createChildSceneNode();
	sWall->attachObject(SouthWall);
	sWall->setPosition(0,0,0);
	sWall->scale(5,5,5);

	Ogre::SceneNode *wWall = SceneManager()->getRootSceneNode()->createChildSceneNode();
	wWall->attachObject(WestWall);
	wWall->setPosition(0,0,0);
	wWall->scale(5,5,5);

	tankEntity = SceneManager()->createEntity("Tank.mesh");
	mTank = SceneManager()->getRootSceneNode()->createChildSceneNode();
	mTank->attachObject(tankEntity);
	mTank->setPosition(0, 0, 20);
	mTank->scale(.5,.5,.5);

	// Now we will show the sample overlay.  Look in the file Content/Overlays/Example to
	// see how this overlay is defined
	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	Ogre::Overlay *overly = om.getByName("Sample");
	overly->show();
}

void 
World::Think(float time)
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
	else
	{
		Ogre::Radian o = oldPitch;
		Ogre::Radian r = newPitch;
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


	mCamera->setPositionFromGhostPosition(mTank->getOrientation(), mTank->getPosition());
	mCamera->setOrientationFromGhostOrientation(mTank->getOrientation());
}


