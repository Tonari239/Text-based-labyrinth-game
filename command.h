#ifndef __ICOMMAND_H
#define __ICOMMAND_H

#include <string>
using namespace std;

class ICommand
{
public:
	virtual void execute() = 0;
	virtual string toString() const = 0;
};

#endif