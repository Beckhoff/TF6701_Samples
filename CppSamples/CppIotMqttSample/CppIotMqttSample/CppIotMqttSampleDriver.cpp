///////////////////////////////////////////////////////////////////////////////
// CppIotMqttSampleDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "CppIotMqttSampleDriver.h"
#include "CppIotMqttSampleClassFactory.h"

DECLARE_GENERIC_DEVICE(CPPIOTMQTTSAMPLEDRV)

IOSTATUS CCppIotMqttSampleDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CCppIotMqttSampleClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CCppIotMqttSampleDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CCppIotMqttSampleDriver::CPPIOTMQTTSAMPLEDRV_GetVersion( )
{
	return( (CPPIOTMQTTSAMPLEDRV_Major << 8) | CPPIOTMQTTSAMPLEDRV_Minor );
}

