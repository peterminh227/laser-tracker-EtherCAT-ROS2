///////////////////////////////////////////////////////////////////////////////
// LaserTrackerUDP_senderDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "LaserTrackerUDP_senderDriver.h"
#include "LaserTrackerUDP_senderClassFactory.h"

DECLARE_GENERIC_DEVICE(LASERTRACKERUDP_SENDERDRV)

IOSTATUS CLaserTrackerUDP_senderDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CLaserTrackerUDP_senderClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CLaserTrackerUDP_senderDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CLaserTrackerUDP_senderDriver::LASERTRACKERUDP_SENDERDRV_GetVersion( )
{
	return( (LASERTRACKERUDP_SENDERDRV_Major << 8) | LASERTRACKERUDP_SENDERDRV_Minor );
}

