# TF6701 MQTT Sample – MQTTv5 Last Will and Testament

## Overview
This TwinCAT 3 sample demonstrates how to use the **Last Will and Testament (LWT)** feature of MQTTv5 with `FB_IotMqtt5Client`. A Last Will message is a special message that the broker will publish on the client's behalf if the client disconnects unexpectedly (e.g. due to a power failure or network interruption). This sample shows how to configure the Last Will topic, payload, QoS level, content type, and user properties.

## What this sample demonstrates
- Configuring a Last Will message with `FB_IotMqtt5Client.stWill` before connecting
- Setting the Last Will topic, payload, QoS level, content type, and user properties
- Cyclically publishing messages and subscribing to a topic (identical to the basic MQTTv5 sample)
- How the broker delivers the Last Will message when the client disconnects ungracefully

## Prerequisites
- TwinCAT 3 XAE engineering environment installed on Windows
- A TwinCAT 3 XAR runtime or compatible target system that can run the PLC project
- TF6701 TC3 IoT Communication (MQTT) license installed on your target system (version supporting MQTTv5)
- An MQTT broker that supports MQTTv5 (e.g. Mosquitto version 1.6 or newer)
- A second MQTT client (e.g. MQTT Explorer) subscribed to `MyLastWillTopic` to observe the Last Will message

## Getting Started
1. Start an MQTTv5-compatible broker (e.g. Mosquitto).
2. Open the solution file [IotMqttv5LastWillSample.sln](IotMqttv5LastWillSample.sln).
3. In `PrgMqttCom`, adjust `sHostName` and `nHostPort` if needed.
4. Build and activate the project on your target system.
5. Use a second MQTT client to subscribe to `MyLastWillTopic`.
6. While the PLC is running, simulate an unexpected disconnect (e.g. stop the TwinCAT runtime without a clean disconnect). The broker will publish the Last Will message to `MyLastWillTopic`.

## Last Will configuration
The Last Will is configured during the parameter setup phase (before `Execute()` is first called):

```iecst
fbMqttClient.stWill.sTopic         := 'MyLastWillTopic';
fbMqttClient.stWill.sContentType   := 'MyContentType';
fbMqttClient.stWill.eQoS           := TcIotMqttQoS.ExactlyOnceDelivery;
fbMqttClient.stWill.fbPayload.SetData(ADR(sLastWillMsg), SIZEOF(sLastWillMsg));
fbMqttClient.stWill.fbUserProperties.AddUserProperty('MyFirst', 'UserProperty');
```

The Last Will payload is set to the string `'I will be back!'`. The broker stores this message and delivers it to subscribers of `MyLastWillTopic` if and only if the client disconnects without sending a proper DISCONNECT packet.

## Notes & Troubleshooting
- The Last Will message is only delivered if the client disconnects **ungracefully**. A clean disconnect (setting `bConnect := FALSE`) will not trigger the Last Will.
- MQTTv5 adds the ability to attach a content type and user properties to the Last Will message, which was not possible in MQTTv3.
- Make sure the broker supports MQTTv5; Mosquitto version 1.6 or newer is required.

## Support
For questions about this sample, contact your local Beckhoff support team. Contact information is available on the official Beckhoff website at https://www.beckhoff.com/contact/.
