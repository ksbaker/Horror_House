#include "MainMenu.h"

#include "OgreOverlay.h"
#include "OgreOverlayManager.h"
#include "OgreOverlayContainer.h"
#include "OgreTextAreaOverlayElement.h"

MainMenu::MainMenu()
{
	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	mOverlay = om.getByName("GameTitle");
	mPlayButtonOverlay = om.getByName("PlayButton");
	mExitButtonOverlay= om.getByName("ExitButton");
	playSelected = true;
	released = true;

	Ogre::TextAreaOverlayElement *te = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("PlayButton/Panel/Text1");
	te->setCaption("> PLAY <");

	Ogre::TextAreaOverlayElement *te2 = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("ExitButton/Panel/Text1");
	te2->setCaption("  EXIT  ");
}

void MainMenu::displayMenu()
{
	mOverlay->show();
	mPlayButtonOverlay->show();
	mExitButtonOverlay->show();
}

void MainMenu::hideMenu()
{
	mOverlay->hide();
	mPlayButtonOverlay->hide();
	mExitButtonOverlay->hide();
}

void MainMenu::changeOption()
{
	if (released)
	{
		if (playSelected)
		{
			playSelected = false;

			Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
			Ogre::TextAreaOverlayElement *te = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("PlayButton/Panel/Text1");
			te->setCaption("> PLAY <");

			Ogre::TextAreaOverlayElement *te2 = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("ExitButton/Panel/Text1");
			te2->setCaption("  EXIT  ");
		}
		else
		{
			playSelected = true;

			Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
			Ogre::TextAreaOverlayElement *te = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("PlayButton/Panel/Text1");
			te->setCaption("  PLAY  ");

			Ogre::TextAreaOverlayElement *te2 = (Ogre::TextAreaOverlayElement *) om.getOverlayElement("ExitButton/Panel/Text1");
			te2->setCaption("> EXIT <");
		}
		released = false;
	}
}

void MainMenu::release()
{
	released = true;
}