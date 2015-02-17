#ifndef SRC_VISION_H_
#define SRC_VISION_H_

#include "WPILib.h"

class Vision
{
public:
	Vision();
	virtual ~Vision();
	void SendImage();
private:
	IMAQdxSession session;
	Image *frame;
	IMAQdxError imaqError;
};

#endif /* SRC_VISION_H_ */
