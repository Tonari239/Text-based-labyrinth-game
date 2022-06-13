#ifndef __FILE_MANAGER_H
#define __FILE_MANAGER_H

using namespace std;
#include <iostream>
class FileManager
{
	string fileName;
	bool fileIsOpen;

public:
	FileManager();
	void help() const;
	bool getFileIsOpenStatus() const;
	void setFileIsOpenStatus(bool status);
	string getFileName() const;
	void setFileName(string name);
};

#endif