#include "WPILib.h"
#include "Vision.h"

/**
 * Uses IMAQdx to manually acquire a new image each frame, and annotate the image by drawing
 * a circle on it, and show it on the FRC Dashboard.
 */
class VR : public SampleRobot
{

public:
	void RobotInit();
	void OperatorControl();
private:
	Vision* vision;
};

void VR::RobotInit()
{
	vision = new Vision();
}

void VR::OperatorControl()
{
	vision->SendImage();
	Wait(0.005);
}

START_ROBOT_CLASS(VR);
