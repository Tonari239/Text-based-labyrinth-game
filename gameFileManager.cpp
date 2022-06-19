#include "GameFileManager.h"

bool GameFileManager::getUnsavedChanges() const
{
	return unsavedChanges;
}

string GameFileManager::getFileName() const
{
	return mCurentFileName;
}

void GameFileManager::setFileName(string name)
{
	name = mCurentFileName;
}

bool GameFileManager::getFileIsOpenStatus() const
{
	return fileIsOpen;
}

void GameFileManager::setFileIsOpenStatus(bool status)
{
	fileIsOpen = status;
}

void GameFileManager::setUnsavedChanges(bool status)
{
	unsavedChanges = status;
}

GameFileManager::GameFileManager() :fileIsOpen(false), mCurentFileName(""),unsavedChanges(false)
{

}

void GameFileManager::open(string fileName,Hero& hero,Map& map)
{
	setFileName(fileName);
	setFileIsOpenStatus(true);
	ifstream file;
	
	try
	{
		file.open(fileName);
	}
	catch (const std::exception&)
	{
		cout << "File opening failed!" << endl;
	}

	file >> hero;
	file >> map;
	cout << "Successfully opened " << fileName;
	try
	{
		file.close();
	}
	catch (const std::exception&)
	{

	}
	
}

void GameFileManager::close()
{
	if (fileIsOpen)
	{
		cout << "Successfully closed " << mCurentFileName;
	}
	fileIsOpen = false;
	mCurentFileName = "";
	unsavedChanges = false;
}

void GameFileManager::save(const Hero& hero,const Map& map)
{
	if (fileIsOpen)
	{
		ofstream file(mCurentFileName);
		file << hero;
		file << map;
		try
		{
			file.close();
		}
		catch (const std::exception&)
		{

		}
		unsavedChanges = false;
	}
	else
	{
		cout << "No file is currently open!" << endl;
	}
	
}

void GameFileManager::saveAs(string newFileName, const Hero& hero, const Map& map)
{
	if (fileIsOpen)
	{
		ofstream file(newFileName);
		file << hero;
		file << map;
		try
		{
			file.close();
		}
		catch (const std::exception&)
		{

		}
		unsavedChanges = false;
	}
	else
	{
		cout << "No file is currently open!" << endl;
	}
}