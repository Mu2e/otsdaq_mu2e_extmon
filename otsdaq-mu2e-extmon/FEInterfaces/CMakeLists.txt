
include(otsdaq::FEInterface)

cet_build_plugin(ROCExtinctionMonitorInterface otsdaq::FEInterface LIBRARIES REG otsdaq_mu2e::ROCCore
 )
 

install_headers()
install_source()