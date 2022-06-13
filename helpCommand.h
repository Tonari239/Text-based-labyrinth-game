#ifndef __HELP_COMMAND_H
#define __HELP_COMMAND_H

#include "command.h"
#include "receiver.h"

class HelpCommand :public ICommand
{
private:
	Receiver& mReceiver;

public:
	HelpCommand(const Receiver& receiver);

	void execute() override;
	string toString() const override;

};

#endif