#
# OMNeT++/OMNEST Makefile for blegossipprj
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out
#

# Name of target to be created (-o option)
TARGET = blegossipprj$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(QTENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)
#USERIF_LIBS = $(QTENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -IiniFile \
    -IiniFile/D00001 \
    -IiniFile/D00005 \
    -IiniFile/D0001 \
    -IiniFile/D0008 \
    -IiniFile/D001 \
    -IiniFile/D002 \
    -IiniFile/noD \
    -Inet \
    -Inet/randomgeometricgraph \
    -Iresults \
    -Iresults/D0001 \
    -Iresults/D0001/r50D0001 \
    -Iresults/D0001/r50D0001/rgg100 \
    -Iresults/D0008 \
    -Iresults/D0008/r10D0008 \
    -Iresults/D0008/r10D0008/General \
    -Iresults/D0008/r10D0008/rgg5 \
    -Iresults/D0008/r15D0008 \
    -Iresults/D0008/r15D0008/General \
    -Iresults/D0008/r15D0008/rgg5 \
    -Iresults/D002 \
    -Iresults/D002/r10D002 \
    -Iresults/noD \
    -Iresults/noD/r10D002 \
    -Iresults/noD/r10D002/General \
    -Isrc \
    -Isrc/battery \
    -Isrc/bluetooth \
    -Isrc/coordinate \
    -Isrc/coordinate/bidimensional \
    -Isrc/message \
    -Isrc/message/bluetooth \
    -Isrc/node \
    -Isrc/node/models \
    -Isrc/node/statistics \
    -Isrc/protocol

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cpp, .msg and .sm files
OBJS = \
    $O/src/battery/BatteryManager.o \
    $O/src/bluetooth/BTFsaManager.o \
    $O/src/coordinate/bidimensional/Coordinate2D.o \
    $O/src/message/bluetooth/BTMessageGenerator.o \
    $O/src/node/models/RandomGeometricNode.o \
    $O/src/node/statistics/StatisticsCollector.o \
    $O/src/protocol/AdvertiseLimit.o \
    $O/src/protocol/Bound.o \
    $O/src/protocol/DynamicFanout.o \
    $O/src/protocol/ProtocolManager.o \
    $O/src/message/bluetooth/btmessage_m.o

# Message files
MSGFILES = \
    src/message/bluetooth/btmessage.msg

# SM files
SMFILES =

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)
SMCOPTS =

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders smheaders

.SUFFIXES: .cpp

$O/%.o: %.cpp $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cpp %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cpp $(MSGCOPTS) $?

%_sm.cpp %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cpp $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f blegossipprj blegossipprj.exe libblegossipprj.so libblegossipprj.a libblegossipprj.dll libblegossipprj.dylib
	$(Q)-rm -f ./*_m.cpp ./*_m.h ./*_sm.cpp ./*_sm.h
	$(Q)-rm -f iniFile/*_m.cpp iniFile/*_m.h iniFile/*_sm.cpp iniFile/*_sm.h
	$(Q)-rm -f iniFile/D00001/*_m.cpp iniFile/D00001/*_m.h iniFile/D00001/*_sm.cpp iniFile/D00001/*_sm.h
	$(Q)-rm -f iniFile/D00005/*_m.cpp iniFile/D00005/*_m.h iniFile/D00005/*_sm.cpp iniFile/D00005/*_sm.h
	$(Q)-rm -f iniFile/D0001/*_m.cpp iniFile/D0001/*_m.h iniFile/D0001/*_sm.cpp iniFile/D0001/*_sm.h
	$(Q)-rm -f iniFile/D0008/*_m.cpp iniFile/D0008/*_m.h iniFile/D0008/*_sm.cpp iniFile/D0008/*_sm.h
	$(Q)-rm -f iniFile/D001/*_m.cpp iniFile/D001/*_m.h iniFile/D001/*_sm.cpp iniFile/D001/*_sm.h
	$(Q)-rm -f iniFile/D002/*_m.cpp iniFile/D002/*_m.h iniFile/D002/*_sm.cpp iniFile/D002/*_sm.h
	$(Q)-rm -f iniFile/noD/*_m.cpp iniFile/noD/*_m.h iniFile/noD/*_sm.cpp iniFile/noD/*_sm.h
	$(Q)-rm -f net/*_m.cpp net/*_m.h net/*_sm.cpp net/*_sm.h
	$(Q)-rm -f net/randomgeometricgraph/*_m.cpp net/randomgeometricgraph/*_m.h net/randomgeometricgraph/*_sm.cpp net/randomgeometricgraph/*_sm.h
	$(Q)-rm -f results/*_m.cpp results/*_m.h results/*_sm.cpp results/*_sm.h
	$(Q)-rm -f results/D0001/*_m.cpp results/D0001/*_m.h results/D0001/*_sm.cpp results/D0001/*_sm.h
	$(Q)-rm -f results/D0001/r50D0001/*_m.cpp results/D0001/r50D0001/*_m.h results/D0001/r50D0001/*_sm.cpp results/D0001/r50D0001/*_sm.h
	$(Q)-rm -f results/D0001/r50D0001/rgg100/*_m.cpp results/D0001/r50D0001/rgg100/*_m.h results/D0001/r50D0001/rgg100/*_sm.cpp results/D0001/r50D0001/rgg100/*_sm.h
	$(Q)-rm -f results/D0008/*_m.cpp results/D0008/*_m.h results/D0008/*_sm.cpp results/D0008/*_sm.h
	$(Q)-rm -f results/D0008/r10D0008/*_m.cpp results/D0008/r10D0008/*_m.h results/D0008/r10D0008/*_sm.cpp results/D0008/r10D0008/*_sm.h
	$(Q)-rm -f results/D0008/r10D0008/General/*_m.cpp results/D0008/r10D0008/General/*_m.h results/D0008/r10D0008/General/*_sm.cpp results/D0008/r10D0008/General/*_sm.h
	$(Q)-rm -f results/D0008/r10D0008/rgg5/*_m.cpp results/D0008/r10D0008/rgg5/*_m.h results/D0008/r10D0008/rgg5/*_sm.cpp results/D0008/r10D0008/rgg5/*_sm.h
	$(Q)-rm -f results/D0008/r15D0008/*_m.cpp results/D0008/r15D0008/*_m.h results/D0008/r15D0008/*_sm.cpp results/D0008/r15D0008/*_sm.h
	$(Q)-rm -f results/D0008/r15D0008/General/*_m.cpp results/D0008/r15D0008/General/*_m.h results/D0008/r15D0008/General/*_sm.cpp results/D0008/r15D0008/General/*_sm.h
	$(Q)-rm -f results/D0008/r15D0008/rgg5/*_m.cpp results/D0008/r15D0008/rgg5/*_m.h results/D0008/r15D0008/rgg5/*_sm.cpp results/D0008/r15D0008/rgg5/*_sm.h
	$(Q)-rm -f results/D002/*_m.cpp results/D002/*_m.h results/D002/*_sm.cpp results/D002/*_sm.h
	$(Q)-rm -f results/D002/r10D002/*_m.cpp results/D002/r10D002/*_m.h results/D002/r10D002/*_sm.cpp results/D002/r10D002/*_sm.h
	$(Q)-rm -f results/noD/*_m.cpp results/noD/*_m.h results/noD/*_sm.cpp results/noD/*_sm.h
	$(Q)-rm -f results/noD/r10D002/*_m.cpp results/noD/r10D002/*_m.h results/noD/r10D002/*_sm.cpp results/noD/r10D002/*_sm.h
	$(Q)-rm -f results/noD/r10D002/General/*_m.cpp results/noD/r10D002/General/*_m.h results/noD/r10D002/General/*_sm.cpp results/noD/r10D002/General/*_sm.h
	$(Q)-rm -f src/*_m.cpp src/*_m.h src/*_sm.cpp src/*_sm.h
	$(Q)-rm -f src/battery/*_m.cpp src/battery/*_m.h src/battery/*_sm.cpp src/battery/*_sm.h
	$(Q)-rm -f src/bluetooth/*_m.cpp src/bluetooth/*_m.h src/bluetooth/*_sm.cpp src/bluetooth/*_sm.h
	$(Q)-rm -f src/coordinate/*_m.cpp src/coordinate/*_m.h src/coordinate/*_sm.cpp src/coordinate/*_sm.h
	$(Q)-rm -f src/coordinate/bidimensional/*_m.cpp src/coordinate/bidimensional/*_m.h src/coordinate/bidimensional/*_sm.cpp src/coordinate/bidimensional/*_sm.h
	$(Q)-rm -f src/message/*_m.cpp src/message/*_m.h src/message/*_sm.cpp src/message/*_sm.h
	$(Q)-rm -f src/message/bluetooth/*_m.cpp src/message/bluetooth/*_m.h src/message/bluetooth/*_sm.cpp src/message/bluetooth/*_sm.h
	$(Q)-rm -f src/node/*_m.cpp src/node/*_m.h src/node/*_sm.cpp src/node/*_sm.h
	$(Q)-rm -f src/node/models/*_m.cpp src/node/models/*_m.h src/node/models/*_sm.cpp src/node/models/*_sm.h
	$(Q)-rm -f src/node/statistics/*_m.cpp src/node/statistics/*_m.h src/node/statistics/*_sm.cpp src/node/statistics/*_sm.h
	$(Q)-rm -f src/protocol/*_m.cpp src/protocol/*_m.h src/protocol/*_sm.cpp src/protocol/*_sm.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES) $(SM_CC_FILES)  ./*.cpp iniFile/*.cpp iniFile/D00001/*.cpp iniFile/D00005/*.cpp iniFile/D0001/*.cpp iniFile/D0008/*.cpp iniFile/D001/*.cpp iniFile/D002/*.cpp iniFile/noD/*.cpp net/*.cpp net/randomgeometricgraph/*.cpp results/*.cpp results/D0001/*.cpp results/D0001/r50D0001/*.cpp results/D0001/r50D0001/rgg100/*.cpp results/D0008/*.cpp results/D0008/r10D0008/*.cpp results/D0008/r10D0008/General/*.cpp results/D0008/r10D0008/rgg5/*.cpp results/D0008/r15D0008/*.cpp results/D0008/r15D0008/General/*.cpp results/D0008/r15D0008/rgg5/*.cpp results/D002/*.cpp results/D002/r10D002/*.cpp results/noD/*.cpp results/noD/r10D002/*.cpp results/noD/r10D002/General/*.cpp src/*.cpp src/battery/*.cpp src/bluetooth/*.cpp src/coordinate/*.cpp src/coordinate/bidimensional/*.cpp src/message/*.cpp src/message/bluetooth/*.cpp src/node/*.cpp src/node/models/*.cpp src/node/statistics/*.cpp src/protocol/*.cpp

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/src/battery/BatteryManager.o: src/battery/BatteryManager.cpp \
	src/battery/BatteryManager.h
$O/src/bluetooth/BTFsaManager.o: src/bluetooth/BTFsaManager.cpp \
	src/bluetooth/BTFsaManager.h \
	src/bluetooth/BTState.h
$O/src/coordinate/bidimensional/Coordinate2D.o: src/coordinate/bidimensional/Coordinate2D.cpp \
	src/coordinate/bidimensional/Coordinate2D.h
$O/src/message/bluetooth/BTMessageGenerator.o: src/message/bluetooth/BTMessageGenerator.cpp \
	src/message/OPCode.h \
	src/message/UnityMeasureCode.h \
	src/message/bluetooth/BTMessageGenerator.h \
	src/message/bluetooth/btmessage_m.h
$O/src/node/models/RandomGeometricNode.o: src/node/models/RandomGeometricNode.cpp \
	src/battery/BatteryManager.h \
	src/bluetooth/BTFsaManager.h \
	src/bluetooth/BTState.h \
	src/message/OPCode.h \
	src/message/UnityMeasureCode.h \
	src/message/bluetooth/BTMessageGenerator.h \
	src/message/bluetooth/btmessage_m.h \
	src/node/models/RandomGeometricNode.h \
	src/protocol/AdvertiseLimit.h \
	src/protocol/Bound.h \
	src/protocol/DynamicFanout.h \
	src/protocol/ProtocolManager.h
$O/src/node/statistics/StatisticsCollector.o: src/node/statistics/StatisticsCollector.cpp \
	src/node/statistics/StatisticsCollector.h
$O/src/protocol/AdvertiseLimit.o: src/protocol/AdvertiseLimit.cpp \
	src/battery/BatteryManager.h \
	src/protocol/AdvertiseLimit.h \
	src/protocol/Bound.h
$O/src/protocol/Bound.o: src/protocol/Bound.cpp \
	src/battery/BatteryManager.h \
	src/protocol/Bound.h
$O/src/protocol/DynamicFanout.o: src/protocol/DynamicFanout.cpp \
	src/battery/BatteryManager.h \
	src/protocol/Bound.h \
	src/protocol/DynamicFanout.h
$O/src/protocol/ProtocolManager.o: src/protocol/ProtocolManager.cpp \
	src/battery/BatteryManager.h \
	src/protocol/AdvertiseLimit.h \
	src/protocol/Bound.h \
	src/protocol/DynamicFanout.h \
	src/protocol/ProtocolManager.h
