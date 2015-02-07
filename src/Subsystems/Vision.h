#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Vision: public Subsystem
{
private:
	NetworkTable* datatable;
public:
	Vision();
	void InitDefaultCommand();
};

#endif
