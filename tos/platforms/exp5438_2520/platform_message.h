/*
 * Copyright (c) 2016 Eric B. Decker
 * Copyright (c) 2013 Eric B. Decker
 * Copyright (c) 2009 Stanford University.
 * Copyright (c) 2005 The Regents of the University  of California.
 * Copyright (c) 2002-2005 Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither the name of the copyright holders nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * Defining the platform-independently named packet structures to be the
 * chip-specific CC2520 packet structures.
 *
 * @author Philip Levis
 * @author Wanja Hofer <wanja@cs.fau.de>
 * @author Eric B. Decker <cire831@gmail.com>
 */

#ifndef PLATFORM_MESSAGE_H
#define PLATFORM_MESSAGE_H

#include <Serial.h>
#include "CC2520Radio.h"

typedef union message_header {
  cc2520packet_header_t cc2520;
  serial_header_t serial;
} message_header_t;

typedef union message_footer {
  cc2520packet_footer_t cc2520;
} message_footer_t;

typedef struct message_metadata {
  union {
    cc2520_metadata_t cc2520_meta;
    serial_metadata_t serial_meta;
  };

#ifdef LOW_POWER_LISTENING
  lpl_metadata_t lpl_meta;
#endif

  timestamp_metadata_t ts_meta;

#ifdef PACKET_LINK
  link_metadata_t link_meta;
#endif

  flags_metadata_t flags_meta;

} message_metadata_t;

#endif
