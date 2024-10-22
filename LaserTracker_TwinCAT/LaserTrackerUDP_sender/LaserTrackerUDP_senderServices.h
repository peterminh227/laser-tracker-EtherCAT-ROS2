///////////////////////////////////////////////////////////////////////////////
// LaserTrackerUDP_senderServices.h

#pragma once

#include "TcServices.h"

const ULONG DrvID_LaserTrackerUDP_sender = 0x3F000000;
#define SRVNAME_LASERTRACKERUDP_SENDER "LaserTrackerUDP_sender"

///<AutoGeneratedContent id="ClassIDs">
const CTCID CID_LaserTrackerUDP_senderCUDP_sender = {0xfa43dd6e,0xa443,0x49f8,{0x82,0x46,0x69,0xf0,0x7e,0xd5,0x03,0x92}};
///</AutoGeneratedContent>

///<AutoGeneratedContent id="ParameterIDs">
const PTCID PID_UDP_senderParameter = 0x00000001;
const PTCID PID_UDP_senderUdpProt = 0x00000002;
///</AutoGeneratedContent>

///<AutoGeneratedContent id="DataTypes">
#if !defined(_TC_TYPE_478C4436_6F33_4F6F_B4A8_88074B54DCD4_INCLUDED_)
#define _TC_TYPE_478C4436_6F33_4F6F_B4A8_88074B54DCD4_INCLUDED_
typedef ULONG ETYPE_VLAN_HEADER;
#endif // !defined(_TC_TYPE_478C4436_6F33_4F6F_B4A8_88074B54DCD4_INCLUDED_)

typedef struct _UDP_senderParameter
{
	ULONG data1;
	ULONG data2;
	double data3;
} UDP_senderParameter, *PUDP_senderParameter;

#pragma pack(push,1)
typedef struct _UDP_senderInputs
{
	double AngleHz;
	double AngleVt;
	double Distance;
	double Quaternion0;
	double Quaternion1;
	double Quaternion2;
	double Quaternion3;
	ULONGLONG TimeStamp;
	ULONG Status;
} UDP_senderInputs, *PUDP_senderInputs;
#pragma pack(pop)

///</AutoGeneratedContent>



///<AutoGeneratedContent id="DataAreaIDs">
#define ADI_UDP_senderInputs 0
///</AutoGeneratedContent>

///<AutoGeneratedContent id="InterfaceIDs">
#if !defined(_TC_IID_03010095_0000_0000_E000_000000000064_INCLUDED_)
#define _TC_IID_03010095_0000_0000_E000_000000000064_INCLUDED_
TCOM_DECL_INTERFACE("03010095-0000-0000-e000-000000000064", ITcIoUdpProtocolRecv)
#endif // !defined(_TC_IID_03010095_0000_0000_E000_000000000064_INCLUDED_)

#if !defined(_TC_IID_03010097_0000_0000_E000_000000000064_INCLUDED_)
#define _TC_IID_03010097_0000_0000_E000_000000000064_INCLUDED_
TCOM_DECL_INTERFACE("03010097-0000-0000-e000-000000000064", ITcIoUdpProtocol)
#endif // !defined(_TC_IID_03010097_0000_0000_E000_000000000064_INCLUDED_)

///</AutoGeneratedContent>

///<AutoGeneratedContent id="EventClasses">
///</AutoGeneratedContent>
