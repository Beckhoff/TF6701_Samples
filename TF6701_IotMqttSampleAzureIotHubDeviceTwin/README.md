# TF6701 MQTT Sample – Azure IoT Hub Device Twin

## Overview
This TwinCAT 3 sample demonstrates how to work with the **Azure IoT Hub Device Twin** feature using MQTT. Device Twins are JSON documents stored in IoT Hub that hold device metadata, configuration (desired properties), and reported state (reported properties). The sample shows how to retrieve the Device Twin document, update reported properties, receive desired property change notifications, and handle direct method calls — all over MQTT.

## What this sample demonstrates
- Connecting to Azure IoT Hub with `FB_IotMqttClient` using a Device SAS Token
- Retrieving the Device Twin document (GET operation)
- Updating Device Twin reported properties (PATCH operation)
- Receiving desired property change notifications
- Receiving and responding to direct method calls
- Parsing Azure IoT Hub system topic structures with `FB_TopicInfos` and `F_GetTopicInfos`
- Publishing telemetry messages (D2C) and receiving Cloud-to-Device (C2D) messages

## Prerequisites
- TwinCAT 3 XAE engineering environment installed on Windows
- A TwinCAT 3 XAR runtime or compatible target system that can run the PLC project
- TF6701 TC3 IoT Communication (MQTT) license installed on your target system
- Tc3_JsonXml library installed on your target system
- An active Azure subscription with an IoT Hub and a registered device
- The appropriate Azure CA certificate on the TwinCAT target

## Getting Started
1. In the Azure portal, create an IoT Hub and register a device. Generate a SAS Token for the device.
2. Download the Azure CA certificate and copy it to the TwinCAT target.
3. Open the solution file [IotMqttSampleAzureIotHub.sln](IotMqttSampleAzureIotHub.sln).
4. In `PrgMqttCom`, set `stTLS.sCA` to the CA certificate path and `stTLS.sAzureSas` to the full Device SAS Token connection string.
5. Replace `CX-12345` in the topic strings with your actual device ID.
6. Build and activate the project on your target system.

## Device Twin operations

The Device Twin uses a set of reserved MQTT topics under the `$iothub/twin/` prefix. The sample subscribes to all required topics at startup.

| Operation | Topic |
|---|---|
| Subscribe to all Twin responses | `$iothub/twin/res/#` |
| GET Device Twin | `$iothub/twin/GET/?$rid=<requestId>` |
| PATCH reported properties | `$iothub/twin/PATCH/properties/reported/?$rid=<requestId>` |
| Desired property changes | `$iothub/twin/PATCH/properties/desired/#` |
| Direct method calls | `$iothub/methods/POST/#` |
| Direct method response | `$iothub/methods/res/<statusCode>/?$rid=<requestId>` |

### Triggering operations from the PLC
To trigger Device Twin operations while the PLC is logged in, set the following variables to `TRUE`:

| Variable | Action |
|---|---|
| `bTwinGet` | Retrieves the current Device Twin document (result stored in `sTwinResponse`) |
| `bTwinUpdate` | Publishes a PATCH update with new reported properties |

Direct method calls are received automatically and indicated via `bTwinMethodCallReceived`.

## Notes & Troubleshooting
- Each GET or PATCH request includes an incrementing `$rid` (Request ID). Responses from IoT Hub include the same `$rid` so they can be correlated. The helper function `FB_TopicInfos` assists with parsing the status code and request ID from the response topic.
- SAS Tokens have an expiry time. Renew the token before it expires to avoid connection drops.
- For basic IoT Hub telemetry and C2D messaging without Device Twin, see the [TF6701_IotMqttSampleAzureIotHub](../TF6701_IotMqttSampleAzureIotHub/) sample.

## Support
For questions about this sample, contact your local Beckhoff support team. Contact information is available on the official Beckhoff website at https://www.beckhoff.com/contact/.
