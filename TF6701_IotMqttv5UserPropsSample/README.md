# TF6701 MQTT Sample – MQTTv5 User Properties

## Overview
This TwinCAT 3 sample demonstrates how to use **MQTTv5 User Properties** with `FB_IotMqtt5Client`. User Properties are key/value pairs that can be attached to any MQTT publish or subscribe message, allowing applications to carry custom metadata alongside the message payload. The sample publishes messages with a set of user properties and reads them back from the received message.

## What this sample demonstrates
- Attaching **User Properties** to a publish message using `FB_IotMqtt5PublishProperties`
- Setting the **Content Type** property on a publish message
- Reading all User Properties from a received message by index using `GetUserPropertyByIdx()`
- Looking up a specific User Property by name using `GetUserPropertyValueByName()`
- Accessing MQTTv5 ConnAck properties and Disconnect Reason Strings

## Prerequisites
- TwinCAT 3 XAE engineering environment installed on Windows
- A TwinCAT 3 XAR runtime or compatible target system that can run the PLC project
- TF6701 TC3 IoT Communication (MQTT) license installed on your target system (version supporting MQTTv5)
- An MQTT broker that supports MQTTv5 (e.g. Mosquitto version 1.6 or newer)

## Getting Started
1. Start an MQTTv5-compatible broker (e.g. Mosquitto).
2. Open the solution file [IotMqttv5UserPropsSample.sln](IotMqttv5UserPropsSample.sln).
3. In `PrgMqttCom`, adjust `sHostName` and `nHostPort` if needed.
4. Build and activate the project on your target system.
5. Log in to the PLC. The client will connect, subscribe to `MyTopic`, and publish messages with user properties every second. The received user properties are stored in `aName_UserRcv` and `aValue_UserRcv`.

## How User Properties work

### Sending User Properties
Before calling `Publish()`, user properties are added to an `FB_IotMqtt5PublishProperties` instance:

```iecst
fbPubProps.AddUserProperty(aUserName[i], aUserValue[i]); // called in a loop for each property
```

The `pProps` parameter of `Publish()` is set to `ADR(fbPubProps)` to attach the properties to the outgoing message.

### Receiving User Properties
When a message is received, the number of user properties is available via `fbMessage.nUserPropertyCnt`. Properties can be read in two ways:

- **By index**: `fbMessage.GetUserPropertyByIdx(nIdx, ...)` — retrieves all properties in sequence
- **By name**: `fbMessage.GetUserPropertyValueByName(sName, ...)` — retrieves the value of a specific named property

### Example user properties in this sample
The sample sends 10 user properties with names `Fritz`, `Uwe`, and `Sven` and corresponding weight values. It demonstrates that multiple properties with the same name are allowed in MQTTv5.

## Notes & Troubleshooting
- The maximum number of receivable user properties is controlled by the constant `cMaxUserPropsToReceive` (set to 20 in this sample). This is also bounded by the `Tc3_IotBase.ParameterList.cMaxMqtt5UserProps` parameter.
- User properties are only available in MQTTv5. They are not supported by MQTTv3 brokers or clients.
- For the MQTTv5 Request/Response pattern (which also uses user properties), see the [TF6701_IotMqttv5ReqResSample](../TF6701_IotMqttv5ReqResSample/) sample.

## Support
For questions about this sample, contact your local Beckhoff support team. Contact information is available on the official Beckhoff website at https://www.beckhoff.com/contact/.
