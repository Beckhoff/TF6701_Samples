# TF6701 MQTT Sample – AWS IoT Core

## Overview
This TwinCAT 3 sample demonstrates how to connect a TwinCAT PLC to **AWS IoT Core** using MQTT over TLS. Authentication is performed using X.509 certificates (either self-signed certificates created on the AWS IoT Core management console, or certificates signed by a custom Certificate Authority registered with AWS).

## What this sample demonstrates
- Connecting to AWS IoT Core with `FB_IotMqttClient` over TLS on port 8883
- Configuring the Amazon Root CA certificate and device certificate/key
- Publishing telemetry messages to an AWS IoT Core topic
- Subscribing to a topic and receiving messages via the message queue function block `FB_IotMqttMessageQueue`

## Prerequisites
- TwinCAT 3 XAE engineering environment installed on Windows
- A TwinCAT 3 XAR runtime or compatible target system that can run the PLC project
- TF6701 TC3 IoT Communication (MQTT) license installed on your target system
- An active AWS account with access to the AWS IoT Core service
- A registered IoT Thing in AWS IoT Core with an attached policy that allows publish and subscribe
- The following certificate files downloaded from AWS IoT Core and placed on the target:
  - Amazon Root CA certificate (e.g. `AmazonRootCA1.pem`)
  - Device certificate (`.pem.crt`)
  - Device private key (`.pem.key`)

## Getting Started
1. In the AWS IoT Core management console, create a Thing, generate or upload a certificate, attach a policy, and download the certificate files.
2. Copy the certificate files to the TwinCAT target (e.g. `C:\TwinCAT\3.1\Config\Certificates\`).
3. Open the solution file [IotMqttSampleAwsIoT.sln](IotMqttSampleAwsIoT.sln).
4. In `PrgMqttCom`, update the following parameters:
   - `stTLS.sCA`: path to the Amazon Root CA certificate
   - `stTLS.sCert`: path to the device certificate
   - `stTLS.sKeyFile`: path to the device private key
   - `sHostName`: your AWS IoT Core endpoint (found in the AWS console under Settings)
   - `sClientId`: your Thing name (must match the certificate policy)
   - `sTopicPub` / `sTopicSub`: the topics to publish to and subscribe from
5. Build and activate the project on your target system.

## Connecting to AWS IoT Core
AWS IoT Core uses mutual TLS authentication. The broker endpoint has the format:

```
<account-prefix>.iot.<region>.amazonaws.com
```

The port is `8883`. The `sClientId` must match the Thing name or comply with the attached IoT policy.

Please consult the [AWS IoT Core documentation](https://docs.aws.amazon.com/iot/) for details on certificate management and policy configuration.

## Notes & Troubleshooting
- AWS IoT Core enforces that the client ID matches the Thing name if the policy uses the `iot:Connect` condition. Verify your policy settings.
- Make sure that the Amazon Root CA certificate matches the certificate authority used by your AWS endpoint. AWS has migrated some endpoints to newer root CAs.
- If the connection is rejected, check that the AWS IoT Thing policy grants `iot:Connect`, `iot:Publish`, and `iot:Subscribe` actions for the relevant topics and client IDs.
- For subscribing to and sending shadow state, see the [TF6701_IotMqttSampleAwsIotShadow](../TF6701_IotMqttSampleAwsIotShadow/) sample.

## Support
For questions about this sample, contact your local Beckhoff support team. Contact information is available on the official Beckhoff website at https://www.beckhoff.com/contact/.
