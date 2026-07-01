# TF6701 MQTT Sample – TLS with Pre-Shared Key (PSK)

## Overview
This TwinCAT 3 sample demonstrates how to establish a secure, encrypted MQTT connection using **TLS with a Pre-Shared Key (PSK)**. PSK-based TLS is an alternative to certificate-based TLS that uses a shared secret key and an identity string instead of X.509 certificates.

## What this sample demonstrates
- Configuring `stTLS` on `FB_IotMqttClient` for PSK-based TLS authentication
- Setting the PSK identity string and the binary key value
- Connecting to a broker on port 8883 with PSK encryption
- Publishing messages over a PSK-secured MQTT connection

## Prerequisites
- TwinCAT 3 XAE engineering environment installed on Windows
- A TwinCAT 3 XAR runtime or compatible target system that can run the PLC project
- TF6701 TC3 IoT Communication (MQTT) license installed on your target system
- An MQTT broker configured for PSK-based TLS (e.g. Mosquitto with `mosquitto_secureTlsPsk.conf` and `myKeys.psk`, see [Mosquitto](../Mosquitto/) folder)

## Getting Started
1. Configure your broker with PSK support. The [Mosquitto](../Mosquitto/) folder contains the files `mosquitto_secureTlsPsk.conf` and `myKeys.psk` as a starting point.
2. Open the solution file [IotMqttSampleTlsPsk.sln](IotMqttSampleTlsPsk.sln).
3. In `PrgMqttCom`, verify that `stTLS.sPskIdentity` matches an identity in your broker's PSK file and that `stTLS.aPskKey` and `stTLS.nPskKeyLen` match the corresponding key.
4. Build and activate the project on your target system.

## Configuring PSK parameters
The PSK parameters are set on the `stTLS` field of `FB_IotMqttClient`:

| Parameter | Description |
|---|---|
| `stTLS.sPskIdentity` | PSK identity string (must match an entry in the broker's PSK file) |
| `stTLS.aPskKey` | Binary PSK key as `ARRAY OF BYTE` |
| `stTLS.nPskKeyLen` | Length of the key in bytes |

The Mosquitto PSK file (`myKeys.psk`) uses the format `identity:hex_key` — for example:
```
my_Identity:1BD06FD256167DC1E8C7482A8EF5FF
```

## Notes & Troubleshooting
- PSK-based TLS is simpler to set up than certificate-based TLS but may not be supported by all MQTT brokers or cloud services.
- Make sure that `nPskKeyLen` matches the actual number of bytes in the key, not the hex string length.
- For TLS with X.509 certificates instead of PSK, see the [TF6701_IotMqttSampleTls](../TF6701_IotMqttSampleTls/) sample.
- This sample includes a local Mosquitto configuration file (`mosquitto_tlspsk.conf`) and a PSK key file (`mosquitto_pskFile.txt`) in the project folder as a reference.

## Support
For questions about this sample, contact your local Beckhoff support team. Contact information is available on the official Beckhoff website at https://www.beckhoff.com/contact/.
