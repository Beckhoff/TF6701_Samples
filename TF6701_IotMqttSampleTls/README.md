# TF6701 MQTT Sample – TLS with Certificate-Based Authentication

## Overview
This TwinCAT 3 sample demonstrates how to establish a secure, encrypted MQTT connection using **TLS with X.509 certificates**. The connection parameters in `stTLS` are configured with a CA certificate, a client certificate, and a client private key.

## What this sample demonstrates
- Configuring `stTLS` on `FB_IotMqttClient` to enable TLS
- Providing CA certificate, client certificate, and private key paths
- Connecting to a broker on the standard TLS port 8883
- Publishing and subscribing over an encrypted MQTT connection
- Receiving messages via `FB_IotMqttMessageQueue`

## Prerequisites
- TwinCAT 3 XAE engineering environment installed on Windows
- A TwinCAT 3 XAR runtime or compatible target system that can run the PLC project
- TF6701 TC3 IoT Communication (MQTT) license installed on your target system
- An MQTT broker configured for TLS with certificate authentication (e.g. Mosquitto with `mosquitto_secureTlsCert.conf`, see [Mosquitto](../Mosquitto/) folder)
- A CA certificate, client certificate, and client private key file accessible from the TwinCAT runtime

## Getting Started
1. Generate or obtain your certificates (CA cert, client cert, client private key).
2. Place the certificate files in a location accessible by the TwinCAT runtime (e.g. `C:\TwinCAT\3.1\Config\Certificates\`).
3. Start your broker with TLS enabled (e.g. Mosquitto with `mosquitto_secureTlsCert.conf`).
4. Open the solution file [IotMqttSampleTls.sln](IotMqttSampleTls.sln).
5. In `PrgMqttCom`, replace the `%HOSTNAME%`, `%CLIENTID%`, `%CACERT%`, `%CLIENTCERT%`, and `%CLIENTKEY%` placeholders with your actual values.
6. Build and activate the project on your target system.

## Configuring TLS parameters
The TLS parameters are set on the `stTLS` field of `FB_IotMqttClient`:

| Parameter | Description |
|---|---|
| `stTLS.sCA` | File path to the CA certificate (PEM format) |
| `stTLS.sCert` | File path to the client certificate (PEM format) |
| `stTLS.sKeyFile` | File path to the client private key file |

The broker port must be set to `8883` (or another port configured for TLS on your broker).

## Notes & Troubleshooting
- All certificate paths must be accessible from the TwinCAT runtime process on the target system.
- Make sure the client certificate has been signed by the CA that the broker trusts.
- If the TLS handshake fails, verify that the certificate chain is valid and that the system time on the target is correct (certificate validity periods are checked).
- For TLS with Pre-Shared Key (PSK) instead of certificates, see the [TF6701_IotMqttSampleTlsPsk](../TF6701_IotMqttSampleTlsPsk/) sample.

## Support
For questions about this sample, contact your local Beckhoff support team. Contact information is available on the official Beckhoff website at https://www.beckhoff.com/contact/.
