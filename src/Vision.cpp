#include "Vision.h"

Vision::Vision()
{
    // create an image
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	//the camera name (ex "cam0") can be found through the roborio web interface
	imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
	}
	imaqError = IMAQdxConfigureGrab(session);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
	}
}

Vision::~Vision() {}

void Vision::SendImage()
{
    // acquire images
	IMAQdxStartAcquisition(session);

    // grab an image, draw the circle, and provide it for the camera server which will
    // in turn send it to the dashboard.
		IMAQdxGrab(session, frame, true, NULL);
		if(imaqError != IMAQdxErrorSuccess)
		{
			DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
		}
		else
		{
			CameraServer::GetInstance()->SetImage(frame);
		}
    // stop image acquisition
	IMAQdxStopAcquisition(session);
}


