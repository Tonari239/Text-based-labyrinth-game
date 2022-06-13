#ifndef __OPEN_COMMAND_H
#define __OPEN_COMMAND_H

#include "command.h"
#include "receiver.h"

class OpenCommand :public ICommand
{
private:
	Receiver& mReceiver;

public:
	OpenCommand(const Receiver& receiver);

	void execute() override;
	string toString() const override;

};
#endif