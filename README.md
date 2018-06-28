## netX programming examples

Made for [netPI RTE 3](https://www.netiot.com/netpi/), the Open Edge Connectivity Ecosystem with Real-Time Ethernet

### netX sample applications for PROFINET, EtherNet/IP and EtherCAT

Base of this image builds a tagged version of [debian:jessie](https://hub.docker.com/r/resin/armv7hf-debian/tags/) with enabled [SSH](https://en.wikipedia.org/wiki/Secure_Shell) and created user 'pi'.

Additionally the image provides netX programming examples in source code (and as precompiled executables) for 

* PROFINET IO-device 
* EtherNet/IP adapter
* EtherCAT slave

#### Container prerequisites

##### Port mapping

For enabling remote login to the container across SSH the container's SSH port 22 needs to be exposed to the host.

##### Host device

To grant access to the netX from inside the container the `/dev/spidev0.0` host device needs to be added to the container.

#### Getting started

STEP 1. Open netPI's landing page under `https://<netpi's ip address>`.

STEP 2. Click the Docker tile to open the [Portainer.io](http://portainer.io/) Docker management user interface.

STEP 3. Enter the following parameters under **Containers > Add Container**

* **Image**: `hilschernetpi/netpi-netx-programming-examples`

* **Port mapping**: `Host "22" (any unused one) -> Container "22"` 

* **Restart policy"** : `always`

* **Runtime > Devices > add device**: `Host "/dev/spidev0.0" -> Container "/dev/spidev0.0"`

STEP 4. Press the button **Actions > Start container**

Pulling the image from Docker Hub may take up to 5 minutes.

#### Accessing

The container starts the SSH service automatically.

Login to it with an SSH client such as [putty](http://www.putty.org/) using netPI's IP address at your mapped port. Use the credentials `pi` as user and `raspberry` as password when asked and you are logged in as non-root user `pi`.

##### Files and folders

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
```
##### netX driver installation

To install the netX SPI driver package move to the `driver` folder and call 

`dpkg -i netx-docker-pi-drv-1.1.3.deb`

The driver will be installed into the folder `/opt/cifx`. 

The cifX API function library needed for linking will be installed into folder `/usr/lib`. 

Basic include files needed for the compilation process will be installed into folder `/usr/include`.

##### netX firmware installation

To install a firmware package move to the folder `firmwares` and call

* `dpkg -i netpi-docker-pi-pns-3.12.0.2.deb` for PROFINET IO device firmware or  
* `dpkg -i netpi-docker-pi-eis-2.12.5.0.deb` for EtherNet/IP adapter firmware or
* `dpkg -i netpi-docker-pi-ecs-4.7.0.2.deb` for EtherCAT slave firmware

Any firmware package extracts its firmware into the folder `/opt/cifx/deviceconfig/FW/channel0`. 

The firmware will be loaded by the driver into netX network controller the first time the driver is accessed using the `cifXDriverInit()` command.

There can be only one installed netX firmware package at a time. An existing package will be automatically uninstalled during the installation procedure.

##### Compiling the programming examples

To compile the programming examples simply call `make` in the pi home directory. The command will locate the `Makefile` which initiates the compilation process.

The following executables will be compiled

* `PNS_simpleConfig` as PROFINET IO device demo
* `EIS_simpleConfig` as EtherNet/IP adapter demo
* `ECS_simpleConfig` as EtherCAT slave demo

You may be faced with the following warning during compilation process

`make: warning:  Clock skew detected.  Your build may be incomplete.`

There is a discrepancy between netPI's system clock and the time the executeables/object files have been generated. Call `make clean` and remove the executeable. Then start the compilation process again. Make also sure you have set netPI's system clock correctly.

##### Changing the default IO size of 10 bytes input and 4 bytes output

All three examples configure a process data input length of 10 bytes and an output length 4 bytes. The provided electronic data sheets for the master/controller engineering software match exactly to this example size.

If a different IO length is required you have to adjust the length in the file `/includes/App.h` in the structures APP_INPUT_DATA_T and APP_OUTPUT_DATA_T accordingly. Please take into account that there is a limit of maximum allowed IO length. This limit can be found in each of the three programming manuals provided in the folder ./manuals.

Afterwards recompile and start the new examples to become effective. Make sure you also modify the device description files and reload them into the master/contoller engineering software to sychronize the project with the new physical setup.

##### Starting the executables

To start the compiled examples call the following executeables in the pi home directory

* `sudo ./PNS_simpleConfig` for the PROFINET IO device example
* `sudo ./EIS_simpleConfig` for the EtherNet/IP adapter example
* `sudo ./ECS_simpleConfig` for the EtherCAT slave example

Each example checks if its corresponding firmware package has been installed properly and loaded into netX, else it will install and load it automatically.

##### Electronic Data Sheets

Any master/controller engineering software needs device descriptions, socalled electronic data sheets, of all IO devices it shall communicate to. They inform about device parameters such as vendor-ID, product-ID, name, IO length etc. For all three examples the devices description files can be found in the github project under `/electronic-data-sheets`.

By default the provided files are preconfigured to an IO length of 10 bytes input and 4 bytes output. In case you modified an example to configure a different IO length you have to modify the electronic data sheet accordingly and reconfigure your master/controller with it.

##### Protocol specifics

In case of PROFINET please keep in mind that a virgin netX needs a PROFINET device name setup over the network as described [here](https://profinetuniversity.com/profinet-basics/dcp/profinet-dcp/). Use your master engineering software to assign a corresponding name ("netx51repns" which is default in the electronic data sheet).

##### Linking the cifX library to applications

To link the cifX driver library to own applications just add the option `-lcifx` to your GCC compilation command.

##### The cifX API funtions reference (netX driver API)

The cifX driver's function application interfaace (API) is described in the manual 

`cifX_API_PR_04_EN.pdf` 

located in the `manuals` folder. These call functions provide you a simple interface between your application and netX network controller.

##### The protocol specific APIs (PROFINET, EtherNet/IP ... APIs)

A netX firmware has a common part that is behaving the same for all firmwares and a protocol dependent specific part. Particularly the configuration varies from protocol to protocol and shows different characteristics.

The protocol specific dependencies are described in the manuals

* `PROFINET_IO-Device_V3.12_Protocol_API_17_EN.pdf` for PROFINET IO device 
* `EtherNetIP_Adapter_Protocol_API_19_EN.pdf` for EtherNet/IP adapter
* `EtherCAT Slave V4 Protocol API 09 EN.pdf` for EtherCAT slave

located in the `manuals` folder.

#### Tags

* **hilscher/netPI-net-programming-examples:latest** - non-versioned latest development output of the master branch. Can run on any netPI RTE 3 system software version.

#### GitHub sources

The image is built from the GitHub project [netPI-netx-programming-examples](https://github.com/Hilscher/netPI-netx-programming-examples). It complies with the [Dockerfile](https://docs.docker.com/engine/reference/builder/) method to build a Docker image [automated](https://docs.docker.com/docker-hub/builds/).

View the license information for the software in the Github project. As with all Docker images, these likely also contain other software which may be under other licenses (such as Bash, etc from the base distribution, along with any direct or indirect dependencies of the primary software being contained).
As for any pre-built image usage, it is the image user's responsibility to ensure that any use of this image complies with any relevant licenses for all software contained within.

To build the container for an ARM CPU on [Docker Hub](https://hub.docker.com/)(x86 based) the Dockerfile uses the method described here [resin.io](https://resin.io/blog/building-arm-containers-on-any-x86-machine-even-dockerhub/).

[![N|Solid](http://www.hilscher.com/fileadmin/templates/doctima_2013/resources/Images/logo_hilscher.png)](http://www.hilscher.com)  Hilscher Gesellschaft fuer Systemautomation mbH  www.hilscher.com
