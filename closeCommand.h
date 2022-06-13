#ifndef __CLOSE_COMMAND_H
#define __CLOSE_COMMAND_H


#include "command.h"
#include "receiver.h"

class CloseCommand :public ICommand
{
private:
	Receiver& mReceiver;

public:
	CloseCommand(const Receiver& receiver);

	void execute() override;
	string toString() const override;

};

#endif