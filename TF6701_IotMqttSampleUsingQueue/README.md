# TF6701 MQTT Sample – Using Queue

## Overview
This TwinCAT 3 sample demonstrates how to use the `FB_IotMqttClient` function block to connect to an MQTT message broker, publish messages cyclically, subscribe to a topic, and receive incoming messages using the message queue function block `FB_IotMqttMessageQueue`.

## What this sample demonstrates
- Establishing an MQTT connection with `FB_IotMqttClient`
- Cyclically publishing string messages to a topic every second
- Subscribing to an MQTT topic
- Receiving incoming messages by polling an `FB_IotMqttMessageQueue` instance
- Basic error handling via `bError` and `hrErrorCode`

## Prerequisites
- TwinCAT 3 XAE engineering environment installed on Windows
- A TwinCAT 3 XAR runtime or compatible target system that can run the PLC project
- TF6701 TC3 IoT Communication (MQTT) license installed on your target system
- A running MQTT message broker accessible from the target (e.g. Mosquitto on `localhost:1883`)

## Getting Started
1. Start your MQTT message broker (e.g. Mosquitto). Sample configuration files for Mosquitto can be found in the [Mosquitto](../Mosquitto/) folder.
2. Open the solution file [IotMqttSampleUsingQueue.sln](IotMqttSample01/IotMqttSampleUsingQueue.tsproj).
3. In `PrgMqttCom`, adjust `sHostName` and `nHostPort` to match your broker address if needed.
4. Build and activate the project on your target system.
5. Log in to the PLC application. The client will connect to the broker, subscribe to `MyTopic`, and start publishing a message every second.

## How it works

### Publishing messages
The program `PrgMqttCom` uses a 1-second `TON` timer. On each timer tick, the string payload `MyMessage<n>` is published to the topic `MyTopic` using `FB_IotMqttClient.Publish()`.

### Receiving messages
An `FB_IotMqttMessageQueue` instance is assigned to `fbMqttClient.ipMessageQueue`. Incoming messages are queued automatically. In each PLC cycle the program checks `fbMessageQueue.nQueuedMessages`. If messages are available, the first message is dequeued using `fbMessageQueue.Dequeue()` and the topic and payload are read using `fbMessage.GetTopic()` and `fbMessage.GetPayload()`.

### Comparing queue vs. callback approach
This sample uses the **queue** approach for receiving messages. An alternative approach using a **callback** method is shown in the [TF6701_IotMqttSampleUsingCallback](../TF6701_IotMqttSampleUsingCallback/) sample.

## Notes & Troubleshooting
- Make sure that the MQTT broker is reachable from the TwinCAT runtime. Check firewall rules and network configuration.
- If `fbMqttClient.bError` is set, inspect `fbMqttClient.hrErrorCode` for a more detailed error description.
- The default broker address is `localhost` on port `1883` (unencrypted). Adjust the connection parameters as needed for your environment.
- For encrypted connections using TLS certificates, refer to the [TF6701_IotMqttSampleTls](../TF6701_IotMqttSampleTls/) sample.

## Support
For questions about this sample, contact your local Beckhoff support team. Contact information is available on the official Beckhoff website at https://www.beckhoff.com/contact/.
