# TF6701 MQTT Sample – Azure IoT Hub

## Overview
This TwinCAT 3 sample demonstrates how to connect a TwinCAT PLC to **Microsoft Azure IoT Hub** using MQTT over TLS. The sample supports three authentication options: SAS Token (compact form), SAS Token (split fields), and X.509 device certificate. After connecting, the PLC publishes telemetry messages to IoT Hub and subscribes to receive Cloud-to-Device (C2D) messages.

## What this sample demonstrates
- Connecting to Azure IoT Hub with `FB_IotMqttClient` over TLS on port 8883
- Three supported authentication methods: Device SAS Token, split SAS Token fields, and X.509 certificate
- Publishing device-to-cloud (D2C) telemetry messages every second
- Subscribing to the Cloud-to-Device (C2D) message topic
- Receiving C2D messages via the message queue function block `FB_IotMqttMessageQueue`

## Prerequisites
- TwinCAT 3 XAE engineering environment installed on Windows
- A TwinCAT 3 XAR runtime or compatible target system that can run the PLC project
- TF6701 TC3 IoT Communication (MQTT) license installed on your target system
- An active Azure subscription with an IoT Hub created
- A registered IoT device in the IoT Hub
- The appropriate Azure CA certificate (see Microsoft's documentation for the current root CA)

## Getting Started
1. In the Azure portal, create an IoT Hub and register a device. Note the device ID and obtain the connection string or certificate.
2. Download the Azure CA certificate (see [Microsoft documentation](https://learn.microsoft.com/en-us/azure/iot/iot-mqtt-connect-to-iot-hub)) and copy it to the TwinCAT target.
3. Open the solution file [IotMqttSampleAzureIotHub.sln](IotMqttSampleAzureIotHub.sln).
4. In `PrgMqttCom`, choose one of the three authentication options (see below) and fill in the required parameters. Replace `PlaceYourDeviceIdHere` in `sTopicPub` and `sTopicSub` with your actual device ID.
5. Build and activate the project on your target system.

## Authentication options

### Option 1: Device SAS Token (compact form)
Set `stTLS.sCA` to the path of the CA certificate and `stTLS.sAzureSas` to the full Device SAS Token connection string. This is the simplest approach and recommended for getting started.

### Option 2: X.509 certificate
Provide `stTLS.sCA`, `stTLS.sCert` (device certificate), and `stTLS.sKeyFile` (private key). Also set `sHostName`, `nHostPort`, `sClientId`, and `sUserName` as described in the code comments.

### Option 3: SAS Token (split fields)
Set `stTLS.sCA`, `sHostName`, `nHostPort`, `sClientId`, `sUserName`, and `sUserPassword` (the SAS token value) individually.

## Azure IoT Hub MQTT topics

| Direction | Topic pattern |
|---|---|
| Device-to-Cloud (D2C) | `devices/<deviceId>/messages/events/` |
| Cloud-to-Device (C2D) | `devices/<deviceId>/messages/devicebound/#` |

## Notes & Troubleshooting
- Microsoft has migrated Azure IoT Hub to new root certificate authorities. Make sure you are using the correct CA certificate for your IoT Hub instance. Refer to the links in the source code comments.
- SAS Tokens have an expiry time. If the connection is refused after some time, regenerate the SAS Token.
- For Azure IoT Hub Device Twin operations (GET, PATCH, direct methods), see the [TF6701_IotMqttSampleAzureIotHubDeviceTwin](../TF6701_IotMqttSampleAzureIotHubDeviceTwin/) sample.

## Support
For questions about this sample, contact your local Beckhoff support team. Contact information is available on the official Beckhoff website at https://www.beckhoff.com/contact/.
