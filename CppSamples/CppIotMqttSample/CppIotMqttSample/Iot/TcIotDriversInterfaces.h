///////////////////////////////////////////////////////////////////////////////
// TcIotDriversInterfaces.h

#pragma once

#include "TcInterfaces.h"
#include "TcIoInterfaces.h"
#include "TcIotDriversServices.h"

enum TcIotMqttQos : unsigned char
{
	AtMostOnceDelivery = 0,
	AtLeastOnceDelivery = 1,
	ExactlyOnceDelivery = 2
};

#define	MQTT_TCP_PORT				1883
#define	MQTTS_TCP_PORT				8883

struct	__declspec(novtable)	ITcIotMqttOwner : public ITcUnknown
{
	virtual	HRESULT TCOMAPI	OnMqttMessage(PCCH topic, PVOID payload, ULONG length, TcIotMqttQos qos=AtMostOnceDelivery, bool bRepeated=false)=0;
};
_TCOM_SMARTPTR_TYPEDEF(ITcIotMqttOwner, IID_ITcIotMqttOwner);

struct	__declspec(novtable)	ITcIotMqttClient : public ITcUnknown
{
	virtual	HRESULT TCOMAPI	MqttExecute(ITcIotMqttOwner* ipOwn, bool connectReq, ETcIotMqttClientState* pState=NULL)=0;	// returns S_OK or S_FALSE if not connected
	virtual	HRESULT TCOMAPI	MqttPublish(PCCH topic, PVOID payload, UINT length, TcIotMqttQos qos=AtMostOnceDelivery, bool retain=false, bool queue=false)=0;
	virtual	HRESULT TCOMAPI	MqttSubscribe(PCCH topic, TcIotMqttQos qos=AtMostOnceDelivery)=0;
	virtual	HRESULT TCOMAPI	MqttUnsubscribe(PCCH topic)=0;
	virtual	HRESULT TCOMAPI	MqttSetParameter(PCCH host, PCCH client=NULL, PCCH topicPrefix=NULL, USHORT port=MQTT_TCP_PORT, USHORT keepAlive=60)=0;
	virtual	HRESULT TCOMAPI	MqttSetUserPwd(PCCH user, PCCH pwd=NULL)=0;
	virtual	HRESULT TCOMAPI	MqttSetWill(PCCH topic, PVOID payload, UINT length, TcIotMqttQos qos=AtMostOnceDelivery, bool retain=false)=0;
};
_TCOM_SMARTPTR_TYPEDEF(ITcIotMqttClient, IID_ITcIotMqttClient);

struct	__declspec(novtable)	ITcIotMqttClientTls : public ITcUnknown
{
	virtual	HRESULT TCOMAPI	MqttSetTlsCa(PCCH ca)=0;																							// file, PEM encoded string
	virtual	HRESULT TCOMAPI	MqttSetTlsCaPath(PCCH caPath)=0;																								
	virtual	HRESULT TCOMAPI	MqttSetTlsCaDer(PBYTE ca, ULONG calen)=0;																		// DER encoded data
	virtual	HRESULT TCOMAPI	MqttSetTlsCert(PCCH cert, PCCH key, PCCH keyPwd=NULL)=0;													// file, PEM encoded string
	virtual	HRESULT TCOMAPI	MqttSetTlsCertDer(PBYTE cert, ULONG certlen, PBYTE key, ULONG keylen, PCCH keyPwd=NULL)=0;	// DER encoded data
	virtual	HRESULT TCOMAPI	MqttSetTlsCrl(PCCH crl)=0;																							// file, PEM encoded string
	virtual	HRESULT TCOMAPI	MqttSetTlsCrlDer(PBYTE crl, ULONG crllen)=0;																	// DER encoded data
	virtual	HRESULT TCOMAPI	MqttSetTlsPsk(PCCH identity, PBYTE key, ULONG keylen)=0;	
	virtual	HRESULT TCOMAPI	MqttSetTlsPskPwd(PCCH identity, PCCH pwd, bool identityCaseSensitive=false)=0;					// key = SHA256(toupper(identity)+pwd)
	virtual	HRESULT TCOMAPI	MqttSetTlsParameter(PCCH version, PCCH ciphers=NULL, bool insecure=false)=0;	
	virtual	HRESULT TCOMAPI	MqttAzureSAS(PCCH azureSAS, bool insecure=false)=0;
};
_TCOM_SMARTPTR_TYPEDEF(ITcIotMqttClientTls, IID_ITcIotMqttClientTls);