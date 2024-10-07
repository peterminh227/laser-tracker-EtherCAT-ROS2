///////////////////////////////////////////////////////////////////////////////
// LaserTrackerUDP_senderCtrl.h

#ifndef __LASERTRACKERUDP_SENDERCTRL_H__
#define __LASERTRACKERUDP_SENDERCTRL_H__

#include <atlbase.h>
#include <atlcom.h>


#include "resource.h"       // main symbols
#include "LaserTrackerUDP_senderW32.h"
#include "TcBase.h"
#include "LaserTrackerUDP_senderClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CLaserTrackerUDP_senderCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CLaserTrackerUDP_senderCtrl, &CLSID_LaserTrackerUDP_senderCtrl>
	, public ILaserTrackerUDP_senderCtrl
	, public ITcOCFCtrlImpl<CLaserTrackerUDP_senderCtrl, CLaserTrackerUDP_senderClassFactory>
{
public:
	CLaserTrackerUDP_senderCtrl();
	virtual ~CLaserTrackerUDP_senderCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_LASERTRACKERUDP_SENDERCTRL)
DECLARE_NOT_AGGREGATABLE(CLaserTrackerUDP_senderCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CLaserTrackerUDP_senderCtrl)
	COM_INTERFACE_ENTRY(ILaserTrackerUDP_senderCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __LASERTRACKERUDP_SENDERCTRL_H__
