#ifndef __EXIT_COMMAND_H
#define __EXIT_COMMAND_H

#include "command.h"
#include "receiver.h"

class ExitCommand :public ICommand
{
private:
	Receiver& mReceiver;

public:
	ExitCommand(const Receiver& receiver);

	void execute() override;
	string toString() const override;

};

#endif