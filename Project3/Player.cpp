#include "Player.h"


Player::Player(void)
{
}


Player::~Player(void)
{
}


bool Player::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = Player::frameRenderingQueued(fe);
 
  mCamNode->translate(mDirection * fe.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
 
  return ret;
}
 

 
bool Player::mouseMoved(const OIS::MouseEvent& me)
{
  if (me.state.buttonDown(OIS::MB_Right))
  {
    mCamNode->yaw(Ogre::Degree(-mRotate * me.state.X.rel), Ogre::Node::TS_WORLD);
    mCamNode->pitch(Ogre::Degree(-mRotate * me.state.Y.rel), Ogre::Node::TS_LOCAL);
  }
 
  return true;
}


void 
Player::Think(float time)
{
}