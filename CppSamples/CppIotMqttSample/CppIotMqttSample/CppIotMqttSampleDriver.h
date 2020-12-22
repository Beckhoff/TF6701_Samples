///////////////////////////////////////////////////////////////////////////////
// CppIotMqttSampleDriver.h

#ifndef __CPPIOTMQTTSAMPLEDRIVER_H__
#define __CPPIOTMQTTSAMPLEDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define CPPIOTMQTTSAMPLEDRV_NAME        "CPPIOTMQTTSAMPLE"
#define CPPIOTMQTTSAMPLEDRV_Major       1
#define CPPIOTMQTTSAMPLEDRV_Minor       0

#define DEVICE_CLASS CCppIotMqttSampleDriver

#include "ObjDriver.h"

class CCppIotMqttSampleDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl CPPIOTMQTTSAMPLEDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(CPPIOTMQTTSAMPLEDRV)
	VxD_Service( CPPIOTMQTTSAMPLEDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __CPPIOTMQTTSAMPLEDRIVER_H__