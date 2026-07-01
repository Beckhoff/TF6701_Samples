# TF6701 MQTT Sample – Using Callback

## Overview
This TwinCAT 3 sample demonstrates how to receive MQTT messages using the **callback** approach. Instead of polling a message queue, a custom function block `FB_MyMqtt` extends `FB_IotMqttClient` and overrides the `OnMqttMessage` method, which is called automatically by the runtime whenever a message arrives on a subscribed topic.

## What this sample demonstrates
- Extending `FB_IotMqttClient` to implement a custom MQTT client function block
- Overriding the `OnMqttMessage` callback method to handle incoming messages
- Cyclically publishing string messages to a topic
- Subscribing to an MQTT topic
- Comparing the callback approach with the queue-based approach

## Prerequisites
- TwinCAT 3 XAE engineering environment installed on Windows
- A TwinCAT 3 XAR runtime or compatible target system that can run the PLC project
- TF6701 TC3 IoT Communication (MQTT) license installed on your target system
- A running MQTT message broker accessible from the target (e.g. Mosquitto on `localhost:1883`)

## Getting Started
1. Start your MQTT message broker (e.g. Mosquitto). Sample configuration files for Mosquitto can be found in the [Mosquitto](../Mosquitto/) folder.
2. Open the solution file [IotMqttSampleUsingCallback.sln](IotMqttSampleUsingCallback.sln).
3. In `PrgMqttCom`, adjust `sHostName` and `nHostPort` to match your broker address if needed.
4. Build and activate the project on your target system.
5. Log in to the PLC application. The client will connect to the broker, subscribe to `MyTopic`, and start publishing messages every second.

## How it works

### The custom function block FB_MyMqtt
`FB_MyMqtt` is declared with `EXTENDS FB_IotMqttClient` and must be compiled with the `{attribute 'c++_compatible'}` attribute. It overrides the `OnMqttMessage` method, which is automatically invoked by the TF6701 runtime each time a message is received on a subscribed topic.

Inside `OnMqttMessage`, the topic is copied to `sTopicRcv` and the payload is copied to `sPayloadRcv` using `STRNCPY` and `MEMCPY` respectively. This approach avoids the overhead of a message queue and provides a more event-driven programming model.

### Publishing messages
The program `PrgMqttCom` uses the `FB_MyMqtt` instance and publishes a string payload every second via `Publish()`.

### Comparing callback vs. queue approach
This sample uses the **callback** approach. An alternative approach using a **message queue** is shown in the [TF6701_IotMqttSampleUsingQueue](../TF6701_IotMqttSampleUsingQueue/) sample.

## Notes & Troubleshooting
- The `{attribute 'c++_compatible'}` and `{attribute 'pack_mode' := '4'}` attributes on `OnMqttMessage` are required. Do not remove them.
- The callback is executed in the context of the TF6701 communication task, not the PLC task. Make sure that shared variables are accessed safely.
- If `fbMqttClient.bError` is set, inspect `fbMqttClient.hrErrorCode` for a more detailed error description.
- For encrypted connections using TLS certificates, refer to the [TF6701_IotMqttSampleTls](../TF6701_IotMqttSampleTls/) sample.

## Support
For questions about this sample, contact your local Beckhoff support team. Contact information is available on the official Beckhoff website at https://www.beckhoff.com/contact/.
