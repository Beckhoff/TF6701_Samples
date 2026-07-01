# TF6701 MQTT Sample – AWS IoT Device Shadow

## Overview
This TwinCAT 3 sample demonstrates how to interact with the **AWS IoT Device Shadow** service using MQTT. Device Shadows allow cloud applications and other devices to read and update the last-known state of a device even when the device is offline. The TwinCAT PLC publishes shadow update messages and subscribes to the shadow document topic to receive the current shadow state.

## What this sample demonstrates
- Connecting to AWS IoT Core using MQTT over TLS
- Publishing a Device Shadow update payload to the `$aws/things/<ThingName>/shadow/update` topic
- Subscribing to the `$aws/things/<ThingName>/shadow/update/documents` topic to receive shadow state changes
- Building a JSON shadow document using `FB_JsonSaxWriter`
- Receiving shadow state via the message queue function block `FB_IotMqttMessageQueue`

## Prerequisites
- TwinCAT 3 XAE engineering environment installed on Windows
- A TwinCAT 3 XAR runtime or compatible target system that can run the PLC project
- TF6701 TC3 IoT Communication (MQTT) license installed on your target system
- Tc3_JsonXml library installed on your target system
- An active AWS account with a registered IoT Thing that has a Device Shadow enabled
- Certificate files downloaded from AWS IoT Core and accessible from the TwinCAT runtime

## Getting Started
1. In the AWS IoT Core console, create or identify a Thing. Note the Thing name.
2. Download the certificate files (Root CA, device cert, device private key) and copy them to the TwinCAT target.
3. Open the solution file [IotMqttSampleAwsIotShadow.sln](IotMqttSampleAwsIotShadow.sln).
4. In `PrgMqttCom`, update the following:
   - `stTLS.sCA`, `stTLS.sCert`, `stTLS.sKeyFile`: paths to the certificate files
   - `sHostName`: your AWS IoT Core ATS endpoint
   - `sClientId`: a unique client identifier
   - `sTopicShadowUpdate`: replace the Thing name (e.g. `$aws/things/<YourThingName>/shadow/update`)
   - `sTopicShadowDocument`: replace the Thing name accordingly
5. Build and activate the project on your target system.
6. Log in to the PLC. To trigger a shadow update, set the variable `bShadowUpdate` to `TRUE`.

## Device Shadow workflow
The AWS IoT Device Shadow service uses a set of reserved MQTT topics under the `$aws/things/<ThingName>/shadow/` prefix.

| Action | Topic |
|---|---|
| Publish shadow update | `$aws/things/<ThingName>/shadow/update` |
| Receive shadow document | `$aws/things/<ThingName>/shadow/update/documents` |

The shadow update payload must follow the JSON format defined by AWS:

```json
{
  "state": {
    "reported": {
      "Vendor": "Beckhoff Automation",
      "CpuTemperature": 42,
      "Operating System": "FreeBSD"
    }
  }
}
```

The `FB_JsonSaxWriter` function block is used to build this JSON document at runtime.

## Notes & Troubleshooting
- Make sure the AWS IoT policy grants `iot:Publish` on the shadow update topic and `iot:Subscribe` / `iot:Receive` on the shadow document topic.
- The shadow document topic (`update/documents`) delivers the full shadow document including `current` and `previous` state. The `update/accepted` topic can be used to receive only a confirmation.
- The ATS endpoint suffix (`-ats`) is recommended for newer AWS regions and CA certificates (Amazon Root CA 1 or 3).
- Please consult the [AWS IoT Device Shadow documentation](https://docs.aws.amazon.com/iot/latest/developerguide/iot-device-shadows.html) for the full JSON schema and available shadow topics.

## Support
For questions about this sample, contact your local Beckhoff support team. Contact information is available on the official Beckhoff website at https://www.beckhoff.com/contact/.
