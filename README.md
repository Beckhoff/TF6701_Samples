# About this repository
This repository contains official sample code for the product TF6701|TC3 IoT Communication (MQTT) offered by [Beckhoff Automation](https://www.beckhoff.com). The sample code is provided as-is under the Zero-Clause BSD license.

# Samples overview

## General MQTT samples

| Folder | Description |
|---|---|
| [TF6701_IotMqttSampleUsingQueue](TF6701_IotMqttSampleUsingQueue/) | Basic MQTT publish/subscribe sample using `FB_IotMqttClient` and a message queue (`FB_IotMqttMessageQueue`) for receiving messages. |
| [TF6701_IotMqttSampleUsingCallback](TF6701_IotMqttSampleUsingCallback/) | Basic MQTT publish/subscribe sample using the callback approach: a custom function block extends `FB_IotMqttClient` and overrides the `OnMqttMessage` method. |
| [TF6701_IotMqttSampleTls](TF6701_IotMqttSampleTls/) | MQTT connection secured with TLS using X.509 certificates (CA cert, client cert, and private key). |
| [TF6701_IotMqttSampleTlsPsk](TF6701_IotMqttSampleTlsPsk/) | MQTT connection secured with TLS using a Pre-Shared Key (PSK) instead of X.509 certificates. |

## MQTTv5 samples

| Folder | Description |
|---|---|
| [TF6701_IotMqttv5Sample](TF6701_IotMqttv5Sample/) | Basic MQTTv5 sample using `FB_IotMqtt5Client`. Shows connect, publish, subscribe, and access to MQTTv5 ConnAck properties and Disconnect Reason Strings. |
| [TF6701_IotMqttv5LastWillSample](TF6701_IotMqttv5LastWillSample/) | Demonstrates the MQTTv5 **Last Will and Testament** feature: configures a last will topic, payload, QoS level, content type, and user properties. |
| [TF6701_IotMqttv5ReqResSample](TF6701_IotMqttv5ReqResSample/) | Demonstrates the MQTTv5 **Request/Response** pattern. Two PLC projects — a requester and a responder — exchange messages using Response Topic and Correlation Data properties. |
| [TF6701_IotMqttv5UserPropsSample](TF6701_IotMqttv5UserPropsSample/) | Demonstrates MQTTv5 **User Properties**: attaches custom key/value pairs to publish messages and reads them from received messages by index or by name. |

## Cloud service samples

| Folder | Description |
|---|---|
| [TF6701_IotMqttSampleAwsIoT](TF6701_IotMqttSampleAwsIoT/) | Connects to **AWS IoT Core** using MQTT over TLS with X.509 device certificates. Publishes telemetry and subscribes to a topic. |
| [TF6701_IotMqttSampleAwsIotShadow](TF6701_IotMqttSampleAwsIotShadow/) | Demonstrates the **AWS IoT Device Shadow** service: publishes shadow updates and receives shadow document change notifications. |
| [TF6701_IotMqttSampleAzureIotHub](TF6701_IotMqttSampleAzureIotHub/) | Connects to **Microsoft Azure IoT Hub** using MQTT over TLS. Supports SAS Token and X.509 authentication. Publishes telemetry (D2C) and receives Cloud-to-Device (C2D) messages. |
| [TF6701_IotMqttSampleAzureIotHubDeviceTwin](TF6701_IotMqttSampleAzureIotHubDeviceTwin/) | Extends the Azure IoT Hub sample with full **Device Twin** support: GET, PATCH reported properties, desired property change notifications, and direct method calls. |

## Mosquitto configuration files

| Folder | Description |
|---|---|
| [Mosquitto](Mosquitto/) | Sample configuration files for the Eclipse Mosquitto message broker covering insecure, username/password, ACL, TLS certificate, and TLS PSK setups. |

# How to get support
Should you have any questions regarding the provided sample code, please contact your local Beckhoff support team. Contact information can be found on the official Beckhoff website at https://www.beckhoff.com/contact/.

# Further information
Further information about this sample code can be found on the [Beckhoff Information System](https://infosys.beckhoff.com) in the [TF6701 documentation](https://infosys.beckhoff.com/content/1033/tf6701_tc3_iot_communication_mqtt/index.html).

