include_directories(${MPI_INCLUDE_PATH})
include_directories(${CMAKE_BINARY_DIR}/artdaq)
    
    
simple_plugin(ROCExtinctionMonitorInterface "interface"
	ROCCore
	FECore
	TableCore
	Macros
	Configurable
	ConfigurationInterface
	WorkLoopManager
	artdaq-core_Utilities
	${XDAQ_XERCES-C}
	${MF_MESSAGELOGGER}
	pthread
 )
