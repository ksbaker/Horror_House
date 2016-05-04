#ifndef __MainMenu_h_
#define __MainMenu_h_

namespace Ogre
{
	class Overlay;
}

class MainMenu 
{
public:
	MainMenu();
	
	void displayMenu();
	void hideMenu();
	void changeOption();
	void release();

private:
	bool playSelected;
	bool released;
	Ogre::Overlay *mOverlay;
	Ogre::Overlay *mPlayButtonOverlay;
	Ogre::Overlay *mExitButtonOverlay;
};

#endif