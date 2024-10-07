///////////////////////////////////////////////////////////////////////////////
// UDP_sender.h
#pragma once

#include "LaserTrackerUDP_senderInterfaces.h"

class LaserTrackerMeasurement {

public:
	double angle_hz, angle_vt, distance;
	double quaternion[4];
	LaserTrackerMeasurement() {
		angle_hz = 0.;
		angle_vt = 0.;
		distance = 0.;
		for (int i = 0; i < 4; i++) {
			quaternion[i] = 0.;
		}
		quaternion[0] = 1.;
	}


	void set_position(double dist, double hz, double vt) {
		distance = dist;
		angle_hz = hz;
		angle_vt = vt;
	}
	void set_orientation(double q0, double q1, double q2, double q3) {
		quaternion[0] = q0;
		quaternion[1] = q1;
		quaternion[2] = q2;
		quaternion[3] = q3;
	}
};
class CUDP_sender 
	: public ITComObject
	, public ITcADI
	, public ITcWatchSource
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
	, public ITcIoUdpProtocolRecv
///</AutoGeneratedContent>
{
public:
	DECLARE_IUNKNOWN()
	DECLARE_IPERSIST_LIB()
	DECLARE_ITCOMOBJECT_LOCKOP()
	DECLARE_ITCADI()
	DECLARE_ITCWATCHSOURCE()
	DECLARE_OBJPARAWATCH_MAP()
	DECLARE_OBJDATAAREA_MAP()

	CUDP_sender();
	virtual	~CUDP_sender();


///<AutoGeneratedContent id="InterfaceMembers">
	// ITcCyclic
	virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

	// ITcIoUdpProtocolRecv
	virtual HRESULT TCOMAPI ReceiveData(ULONG ipAddr, USHORT udpDestPort, USHORT udpSrcPort, ULONG nData, PVOID pData, ETYPE_VLAN_HEADER* pVlan=0);

///</AutoGeneratedContent>

protected:
	DECLARE_ITCOMOBJECT_SETSTATE();

	HRESULT AddModuleToCaller();
	VOID RemoveModuleFromCaller();

	// Tracing
	CTcTrace m_Trace;

///<AutoGeneratedContent id="Members">
	TcTraceLevel m_TraceLevelMax;
	UDP_senderParameter m_Parameter;
	UDP_senderInputs m_Inputs;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
	ITcIoUdpProtocolPtr m_spUdpProt;
///</AutoGeneratedContent>

	// TODO: Custom variable
	UINT m_counter;
	ULONG client_ipaddr;
	USHORT m_udpPort;
	LaserTrackerMeasurement meas_data;
};