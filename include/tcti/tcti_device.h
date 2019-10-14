//**********************************************************************;
// Copyright (c) 2015, Intel Corporation
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//**********************************************************************;

#ifndef TCTI_DEVICE_H
#define TCTI_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <tcti/magic.h>

TSS2_RC InitDeviceTcti (
    TSS2_TCTI_CONTEXT *tctiContext, // OUT
    size_t *contextSize,            // IN/OUT
    const char *config,              // IN
    const uint64_t magic,
    const uint32_t version,
	const char *interfaceName,
    const uint8_t serverSockets  // Unused for local TPM.
    );

TSS2_RC TeardownDeviceTcti (
    TSS2_TCTI_CONTEXT *tctiContext, // OUT
    const char *config,              // IN        
	const char *interfaceName
    );

#define DEVICE_TCTI_CONFIG_SIZE 250

extern char deviceTctiConfig[DEVICE_TCTI_CONFIG_SIZE];

extern TSS2_RC InitDeviceTctiContext( const char *driverConfig, TSS2_TCTI_CONTEXT **tctiContext );

extern TSS2_RC TeardownDeviceTctiContext( const char *driverConfig, TSS2_TCTI_CONTEXT *tctiContext );

#ifdef __cplusplus
}
#endif

#endif /* TCTI_DEVICE_H */
