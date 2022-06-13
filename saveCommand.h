#ifndef __SAVE_COMMAND_H
#define __SAVE_COMMAND_H


#include "command.h"
#include "receiver.h"

class SaveCommand :public ICommand
{
private:
	Receiver& mReceiver;

public:
	SaveCommand(const Receiver& receiver);

	void execute() override;
	string toString() const override;

};
#endif