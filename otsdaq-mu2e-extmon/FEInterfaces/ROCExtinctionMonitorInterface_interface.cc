#include "otsdaq-mu2e-extmon/FEInterfaces/ROCExtinctionMonitorInterface.h"

#include "otsdaq-core/Macros/InterfacePluginMacros.h"

using namespace ots;

#undef __MF_SUBJECT__
#define __MF_SUBJECT__ "FE-ROCExtinctionMonitorInterface"

//=========================================================================================
ROCExtinctionMonitorInterface::ROCExtinctionMonitorInterface(
    const std::string&       rocUID,
    const ConfigurationTree& theXDAQContextConfigTree,
    const std::string&       theConfigurationPath)
    : ROCCoreVInterface(rocUID, theXDAQContextConfigTree, theConfigurationPath)
{
	INIT_MF("ROCExtinctionMonitorInterface");

	__MCOUT_INFO__("ROCExtinctionMonitorInterface instantiated with link: "
	               << linkID_ << " and EventWindowDelayOffset = " << delay_ << __E__);
}

//==========================================================================================
ROCExtinctionMonitorInterface::~ROCExtinctionMonitorInterface(void)
{
	// NOTE:: be careful not to call __FE_COUT__ decoration because it uses the
	// tree and it may already be destructed partially
	__COUT__ << FEVInterface::interfaceUID_ << " Destructor" << __E__;
}

//==================================================================================================
void ROCExtinctionMonitorInterface::writeROCRegister(uint16_t address,
                                                     uint16_t data_to_write)
{
	__FE_COUT__ << "Calling write ROC register: link number " << std::dec << linkID_
	            << ", address = " << address << ", write data = " << data_to_write
	            << __E__;

	return;
}

//==================================================================================================
uint16_t ROCExtinctionMonitorInterface::readROCRegister(uint16_t address)
{
	__FE_COUT__ << "Calling read ROC register: link number " << std::dec << linkID_
	            << ", address = " << address << __E__;

	return -1;
}

//============================================================================================
void ROCExtinctionMonitorInterface::writeEmulatorRegister(uint16_t address,
                                                          uint16_t data_to_write)
{
	__FE_COUT__ << "Calling write ROC Emulator register: link number " << std::dec
	            << linkID_ << ", address = " << address
	            << ", write data = " << data_to_write << __E__;

	return;
}

//==================================================================================================
uint16_t ROCExtinctionMonitorInterface::readEmulatorRegister(uint16_t address)
{
	__FE_COUT__ << "Calling read ROC Emulator register: link number " << std::dec
	            << linkID_ << ", address = " << address << __E__;

	return -1;
}

//==================================================================================================
int ROCExtinctionMonitorInterface::readTimestamp() { return this->readRegister(12); }

//==================================================================================================
void ROCExtinctionMonitorInterface::writeDelay(uint16_t delay)
{
	this->writeRegister(21, delay);
	return;
}

//==================================================================================================
int ROCExtinctionMonitorInterface::readDelay() { return this->readRegister(7); }

//==================================================================================================
int ROCExtinctionMonitorInterface::readDTCLinkLossCounter()
{
	return this->readRegister(8);
}

//==================================================================================================
void ROCExtinctionMonitorInterface::resetDTCLinkLossCounter()
{
	this->writeRegister(24, 0x1);
	return;
}

//==================================================================================================
void ROCExtinctionMonitorInterface::configure(void) try
{
	__MCOUT_INFO__(".... do nothing for TEM ROC... ");

	// __MCOUT_INFO__("......... Clear DCS FIFOs" << __E__);
	// this->writeRegister(0,1);
	// this->writeRegister(0,0);

	// setup needToResetAlignment using rising edge of register 22
	// (i.e., force synchronization of ROC clock with 40MHz system clock)
	//__MCOUT_INFO__("......... setup to synchronize ROC clock with 40 MHz clock
	// edge" << __E__);  this->writeRegister(22,0);  this->writeRegister(22,1);

	// this->writeDelay(delay_);
	// usleep(100);

	//__MCOUT_INFO__ ("........." << " Set delay = " << delay_ << ", readback = "
	//<< this->readDelay() << " ... ");

	//__FE_COUT__ << "Debugging ROC-DCS" << __E__;

	// unsigned int val;

	// read 6 should read back 0x12fc
	// for (int i = 0; i<1; i++)
	//{
	//	val = this->readRegister(6);
	//
	//	//__MCOUT_INFO__(i << " read register 6 = " << val << __E__);
	//	if(val != 4860)
	//	{
	//		__FE_SS__ << "Bad read not 4860! val = " << val << __E__;
	//		__FE_SS_THROW__;
	//	}
	//
	//	val = this->readDelay();
	//	//__MCOUT_INFO__(i << " read register 7 = " << val << __E__);
	//	if(val != delay_)
	//	{
	//		__FE_SS__ << "Bad read not " << delay_ << "! val = " << val <<
	//__E__;
	//		__FE_SS_THROW__;
	//	}
	//}

	// if(0) //random intense check
	//{
	//	highRateCheck();
	//}

	//__MCOUT_INFO__ ("......... reset DTC link loss counter ... ");
	// resetDTCLinkLossCounter();
}
catch(const std::runtime_error& e)
{
	__FE_MOUT__ << "Error caught: " << e.what() << __E__;
	throw;
}
catch(...)
{
	__FE_SS__ << "Unknown error caught. Check printouts!" << __E__;
	__FE_MOUT__ << ss.str();
	__FE_SS_THROW__;
}

//========================================================================================================================
void ROCExtinctionMonitorInterface::halt(void) {}

//========================================================================================================================
void ROCExtinctionMonitorInterface::pause(void) {}

//========================================================================================================================
void ROCExtinctionMonitorInterface::resume(void) {}

//========================================================================================================================
void ROCExtinctionMonitorInterface::start(std::string)  // runNumber)
{
}

//========================================================================================================================
void ROCExtinctionMonitorInterface::stop(void) {}

//========================================================================================================================
bool ROCExtinctionMonitorInterface::running(void) { return false; }

DEFINE_OTS_INTERFACE(ROCExtinctionMonitorInterface)
