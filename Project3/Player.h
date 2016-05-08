#pragma once

#include <ois/ois.h>
#include "Ogre.h"

class Player
{
public:
	Player(void);
	~Player(void);
	void Think(float time);

private:
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
 
	virtual bool mouseMoved(const OIS::MouseEvent& me);
 
	Ogre::Real mRotate;
	Ogre::Real mMove;
	Ogre::SceneNode* mCamNode;
	Ogre::Vector3 mDirection;
};

