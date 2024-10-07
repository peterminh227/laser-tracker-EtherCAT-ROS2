// LaserTrackerUDP_senderCtrl.cpp : Implementation of CTcLaserTrackerUDP_senderCtrl
#include "TcPch.h"
#pragma hdrstop

#include "LaserTrackerUDP_senderW32.h"
#include "LaserTrackerUDP_senderCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CLaserTrackerUDP_senderCtrl

CLaserTrackerUDP_senderCtrl::CLaserTrackerUDP_senderCtrl() 
	: ITcOCFCtrlImpl<CLaserTrackerUDP_senderCtrl, CLaserTrackerUDP_senderClassFactory>() 
{
}

CLaserTrackerUDP_senderCtrl::~CLaserTrackerUDP_senderCtrl()
{
}

