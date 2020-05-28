#use armv7hf compatible base image
FROM balenalib/armv7hf-debian:buster-20191223

#dynamic build arguments coming from the /hooks/build file
ARG BUILD_DATE
ARG VCS_REF

#metadata labels
LABEL org.label-schema.build-date=$BUILD_DATE \
      org.label-schema.vcs-url="https://github.com/HilscherAutomation/netPI-netx-programming-examples" \
      org.label-schema.vcs-ref=$VCS_REF

#version
ENV HILSCHERNETPI_NETX_PROGRAMMING_EXAMPLES_VERSION 1.1.0

#labeling
LABEL maintainer="netpi@hilscher.com" \
      version=$HILSCHERNETPI_NETX_PROGRAMMING_EXAMPLES_VERSION \
      description="netX real-time ethernet programming examples"

#install ssh, gcc, create user "pi" and make him sudo
RUN apt-get update  \
    && apt-get install -y openssh-server build-essential \
    && mkdir /var/run/sshd \
    && useradd --create-home --shell /bin/bash pi \
    && echo 'pi:raspberry' | chpasswd \
    && adduser pi sudo 
    
#create needed folders
RUN mkdir /home/pi/manuals /home/pi/firmwares /home/pi/driver /home/pi/sources \
          /home/pi/includes \
          /home/pi/includes/EtherNetIP \
          /home/pi/includes/PROFINET \
          /home/pi/includes/EtherCAT \
          /home/pi/includes/POWERLINK \
	  /home/pi/includes/ModbusTCP \
          /home/pi/devicedescriptions/ \
          /home/pi/devicedescriptions/PROFINET \
          /home/pi/devicedescriptions/EtherNetIP \
          /home/pi/devicedescriptions/EtherCAT \
          /home/pi/devicedescriptions/POWERLINK \
          /home/pi/objs

#set the working directory
WORKDIR /home/pi

#copy the manuals
COPY ./manuals/* manuals/

#copy the firmware packages
COPY ./firmwares/* firmwares/

#copy the netx driver and include files
COPY ./driver/* driver/
COPY ./driver/includes/* /usr/include/cifx/

#copy the include files
COPY examples/includes/EtherCAT/* includes/EtherCAT/
COPY examples/includes/EtherNetIP/* includes/EtherNetIP/
COPY examples/includes/PROFINET/* includes/PROFINET/
COPY examples/includes/POWERLINK/* includes/POWERLINK/
COPY examples/includes/ModbusTCP/* includes/ModbusTCP/
COPY examples/includes/SystemPackets.h includes/
COPY examples/includes/App.h includes/
COPY examples/includes/PacketHandlerPNS.h includes/
COPY examples/includes/PacketHandlerEIS.h includes/
COPY examples/includes/PacketHandlerECS.h includes/
COPY examples/includes/PacketHandlerPLS.h includes/
COPY examples/includes/PacketHandlerOMB.h includes/

#copy the device description files such as GSDML, EDS
COPY electronic-data-sheets/PROFINET/* devicedescriptions/PROFINET/
COPY electronic-data-sheets/EtherNetIP/* devicedescriptions/EtherNetIP/
COPY electronic-data-sheets/EtherCAT/* devicedescriptions/EtherCAT/
COPY electronic-data-sheets/POWERLINK/* devicedescriptions/POWERLINK/

#copy the makefile and the application source codes
COPY examples/Makefile ./
COPY examples/sources/* sources/

#install the driver
RUN dpkg -i ./driver/netx-docker-pi-drv-2.0.1-r0.deb

#compile the applications
RUN make

#SSH port
EXPOSE 22

#the entrypoint shall start ssh
ENTRYPOINT ["/usr/sbin/sshd", "-D"]

#set STOPSGINAL
STOPSIGNAL SIGTERM

