#ifndef __FILE_MANAGER_H
#define __FILE_MANAGER_H

using namespace std;
#include <iostream>
class FileManager
{
	string mCurentFileName;
	bool fileIsOpen;

public:
	FileManager();
	void open(string fileName);
	void close();
	void save();
	void saveAs(string newFileName);
	bool getFileIsOpenStatus() const;
	void setFileIsOpenStatus(bool status);
	string getFileName() const;
	void setFileName(string name);
};

#endif