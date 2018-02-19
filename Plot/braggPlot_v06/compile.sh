#!/bin/sh

cd `dirname $0`
export ANALYSIS_PATH="`/bin/pwd`"
export CORSOCXX_UTIL=${ANALYSIS_PATH}

clear
#####################################################################

export LIB_NAME=AnalysisFramework
cd ${ANALYSIS_PATH}/${LIB_NAME}
rm -f ${ANALYSIS_PATH}/lib${LIB_NAME}.so
echo "compile " ${LIB_NAME}
c++ -Wall -fPIC -shared -I. -I ${CORSOCXX_UTIL} -I ${ANALYSIS_PATH} \
-o ${ANALYSIS_PATH}/lib${LIB_NAME}.so *.cc

export LIB_NAME=AnalysisUtilities
cd ${ANALYSIS_PATH}/${LIB_NAME}
rm -f ${ANALYSIS_PATH}/lib${LIB_NAME}.so
echo "compile " ${LIB_NAME}
c++ -Wall -fPIC -shared -I. -I ${CORSOCXX_UTIL} -I ${ANALYSIS_PATH} \
-o ${ANALYSIS_PATH}/lib${LIB_NAME}.so *.cc

export LIB_NAME=AnalysisObjects
cd ${ANALYSIS_PATH}/${LIB_NAME}
rm -f ${ANALYSIS_PATH}/lib${LIB_NAME}.so
echo "compile " ${LIB_NAME}
c++ -Wall -fPIC -shared -I. -I ${CORSOCXX_UTIL} -I ${ANALYSIS_PATH} \
-o ${ANALYSIS_PATH}/lib${LIB_NAME}.so *.cc -L${ANALYSIS_PATH} -lAnalysisFramework -lAnalysisUtilities 

#####################################################################

cd ${ANALYSIS_PATH}/AnalysisPlugins

export LIB_NAME=EventDump
rm -f ${ANALYSIS_PATH}/lib${LIB_NAME}.so
echo "compile " ${LIB_NAME}
c++ -Wall -fPIC -shared -I. -I ${CORSOCXX_UTIL} -I ${ANALYSIS_PATH} \
-o ${ANALYSIS_PATH}/lib${LIB_NAME}.so ${LIB_NAME}.cc \
-L${ANALYSIS_PATH} -lAnalysisFramework -lAnalysisUtilities -lAnalysisObjects

export LIB_NAME=EnergyDist
rm -f ${ANALYSIS_PATH}/lib${LIB_NAME}.so
echo "compile " ${LIB_NAME}
c++ -Wall -fPIC -shared -I. -I ${CORSOCXX_UTIL} -I ${ANALYSIS_PATH} \
`root-config --cflags --libs`                                              \
-o ${ANALYSIS_PATH}/lib${LIB_NAME}.so ${LIB_NAME}.cc \
-L${ANALYSIS_PATH} -lAnalysisFramework -lAnalysisUtilities -lAnalysisObjects

export LIB_NAME=BGCalc
rm -f ${ANALYSIS_PATH}/lib${LIB_NAME}.so
echo "compile " ${LIB_NAME}
c++ -Wall -fPIC -shared -I. -I ${CORSOCXX_UTIL} -I ${ANALYSIS_PATH} \
`root-config --cflags`                                              \
-o ${ANALYSIS_PATH}/lib${LIB_NAME}.so ${LIB_NAME}.cc \
-L${ANALYSIS_PATH} -lAnalysisFramework -lAnalysisUtilities -lAnalysisObjects

#####################################################################

#####################################################################

cd ${ANALYSIS_PATH}

export EXE_NAME=runDump
rm -f ${EXE_NAME}
echo "compile " ${EXE_NAME}
c++ -Wall -fPIC -I. -I ${ANALYSIS_PATH} -I ${CORSOCXX_UTIL}         \
-o ${EXE_NAME} dum.cc -L ${ANALYSIS_PATH}         \
-lAnalysisFramework -lAnalysisObjects -lAnalysisUtilities           \
-lEventDump

export EXE_NAME=runStat
rm -f ${EXE_NAME}
echo "compile " ${EXE_NAME}
c++ -Wall -fPIC -I. -I ${ANALYSIS_PATH} -I ${CORSOCXX_UTIL}         \
-o ${EXE_NAME} dum.cc -L ${ANALYSIS_PATH}        \
-lAnalysisFramework -lAnalysisObjects -lAnalysisUtilities           \
-lEnergyDist

export EXE_NAME=runAll
rm -f ${EXE_NAME}
echo "compile " ${EXE_NAME}
c++ -Wall -fPIC -I. -I ${ANALYSIS_PATH} -I ${CORSOCXX_UTIL}         \
-o ${EXE_NAME} dum.cc -L ${ANALYSIS_PATH}         \
-lAnalysisFramework -lAnalysisObjects -lAnalysisUtilities           \
-lEventDump -lEnergyDist -lBGCalc 		                            \
`root-config --libs`

