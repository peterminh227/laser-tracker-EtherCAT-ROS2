///////////////////////////////////////////////////////////////////////////////
// LaserTrackerUDP_senderDriver.h

#ifndef __LASERTRACKERUDP_SENDERDRIVER_H__
#define __LASERTRACKERUDP_SENDERDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define LASERTRACKERUDP_SENDERDRV_NAME        "LASERTRACKERUDP_SENDER"
#define LASERTRACKERUDP_SENDERDRV_Major       1
#define LASERTRACKERUDP_SENDERDRV_Minor       0

#define DEVICE_CLASS CLaserTrackerUDP_senderDriver

#include "ObjDriver.h"

class CLaserTrackerUDP_senderDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl LASERTRACKERUDP_SENDERDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(LASERTRACKERUDP_SENDERDRV)
	VxD_Service( LASERTRACKERUDP_SENDERDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __LASERTRACKERUDP_SENDERDRIVER_H__