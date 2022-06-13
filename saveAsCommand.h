#ifndef __SAVE_AS_COMMAND_H
#define __SAVE_AS_COMMAND_H

#include "command.h"
#include "receiver.h"

class SaveAsCommand :public ICommand
{
private:
	Receiver& mReceiver;

public:
	SaveAsCommand(const Receiver& receiver);

	void execute() override;
	string toString() const override;

};
#endif