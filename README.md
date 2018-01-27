# ws-simple-BLE-communication

This is simple serial passthrough program to enable communication between PC (USB) and BLE (Serial2).

>**IMPORTANT! -- In order for this program to work the MCU has to be setup as described in Bootloader & Setup [readme](https://github.com/inovatink/wearable-sensor-hardware/tree/master/Bootloader%20%26%20Setup) of wearable-sensor-hardware repo.

## BLE Module Commands

BLE module used in wearable sensor is RN4870. Firmware inside RN4870 provides the control interface based on ASCII commands sent over
UART. In wearable sensor MCU and RN4870 are connected through Serial2 UART.

The ASCII commands can control functions such as connection setup, accessing Generic Attribute Profile (GATT) characteristics, changing
configuration settings, and reading status. The UART can operate in Command mode, to receive ASCII commands, or Data mode to exchange data using “Transparent UART” Bluetooth service.

For wearable sensor the most basic use of module will be following;
* initialize Serial2 to be able to send commands to module
* configure module so that BLE hub (RPI3 or smartphone) can discover and connect to the module
* configure other necessary parameters
* once connection is established, use module in Transparent UART mode

Necessary commands to setup proper operation of module as described above can be found in [RN4870 User Guide](http://ww1.microchip.com/downloads/en/DeviceDoc/50002466B.pdf). Table below summarizes the most basic commands.

