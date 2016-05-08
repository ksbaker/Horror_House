#ifndef __World_h_
#define __World_h_

// Forward delcarations of Ogre classes.  Note the Ogre namespace!
namespace Ogre {
    class SceneNode;
    class SceneManager;
	class Entity;
}

// Forward delcarations of our own classes
class GhostCamera;
class InputHandler;


class World
{
public:
	
    World(Ogre::SceneManager *sceneManager, InputHandler *input);

    // You'll want various methods to access & change your world here
    void Think(float time);
	void addCamera(GhostCamera *c) { mCamera = c; }

	Ogre::SceneManager *SceneManager() { return mSceneManager; }
	Ogre::SceneNode *flashLight;
	Ogre::SceneNode *nWall;
	Ogre::SceneNode *LightNode;

protected:


	Ogre::SceneManager *mSceneManager;

	InputHandler *mInputHandler;
	GhostCamera *mCamera;

	// Here is where you keep all your world data.
	//  You probably want to use containers (arrays / lists / classes / etc) to ogranize them, 
	//    instead of a whole list of variables.  

};

#endif