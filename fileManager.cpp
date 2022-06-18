#include "fileManager.h"


string FileManager::getFileName() const
{
	return mCurentFileName;
}

void FileManager::setFileName(string name)
{
	name = mCurentFileName;
}

bool FileManager::getFileIsOpenStatus() const
{
	return fileIsOpen;
}

void FileManager::setFileIsOpenStatus(bool status)
{
	fileIsOpen = status;
}



FileManager::FileManager() :fileIsOpen(false), mCurentFileName("")
{

}

void FileManager::open(string fileName)
{
	setFileName(fileName);
	setFileIsOpenStatus(true);
}

void FileManager::close()
{
	if (getFileIsOpenStatus())
	{

	}
}
void FileManager::save()
{

}
void FileManager::saveAs(string newFileName)
{

}