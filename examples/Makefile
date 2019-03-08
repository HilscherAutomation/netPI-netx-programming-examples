GCC = gcc

CFLAGS =

SRCPATH = .

LIBS = -lcifx

OBJDIR = ./objs

SOURCES = $(SRCPATH)/sources

INCDIRS = -I/usr/include/cifx -Iincludes/

INCDIRS_PNS = -I/usr/include/cifx -Iincludes/PROFINET -Iincludes/
INCDIRS_EIS = -I/usr/include/cifx -Iincludes/EtherNetIP -Iincludes/
INCDIRS_ECS = -I/usr/include/cifx -Iincludes/EtherCAT -Iincludes/
INCDIRS_PLS = -I/usr/include/cifx -Iincludes/POWERLINK -Iincludes/
INCDIRS_OMB = -I/usr/include/cifx -Iincludes/ModbusTCP -Iincludes/


all:							$(SRCPATH)/PNS_simpleConfig $(SRCPATH)/EIS_simpleConfig $(SRCPATH)/ECS_simpleConfig $(SRCPATH)/PLS_simpleConfig $(SRCPATH)/OMB_simpleConfig





$(SRCPATH)/PNS_simpleConfig:	$(OBJDIR)/PNS_simpleConfig.o $(OBJDIR)/SystemPackets.o $(OBJDIR)/PacketHandlerPNS.o 

								$(GCC) $(LIBS) -o $(SRCPATH)/PNS_simpleConfig $(OBJDIR)/PNS_simpleConfig.o $(OBJDIR)/SystemPackets.o $(OBJDIR)/PacketHandlerPNS.o



$(SRCPATH)/EIS_simpleConfig:	$(OBJDIR)/EIS_simpleConfig.o $(OBJDIR)/SystemPackets.o $(OBJDIR)/PacketHandlerEIS.o 

								$(GCC) $(LIBS) -o $(SRCPATH)/EIS_simpleConfig $(OBJDIR)/EIS_simpleConfig.o $(OBJDIR)/SystemPackets.o $(OBJDIR)/PacketHandlerEIS.o



$(SRCPATH)/ECS_simpleConfig:	$(OBJDIR)/ECS_simpleConfig.o $(OBJDIR)/SystemPackets.o $(OBJDIR)/PacketHandlerECS.o

								$(GCC) $(LIBS) -o $(SRCPATH)/ECS_simpleConfig $(OBJDIR)/ECS_simpleConfig.o $(OBJDIR)/SystemPackets.o $(OBJDIR)/PacketHandlerECS.o



$(SRCPATH)/PLS_simpleConfig:	$(OBJDIR)/PLS_simpleConfig.o $(OBJDIR)/SystemPackets.o $(OBJDIR)/PacketHandlerPLS.o

								$(GCC) $(LIBS) -o $(SRCPATH)/PLS_simpleConfig $(OBJDIR)/PLS_simpleConfig.o $(OBJDIR)/SystemPackets.o $(OBJDIR)/PacketHandlerPLS.o



$(SRCPATH)/OMB_simpleConfig:	$(OBJDIR)/OMB_simpleConfig.o $(OBJDIR)/SystemPackets.o $(OBJDIR)/PacketHandlerOMB.o

								$(GCC) $(LIBS) -o $(SRCPATH)/OMB_simpleConfig $(OBJDIR)/OMB_simpleConfig.o $(OBJDIR)/SystemPackets.o $(OBJDIR)/PacketHandlerOMB.o                                



$(OBJDIR)/PNS_simpleConfig.o:	$(SOURCES)/PNS_simpleConfig.c

								$(GCC) $(CFLAGS) -c $(SOURCES)/PNS_simpleConfig.c -o $(OBJDIR)/PNS_simpleConfig.o $(INCDIRS_PNS)



$(OBJDIR)/EIS_simpleConfig.o:	$(SOURCES)/EIS_simpleConfig.c

								$(GCC) $(CFLAGS) -c $(SOURCES)/EIS_simpleConfig.c -o $(OBJDIR)/EIS_simpleConfig.o $(INCDIRS_EIS)



$(OBJDIR)/ECS_simpleConfig.o:	$(SOURCES)/ECS_simpleConfig.c

								$(GCC) $(CFLAGS) -c $(SOURCES)/ECS_simpleConfig.c -o $(OBJDIR)/ECS_simpleConfig.o $(INCDIRS_ECS)



$(OBJDIR)/PLS_simpleConfig.o:	$(SOURCES)/PLS_simpleConfig.c

								$(GCC) $(CFLAGS) -c $(SOURCES)/PLS_simpleConfig.c -o $(OBJDIR)/PLS_simpleConfig.o $(INCDIRS_PLS)



$(OBJDIR)/OMB_simpleConfig.o:	$(SOURCES)/OMB_simpleConfig.c

								$(GCC) $(CFLAGS) -c $(SOURCES)/OMB_simpleConfig.c -o $(OBJDIR)/OMB_simpleConfig.o $(INCDIRS_OMB)                                



$(OBJDIR)/SystemPackets.o:		$(SOURCES)/SystemPackets.c

								$(GCC) $(CFLAGS) -c $(SOURCES)/SystemPackets.c -o $(OBJDIR)/SystemPackets.o $(INCDIRS)





$(OBJDIR)/PacketHandlerPNS.o:	$(SOURCES)/PacketHandlerPNS.c

								$(GCC) $(CFLAGS) -c $(SOURCES)/PacketHandlerPNS.c -o $(OBJDIR)/PacketHandlerPNS.o $(INCDIRS_PNS)



$(OBJDIR)/PacketHandlerEIS.o:	$(SOURCES)/PacketHandlerEIS.c

								$(GCC) $(CFLAGS) -c $(SOURCES)/PacketHandlerEIS.c -o $(OBJDIR)/PacketHandlerEIS.o $(INCDIRS_EIS)



$(OBJDIR)/PacketHandlerECS.o:	$(SOURCES)/PacketHandlerECS.c

								$(GCC) $(CFLAGS) -c $(SOURCES)/PacketHandlerECS.c -o $(OBJDIR)/PacketHandlerECS.o $(INCDIRS_ECS)

						

$(OBJDIR)/PacketHandlerPLS.o:	$(SOURCES)/PacketHandlerPLS.c

								$(GCC) $(CFLAGS) -c $(SOURCES)/PacketHandlerPLS.c -o $(OBJDIR)/PacketHandlerPLS.o $(INCDIRS_PLS)



$(OBJDIR)/PacketHandlerOMB.o:	$(SOURCES)/PacketHandlerOMB.c

								$(GCC) $(CFLAGS) -c $(SOURCES)/PacketHandlerOMB.c -o $(OBJDIR)/PacketHandlerOMB.o $(INCDIRS_OMB)                                						



clean:

						rm $(OBJDIR)/*.o



