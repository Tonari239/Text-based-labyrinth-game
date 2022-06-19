#ifndef __FILE_MANAGER_H
#define __FILE_MANAGER_H

using namespace std;
#include <iostream>
#include "fstream"

#include "hero.h"
#include "map.h"
class GameFileManager
{
	string mCurentFileName;
	bool fileIsOpen;
	bool unsavedChanges;

public:
	GameFileManager();
	void open(string fileName, Hero& hero, Map& map);
	void close();
	void save(const Hero& hero, const Map& map);
	void saveAs(string newFileName, const Hero& hero, const Map& map);
	bool getFileIsOpenStatus() const;
	void setFileIsOpenStatus(bool status);
	void setUnsavedChanges(bool status);
	bool getUnsavedChanges() const;
	string getFileName() const;
	void setFileName(string name);
};

#endif