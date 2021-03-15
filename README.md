Roseguarden Firmware
====================

This is the firmware for a Roseguarden door node based on an ESP32 microcontroller.

### Project Setup

The firmware is based on ESP-IDF with its CMake build system which is supported by different IDEs.

#### Eclipse with IDF-Plugin

Please check the [documentation](https://github.com/espressif/idf-eclipse-plugin) for a detailed description on how to install the IDE and the toolchain.  
Here's a short summary of the minimal installation steps needed on a linux system:

- Checkout submodules
- Download [Eclipse CDT 2020-12](https://www.eclipse.org/downloads/packages/release/2020-12/r/eclipse-ide-cc-developers), extract the archive and start the eclipse executable
- Create a fresh workspace somewhere
- [Install the Eclipse IDF Plugin](https://github.com/espressif/idf-eclipse-plugin#installing-idf-plugin-using-update-site-url)
- [Select the existing IDF](https://github.com/espressif/idf-eclipse-plugin#installing-esp-idf) that is located inside the `idf` folder in this project.
- Install the tools as requested. This will take some time with no output in the eclipse terminal
- Connect the ESP to the computer (for the serial port to appear in the next step)
- [Create a launch target](https://github.com/espressif/idf-eclipse-plugin#configuring-launch-target) for the connected board
- [Import](https://github.com/espressif/idf-eclipse-plugin#ImportProject) the roseuguard-firmware project
- Restart eclipse (otherwise the build fill fail with an indefinite error at this point)
- Build the project by clicking on the hammer symbol
- Flash the binary by pressing the play symbol

#### Headless build

Checkout all submodules

    git submodule update --recursive --depth 1

Install the IDF shipped with this project

    ./idf/install.sh

Setup environment variables for the current shell instance (so future calls to `idf.py` will work)

    . ./idf/export.sh

Run the build

    idf.py build

Flash the binary (it should autodetect the serial port)

    idf.py flash

Display logging output

    idf.py monitor


### Hardware Setup

The MOD-RFID1356MIFARE can be powered from USB or directly via the UEXT port. Bridge the little jumper on the back side to power it directly from the 3.3V provided by the UEXT port. Once this jumper is bridged one shouldn't connect USB and UEXT at the same time.

The MOD-RFID1356MIFARE has to be set to its UART-Mode. Power the device (either via USB or by connecting it to a UEXT port), press and hold the button until both LEDs (green and red) blink. The mode will be saved and the device will boot into the same mode upon the next power cycle.

## Configuration

To customize a build use the `Roseguarden` entry in idf's menuconfig:

|IDE | How to access `menuconfig` |
|-|-|
| Commandline | `idf.py menuconfig` |
| Eclipse IDF-Plugin | Open the file `sdkconfig` |

Some configuration values are set via 'sdkconfig.defaults'. Depending one the environment (production/development) one should select the behaviour of the panic handler. It should reboot the device in a production environment, while starting a gdb stub is more helpful during development.

### Certificate

Currently only the certificate `cert.pem` is trusted (and may be used as a trust anchor for TLS connections).
