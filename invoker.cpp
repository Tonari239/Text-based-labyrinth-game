#include "invoker.h"

Invoker::Invoker() : mCommands(vector<ICommand*>())
{

}

Invoker::Invoker(const std::vector<ICommand*> commands)
	: mCommands(commands)
{

}

Invoker::~Invoker()
{
	int length = mCommands.size();
	for (int i = 0; i < length; i++)
	{
		delete this->mCommands[i];
	}
	mCommands.clear();
}

void Invoker::addCommand(ICommand* command)
{
	mCommands.push_back(command);
}

void Invoker::execute(const string& commandName)
{
	int length = mCommands.size();
	for (int i = 0; i < length; i++)
	{
		if (mCommands[i]->toString() == commandName)
		{
			mCommands[i]->execute();
			return;
		}
	}
}