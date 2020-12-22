///////////////////////////////////////////////////////////////////////////////
// CppIotMqttSampleCtrl.h

#ifndef __CPPIOTMQTTSAMPLECTRL_H__
#define __CPPIOTMQTTSAMPLECTRL_H__

#include <atlbase.h>
#include <atlcom.h>


#include "resource.h"       // main symbols
#include "CppIotMqttSampleW32.h"
#include "TcBase.h"
#include "CppIotMqttSampleClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CCppIotMqttSampleCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CCppIotMqttSampleCtrl, &CLSID_CppIotMqttSampleCtrl>
	, public ICppIotMqttSampleCtrl
	, public ITcOCFCtrlImpl<CCppIotMqttSampleCtrl, CCppIotMqttSampleClassFactory>
{
public:
	CCppIotMqttSampleCtrl();
	virtual ~CCppIotMqttSampleCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_CPPIOTMQTTSAMPLECTRL)
DECLARE_NOT_AGGREGATABLE(CCppIotMqttSampleCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCppIotMqttSampleCtrl)
	COM_INTERFACE_ENTRY(ICppIotMqttSampleCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __CPPIOTMQTTSAMPLECTRL_H__
