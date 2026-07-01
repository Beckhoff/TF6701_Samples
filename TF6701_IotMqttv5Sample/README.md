# TF6701 MQTT Sample – MQTTv5

## Overview
This TwinCAT 3 sample demonstrates how to use the **MQTTv5** function blocks introduced in TF6701. It uses `FB_IotMqtt5Client` instead of the MQTTv3 `FB_IotMqttClient` to connect to an MQTTv5-capable message broker. The sample shows how to publish and subscribe to messages and how to access MQTTv5-specific features such as ConnAck properties and Disconnect Reason Strings.

## What this sample demonstrates
- Connecting to an MQTTv5 broker with `FB_IotMqtt5Client`
- Cyclically publishing a JSON payload every second
- Subscribing to a topic and receiving messages via the built-in message queue (`fbMqttClient.fbMessageQueue`)
- Accessing MQTTv5 **ConnAck properties** (e.g. checking if the broker supports retained messages)
- Accessing MQTTv5 **Disconnect Reason String** when the connection is lost
- Building a JSON payload using the helper function `F_CreateMessage`

## Prerequisites
- TwinCAT 3 XAE engineering environment installed on Windows
- A TwinCAT 3 XAR runtime or compatible target system that can run the PLC project
- TF6701 TC3 IoT Communication (MQTT) license installed on your target system (version supporting MQTTv5)
- An MQTT broker that supports MQTTv5 (e.g. Mosquitto version 1.6 or newer)

## Getting Started
1. Start an MQTTv5-compatible broker (e.g. Mosquitto). Sample configuration files are available in the [Mosquitto](../Mosquitto/) folder.
2. Open the solution file [IotMqttv5Sample.sln](IotMqttv5Sample.sln).
3. In `PrgMqttCom`, adjust `sHostName` and `nHostPort` if your broker is not running on `localhost:1883`.
4. Build and activate the project on your target system.
5. Log in to the PLC. The client will connect, subscribe to `MyTopic`, and publish a message every second.

## Differences from MQTTv3
`FB_IotMqtt5Client` provides the same core methods (`Execute`, `Publish`, `Subscribe`) as `FB_IotMqttClient` but adds MQTTv5-specific properties and features:

| Feature | Description |
|---|---|
| `fbConnAckProps` | ConnAck properties sent by the broker after a successful connect |
| `fbDisconnectProps` | Disconnect properties including a human-readable Reason String |
| Built-in message queue | `fbMqttClient.fbMessageQueue` — no need to assign an external queue instance |
| Publish/Subscribe properties | Extended `pProps` parameter for passing MQTTv5 properties |

## Notes & Troubleshooting
- Make sure your broker is configured for MQTTv5. Mosquitto requires version 1.6 or newer and does not need any special configuration for MQTTv5 by default.
- The `pProps` parameter in `Publish()` and `Subscribe()` can be set to `NULL` if no additional properties are needed.
- For MQTTv5 User Properties, see the [TF6701_IotMqttv5UserPropsSample](../TF6701_IotMqttv5UserPropsSample/) sample.
- For MQTTv5 Last Will and Testament, see the [TF6701_IotMqttv5LastWillSample](../TF6701_IotMqttv5LastWillSample/) sample.
- For the MQTTv5 Request/Response pattern, see the [TF6701_IotMqttv5ReqResSample](../TF6701_IotMqttv5ReqResSample/) sample.

## Support
For questions about this sample, contact your local Beckhoff support team. Contact information is available on the official Beckhoff website at https://www.beckhoff.com/contact/.
