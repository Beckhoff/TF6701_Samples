# TF6701 MQTT Sample – MQTTv5 Request/Response

## Overview
This TwinCAT 3 sample demonstrates the **Request/Response** pattern introduced in MQTTv5. Two separate PLC applications are included in the solution: a **requester** (`PlcIotMqttv5ReqSample`) that sends requests, and a **responder** (`PlcIotMqttv5ResSample`) that receives requests and sends back responses. The sample also demonstrates how to use MQTTv5 **User Properties** and **Correlation Data** to match responses with their corresponding requests.

## What this sample demonstrates
- Implementing the MQTTv5 Request/Response pattern using `FB_IotMqtt5Client`
- Setting the **Response Topic** and **Correlation Data** properties on a publish message
- Reading the **Response Topic** and **Correlation Data** from a received request message
- Sending a response to the dynamically provided response topic
- Exchanging **User Properties** and **Content Type** alongside message payloads
- Accessing **ConnAck properties** (e.g. Retain availability) and **Disconnect Reason Strings**

## Prerequisites
- TwinCAT 3 XAE engineering environment installed on Windows
- Two TwinCAT 3 XAR runtimes or target systems (or the same target running both PLC instances)
- TF6701 TC3 IoT Communication (MQTT) license installed on both targets
- An MQTT broker that supports MQTTv5 (e.g. Mosquitto version 1.6 or newer)

## Getting Started
1. Start an MQTTv5-compatible broker.
2. Open the solution file [IotMqttv5ReqResSample.sln](IotMqttv5ReqResSample.sln). The solution contains two PLC projects: `PlcIotMqttv5ReqSample` and `PlcIotMqttv5ResSample`.
3. Deploy `PlcIotMqttv5ResSample` (the responder) to one TwinCAT runtime.
4. Deploy `PlcIotMqttv5ReqSample` (the requester) to the same or another TwinCAT runtime.
5. Log in to both PLC applications.
6. In the requester PLC, set `bSendRequest := TRUE` to trigger a request. The request is published to `MyRequest` with `MyResponse` as the response topic and a correlation data value.

## How the Request/Response pattern works

### Requester (PlcIotMqttv5ReqSample)
1. Subscribes to the response topic (`MyResponse`).
2. When `bSendRequest` is set to `TRUE`, publishes a message to `MyRequest` with:
   - **Response Topic**: `MyResponse` — tells the responder where to send the reply
   - **Correlation Data**: a `UDINT` value (`nCorrDataSent`) — used to match the response to the request
   - **User Properties**: key/value pairs attached to the publish properties
3. When a message is received on `MyResponse`, reads the Correlation Data and verifies it matches `nCorrDataSent`. Sets `bResponseReceived := TRUE` on success.

### Responder (PlcIotMqttv5ResSample)
1. Subscribes to the request topic (`MyRequest`).
2. When a request arrives:
   - Reads the **Response Topic** from the message properties using `fbMessage.GetResponseTopic()`
   - Reads the **Correlation Data** using `fbMessage.GetCorrelationData()`
   - Publishes a response to the received response topic, echoing the Correlation Data

## Notes & Troubleshooting
- Both PLC projects must connect to the same MQTT broker. Adjust `sHostName` and `nHostPort` in both `PrgMqttCom` programs accordingly.
- If no response is received, check that the responder is subscribed and running before the requester sends the request.
- The `cMaxUserPropsToReceive` constant (default: 20) limits how many user properties can be read from a single incoming message. This limit is also bounded by the `Tc3_IotBase.ParameterList.cMaxMqtt5UserProps` parameter.

## Support
For questions about this sample, contact your local Beckhoff support team. Contact information is available on the official Beckhoff website at https://www.beckhoff.com/contact/.
