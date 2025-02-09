#pragma once
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

#include "CECCommandHandler.h"

namespace CEC
{
  class CSLCommandHandler : public CCECCommandHandler
  {
  public:
    CSLCommandHandler(CCECBusDevice *busDevice);
    virtual ~CSLCommandHandler(void) {};
    virtual cec_vendor_id GetVendorId(void) { return CEC_VENDOR_LG; };

    virtual void HandlePoll(const cec_logical_address iInitiator, const cec_logical_address iDestination);
    virtual bool HandleReceiveFailed(void);
    virtual bool InitHandler(void);

  protected:
    virtual bool HandleActiveSource(const cec_command &command);
    virtual bool HandleFeatureAbort(const cec_command &command);
    virtual bool HandleGivePhysicalAddress(const cec_command &command);
    virtual bool HandleVendorCommand(const cec_command &command);

    virtual void HandleVendorCommand01(const cec_command &command);
    virtual void TransmitVendorCommand0205(const cec_logical_address iSource, const cec_logical_address iDestination);

    virtual void HandleVendorCommandPowerOn(const cec_command &command);
    virtual void HandleVendorCommandPowerOnStatus(const cec_command &command);

    virtual void HandleVendorCommandSLConnect(const cec_command &command);
    virtual void TransmitVendorCommand05(const cec_logical_address iSource, const cec_logical_address iDestination);

    virtual void SetLGDeckStatus(void);

    bool    m_bAwaitingReceiveFailed;
    bool    m_bSLEnabled;
    bool    m_bPowerStateReset;
  };
};
