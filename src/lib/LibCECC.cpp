/*
 * This file is part of the libCEC(R) library.
 *
 * libCEC(R) is Copyright (C) 2011 Pulse-Eight Limited.  All rights reserved.
 * libCEC(R) is an original work, containing original code.
 *
 * libCEC(R) is a trademark of Pulse-Eight Limited.
 *
 * This program is dual-licensed; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *
 * Alternatively, you can license this library under a commercial license,
 * please contact Pulse-Eight Licensing for more information.
 *
 * For more information contact:
 * Pulse-Eight Licensing       <license@pulse-eight.com>
 *     http://www.pulse-eight.com/
 *     http://www.pulse-eight.net/
 */

#include <cec.h>
#include <cecc.h>

using namespace CEC;
using namespace std;

/*!
 * C interface implementation
 */
//@{
ICECAdapter *cec_parser;

int cec_init(const char *strDeviceName, cec_logical_address iLogicalAddress, uint16_t iPhysicalAddress)
{
  cec_parser = (ICECAdapter *) CECCreate(strDeviceName, iLogicalAddress, iPhysicalAddress);
  return (cec_parser != NULL) ? 1 : 0;
}

int cec_init_typed(const char *strDeviceName, cec_device_type_list devicesTypes)
{
  cec_parser = (ICECAdapter *) CECInit(strDeviceName, devicesTypes);
  return (cec_parser != NULL) ? 1 : 0;
}

void cec_destroy(void)
{
  cec_close();
  CECDestroy(cec_parser);
  cec_parser = NULL;
}

int cec_open(const char *strPort, uint32_t iTimeout)
{
  if (cec_parser)
    return cec_parser->Open(strPort, iTimeout);
  return false;
}

void cec_close(void)
{
  if (cec_parser)
    cec_parser->Close();
}

int8_t cec_find_adapters(cec_adapter *deviceList, uint8_t iBufSize, const char *strDevicePath /* = NULL */)
{
  if (cec_parser)
    return cec_parser->FindAdapters(deviceList, iBufSize, strDevicePath);
  return -1;
}

int cec_ping_adapters(void)
{
  if (cec_parser)
    return cec_parser->PingAdapter() ? 1 : 0;
  return -1;
}

int cec_start_bootloader(void)
{
  if (cec_parser)
    return cec_parser->StartBootloader() ? 1 : 0;
  return -1;
}

int8_t cec_get_min_version(void)
{
  if (cec_parser)
    return cec_parser->GetMinLibVersion();
  return -1;
}

int8_t cec_get_lib_version_major(void)
{
  if (cec_parser)
    return cec_parser->GetLibVersionMajor();
  return -1;
}

int8_t cec_get_lib_version_minor(void)
{
  if (cec_parser)
    return cec_parser->GetLibVersionMinor();
  return -1;
}

int cec_get_next_log_message(cec_log_message *message)
{
  if (cec_parser)
    return cec_parser->GetNextLogMessage(message) ? 1 : 0;
  return -1;
}

int cec_get_next_keypress(cec_keypress *key)
{
  if (cec_parser)
    return cec_parser->GetNextKeypress(key) ? 1 : 0;
  return -1;
}

int cec_get_next_command(cec_command *command)
{
  if (cec_parser)
    return cec_parser->GetNextCommand(command) ? 1 : 0;
  return -1;
}

int cec_transmit(const CEC::cec_command *data)
{
  if (cec_parser)
    return cec_parser->Transmit(*data) ? 1 : 0;
  return -1;
}

int cec_set_logical_address(cec_logical_address iLogicalAddress /* = CECDEVICE_PLAYBACKDEVICE1 */)
{
  if (cec_parser)
    return cec_parser->SetLogicalAddress(iLogicalAddress) ? 1 : 0;
  return -1;
}

int cec_set_physical_address(uint16_t iPhysicalAddress /* = CEC_DEFAULT_PHYSICAL_ADDRESS */)
{
  if (cec_parser)
    return cec_parser->SetPhysicalAddress(iPhysicalAddress) ? 1 : 0;
  return -1;
}

int cec_power_on_devices(cec_logical_address address /* = CECDEVICE_TV */)
{
  if (cec_parser)
    return cec_parser->PowerOnDevices(address) ? 1 : 0;
  return -1;
}

int cec_standby_devices(cec_logical_address address /* = CECDEVICE_BROADCAST */)
{
  if (cec_parser)
    return cec_parser->StandbyDevices(address) ? 1 : 0;
  return -1;
}

int cec_set_active_view(void)
{
  if (cec_parser)
    return cec_parser->SetActiveView() ? 1 : 0;
  return -1;
}

int cec_set_active_source(cec_device_type type)
{
  if (cec_parser)
    return cec_parser->SetActiveSource(type) ? 1 : 0;
  return -1;
}

int cec_set_deck_control_mode(cec_deck_control_mode mode, int bSendUpdate) {
  if (cec_parser)
    return cec_parser->SetDeckControlMode(mode, bSendUpdate == 1) ? 1 : 0;
  return -1;
}

int cec_set_deck_info(cec_deck_info info, int bSendUpdate) {
  if (cec_parser)
    return cec_parser->SetDeckInfo(info, bSendUpdate == 1) ? 1 : 0;
  return -1;

}

int cec_set_inactive_view(void)
{
  if (cec_parser)
    return cec_parser->SetInactiveView() ? 1 : 0;
  return -1;
}

int cec_set_menu_state(cec_menu_state state, int bSendUpdate) {
  if (cec_parser)
    return cec_parser->SetMenuState(state, bSendUpdate == 1) ? 1 : 0;
  return -1;
}

int cec_set_osd_string(cec_logical_address iLogicalAddress, cec_display_control duration, const char *strMessage)
{
  if (cec_parser)
    return cec_parser->SetOSDString(iLogicalAddress, duration, strMessage) ? 1 : 0;
  return -1;
}

int cec_switch_monitoring(int bEnable)
{
  if (cec_parser)
    return cec_parser->SwitchMonitoring(bEnable == 1) ? 1 : 0;
  return -1;
}

cec_version cec_get_device_cec_version(cec_logical_address iLogicalAddress)
{
  if (cec_parser)
    return cec_parser->GetDeviceCecVersion(iLogicalAddress);
  return CEC_VERSION_UNKNOWN;
}

int cec_get_device_menu_language(cec_logical_address iLogicalAddress, cec_menu_language *language)
{
  if (cec_parser)
    return cec_parser->GetDeviceMenuLanguage(iLogicalAddress, language) ? 1 : 0;
  return -1;
}

uint64_t cec_get_device_vendor_id(cec_logical_address iLogicalAddress)
{
  if (cec_parser)
    return cec_parser->GetDeviceVendorId(iLogicalAddress);
  return 0;
}

uint16_t cec_get_device_physical_address(cec_logical_address iLogicalAddress)
{
  if (cec_parser)
    return cec_parser->GetDevicePhysicalAddress(iLogicalAddress);
  return 0;
}

cec_logical_address cec_get_active_source(void)
{
  if (cec_parser)
    return cec_parser->GetActiveSource();
  return CECDEVICE_UNKNOWN;
}

int cec_is_active_source(cec_logical_address iAddress)
{
  if (cec_parser)
    return cec_parser->IsActiveSource(iAddress);
  return false;
}

cec_power_status cec_get_device_power_status(cec_logical_address iLogicalAddress)
{
  if (cec_parser)
    return cec_parser->GetDevicePowerStatus(iLogicalAddress);
  return CEC_POWER_STATUS_UNKNOWN;
}

int cec_poll_device(cec_logical_address iLogicalAddress)
{
  if (cec_parser)
    return cec_parser->PollDevice(iLogicalAddress) ? 1 : 0;
  return -1;
}

cec_logical_addresses cec_get_active_devices(void)
{
  cec_logical_addresses addresses;
  addresses.Clear();
  if (cec_parser)
    addresses = cec_parser->GetActiveDevices();
  return addresses;
}

int cec_is_active_device(cec_logical_address iAddress)
{
  if (cec_parser)
    return cec_parser->IsActiveDevice(iAddress) ? 1 : 0;
  return -1;
}

int cec_is_active_device_type(cec_device_type type)
{
  if (cec_parser)
    return cec_parser->IsActiveDeviceType(type) ? 1 : 0;
  return -1;
}

int cec_set_hdmi_port(cec_logical_address iBaseDevice, uint8_t iPort)
{
  if (cec_parser)
    return cec_parser->SetHDMIPort(iBaseDevice, iPort) ? 1 : 0;
  return -1;
}

int cec_volume_up(int bSendRelease)
{
  if (cec_parser)
    return cec_parser->VolumeUp(bSendRelease == 1);
  return -1;
}

int cec_volume_down(int bSendRelease)
{
  if (cec_parser)
    return cec_parser->VolumeDown(bSendRelease == 1);
  return -1;
}

int cec_mute_audio(int bSendRelease)
{
  if (cec_parser)
    return cec_parser->MuteAudio(bSendRelease == 1);
  return -1;
}

int cec_send_keypress(cec_logical_address iDestination, cec_user_control_code key, int bWait)
{
  if (cec_parser)
    return cec_parser->SendKeypress(iDestination, key, bWait == 1) ? 1 : 0;
  return -1;
}

int cec_send_key_release(cec_logical_address iDestination, int bWait)
{
  if (cec_parser)
    return cec_parser->SendKeyRelease(iDestination, bWait == 1) ? 1 : 0;
  return -1;
}

cec_osd_name cec_get_device_osd_name(cec_logical_address iAddress)
{
  cec_osd_name retVal;
  retVal.device = iAddress;
  retVal.name[0] = 0;

  if (cec_parser)
    retVal = cec_parser->GetDeviceOSDName(iAddress);

  return retVal;
}

int cec_enable_physical_address_detection(void)
{
  return cec_parser ? (cec_parser->EnablePhysicalAddressDetection() ? 1 : 0) : -1;
}

//@}
