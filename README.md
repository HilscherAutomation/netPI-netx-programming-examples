## netX programming

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![](https://images.microbadger.com/badges/commit/hilschernetpi/netpi-netx-programming-examples.svg)](https://microbadger.com/images/hilschernetpi/netpi-netx-programming-examples "netX programming examples")
[![Docker Registry](https://img.shields.io/docker/pulls/hilschernetpi/netpi-netx-programming-examples.svg)](https://registry.hub.docker.com/r/hilschernetpi/netpi-netx-programming-examples/)&nbsp;
[![Image last updated](https://img.shields.io/badge/dynamic/json.svg?url=https://api.microbadger.com/v1/images/hilschernetpi/netpi-netx-programming-examples&label=Image%20last%20updated&query=$.LastUpdated&colorB=007ec6)](http://microbadger.com/images/hilschernetpi/netpi-netx-programming-examples "Image last updated")&nbsp;

Made for Raspberry Pi 3B architecture based devices and compatibles featuring a netX51 industrial network controller

### Container features

The image provided herunder deploys a container that includes different programming examples for the on-board netX51 industrial network controller.

Base of this image builds [debian](https://www.balena.io/docs/reference/base-images/base-images/) with enabled [SSH](https://en.wikipedia.org/wiki/Secure_Shell) and created user 'pi'.

Additionally the image contains netX51 programming examples in source code and as precompiled executables for the following protocols

* PROFINET IO-device 
* EtherNet/IP adapter
* EtherCAT slave
* POWERLINK slave
* Modbus/TCP server

### Container hosts

The container has been successfully tested on the following Docker hosts

* netPI, model RTE 3, product name NIOT-E-NPI3-51-EN-RE
* netIOT Connect, product name NIOT-E-TPI51-EN-RE
* netFIELD Connect, product name NIOT-E-TPI51-EN-RE/NFLD

netPI devices specifically feature a restricted Docker protecting the Docker host system software's integrity by maximum. The restrictions are

* privileged mode is not automatically adding all host devices `/dev/` to a container
* volume bind mounts to rootfs is not supported
* the devices `/dev`,`/dev/mem`,`/dev/sd*`,`/dev/dm*`,`/dev/mapper`,`/dev/mmcblk*` cannot be added to a container

### Container setup

#### Port mapping

For enabling remote login to the container across SSH the container's SSH port 22 needs to be exposed to the host.

#### Host device

To grant access to the netX from inside the container the `/dev/spidev0.0` host device needs to be added to the container.

### Container deployment

Pulling the image may take 10 minutes.

#### netPI example

STEP 1. Open netPI's web UI in your browser (https).

STEP 2. Click the Docker tile to open the [Portainer.io](http://portainer.io/) Docker management user interface.

STEP 3. Enter the following parameters under *Containers > + Add Container*

Parameter | Value | Remark
:---------|:------ |:------
*Image* | **hilschernetpi/netpi-netx-programming-examples**
*Port mapping* | *host* **unused port e.g.23** -> *container* **22** | 
*Restart policy* | **always**
*Runtime > Devices > +add device* | *Host path* **/dev/spidev0.0** -> *Container path* **/dev/spidev0.0** |

STEP 4. Press the button **Actions > Start/Deploy container**

#### Docker command line example

`docker run -d --restart=always --device=/dev/spidev0.0:/dev/spidev0.0 -p 23:22/tcp hilschernetpi/netpi-netx-programming-examples`

#### Docker compose example

A `docker-compose.yml` file could look like this

    version: "2"

    services:
     nodered:
       image: hilschernetpi/netpi-netx-programming-examples
       restart: always
       ports:
         - 23:22
       devices:
         - "/dev/spidev0.0:/dev/spidev0.0"

### Container access

The container starts the SSH server automatically when deployed. 

For an SSH terminal session use an SSH client such as [putty](http://www.putty.org/) with the Docker host IP address (@port number mapped e.g.23).

Use the credentials `pi` as user and `raspberry` as password when asked and you are logged in as non-root user `pi`.

Continue to use [Linux commands](https://www.raspberrypi.org/documentation/linux/usage/commands.md) in the terminal as usual.

#### Container files and folders

The login directs you to the pi user home directory /home/pi with following structure

```
/home/pi/
       |
       +--/devicedescriptions   - device description files such as EDS, GSDML, ESI needed for master engineering
       +--/driver               - netX driver installation package
       +--/firmwares            - netX firmware installation packages
       +--/includes             - protocol specific include files for compilation
       +--/manuals              - common cifX API manual and protocol specific API manuals
       +--/objs                 - folder where the object files of the compilation process are stored to
       +--/sources              - protocol specific source codes of the demos
       | Makefile               - Makefile to compile all example applications using 'make' command
       | PNS_simpleConfig       - precompiled and executable PROFINET IO device example 
       | EIS_simpleConfig       - precompiled and executable EtherNet/IP adapter example
       | ECS_simpleConfig       - precompiled and executable EtherCAT slave example
       | PLS_simpleConfig       - precompiled and executable POWERLINK slave example
       | OMB_simpleConfig       - precompiled and executable Modbus/TCP server example
```
##### netX driver installation

To install the netX SPI driver package move to the `driver` folder and call 

`dpkg -i netx-docker-pi-drv-2.0.1-r0.deb`

The driver will be installed into the folder `/opt/cifx`. 

The cifX API function library needed for linking will be installed into folder `/usr/lib`. 

Basic include files needed for the compilation process will be installed into folder `/usr/include`.

##### netX firmware installation

To install a firmware package move to the folder `firmwares` and call

* `dpkg -i netx-docker-pi-pns-3.14.0.5.deb` for PROFINET IO device firmware or  
* `dpkg -i netx-docker-pi-eis-2.14.0.2.deb` for EtherNet/IP adapter firmware or
* `dpkg -i netx-docker-pi-ecs-4.7.0.2.deb` for EtherCAT slave firmware or
* `dpkg -i netx-docker-pi-pls-3.3.0.0.deb` for POWERLINK slave firmware or
* `dpkg -i netx-docker-pi-omb-2.6.0.6.deb` for Modbus/TCP server firmware

Any firmware package extracts its firmware into the folder `/opt/cifx/deviceconfig/FW/channel0`. 

The firmware will be automatically loaded by the driver into the netX network controller when the driver is accesed by an application the first time using the `cifXDriverInit()` function.

There can be only one installed netX firmware package at a time. An existing package will be automatically uninstalled during the installation procedure.

##### Compiling the programming examples

To compile the programming examples simply call `make` in the pi home directory. The command will locate the `Makefile` which initiates the compilation process.

The following executables will be compiled

* `PNS_simpleConfig` as PROFINET IO device demo
* `EIS_simpleConfig` as EtherNet/IP adapter demo
* `ECS_simpleConfig` as EtherCAT slave demo
* `PLS_simpleConfig` as POWERLINK slave demo
* `OMB_simpleConfig` as Modbus/TCP server demo

You may be faced with the following warning during compilation process

`make: warning:  Clock skew detected.  Your build may be incomplete.`

There is a discrepancy between netPI's system clock and the time the executeables/object files have been generated. Call `make clean` and remove the executeable. Then start the compilation process again. Make also sure you have set netPI's system clock correctly.

##### Changing the default IO size of 10 bytes input and 4 bytes output

All three examples configure a process data input length of 10 bytes and an output length 4 bytes. The provided electronic data sheets for the master/controller engineering software match exactly to this example size.

If a different IO length is required you have to adjust the length in the file `/includes/App.h` in the structures APP_INPUT_DATA_T and APP_OUTPUT_DATA_T accordingly. Please take into account that there is a limit of maximum allowed IO length. This limit can be found in each of the three programming manuals provided in the folder ./manuals.

Afterwards recompile and start the new examples to become effective. Make sure you also modify the device description files and reload them into the master/contoller engineering software to sychronize the project with the new physical setup.

##### Starting the pre-compiled executables

To start the pre-compiled examples call the following executeables in the pi home directory

* `sudo ./PNS_simpleConfig` for the PROFINET IO device example
* `sudo ./EIS_simpleConfig` for the EtherNet/IP adapter example
* `sudo ./ECS_simpleConfig` for the EtherCAT slave example
* `sudo ./PLS_simpleConfig` for the POWERLINK slave example
* `sudo ./OMB_simpleConfig` for the Modbus/TCP server example

Each example checks if the related firmware package has been installed properly. It not it installs the package prior operation.

##### Electronic Data Sheets

Any master/controller engineering software needs device descriptions, socalled electronic data sheets, of all IO devices it shall communicate to. They inform about device parameters such as vendor-ID, product-ID, name, IO length etc. For all three examples the devices description files can be found in the github project under `/electronic-data-sheets`.

By default the provided files are preconfigured to an IO length of 10 bytes input and 4 bytes output. In case you modified an example to configure a different IO length you have to modify the electronic data sheet accordingly and reconfigure your master/controller with it.

##### Protocol specifics

In case of PROFINET please keep in mind that a virgin netX needs a PROFINET device name setup over the network as described [here](https://profinetuniversity.com/profinet-basics/dcp/profinet-dcp/). Use your master engineering software to assign a corresponding name ("netx51repns" which is default in the electronic data sheet).

##### Linking the cifX library to applications

To link the cifX driver library to own applications just add the option `-lcifx` to your GCC compilation command.

##### The cifX API funtions reference (netX driver API)

The cifX driver's function application interfaace (API) is described in the manual 

`cifX_API_PR_08_EN.pdf` 

located in the `manuals` folder. These call functions provide you a simple interface between your application and netX network controller.

##### The protocol specific APIs (PROFINET, EtherNet/IP ... APIs)

A netX firmware has a common part that is behaving the same for all firmwares and a protocol dependent specific part. Particularly the configuration varies from protocol to protocol and shows different characteristics.

The protocol specific dependencies are described in the manuals

* `PROFINET IO-Device V3.14 Protocol API 19 EN.pdf` for PROFINET IO device 
* `EtherNetIP_Adapter_Protocol_API_20_EN.pdf` for EtherNet/IP adapter
* `EtherCAT Slave V4 Protocol API 09 EN.pdf` for EtherCAT slave
* `POWERLINK Slave V4 Protocol API 09 EN.pdf` for POWERLINK slave
* `OpenModbusTCP Protocol API 10 EN.pdf` for Modbus TCP server

located in the `manuals` folder.

### License

Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All rights reserved.
Licensed under the LISENSE.txt file information stored in the project's source code repository.

As with all Docker images, these likely also contain other software which may be under other licenses (such as Bash, etc from the base distribution, along with any direct or indirect dependencies of the primary software being contained).
As for any pre-built image usage, it is the image user's responsibility to ensure that any use of this image complies with any relevant licenses for all software contained within.

[![N|Solid](http://www.hilscher.com/fileadmin/templates/doctima_2013/resources/Images/logo_hilscher.png)](http://www.hilscher.com)  Hilscher Gesellschaft fuer Systemautomation mbH  www.hilscher.com
