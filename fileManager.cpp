#include "fileManager.h"


string FileManager::getFileName() const
{
	return fileName;
}

void FileManager::setFileName(string name)
{
	name = fileName;
}

bool FileManager::getFileIsOpenStatus() const
{
	return fileIsOpen;
}

void FileManager::setFileIsOpenStatus(bool status)
{
	fileIsOpen = status;
}


void FileManager::help() const
{
	system("CLS");
	cout << "The following commands are supported: " << endl;
	cout <<"open <file>              opens <file> and enabled user to make changes to map" << endl;
	cout <<"close                    closes currently opened file" << endl;
	cout <<"save                     saves currently opened file" << endl;
	cout << "saveas <file>           saves currently opened file in <file>" << endl;
	cout << "help                    prints this information" << endl;
	cout << "exit                    exists program" << endl;
}

FileManager::FileManager() :fileIsOpen(false), fileName("")
{

}