/*
 * Copyright (c) 2016, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the Intel Corporation nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: Liam Girdwood <liam.r.girdwood@linux.intel.com>
 *         Keyon Jie <yang.jie@linux.intel.com>
 */

/**
 * \file include/uapi/ipc/header.h
 * \brief IPC definitions
 * \author Liam Girdwood <liam.r.girdwood@linux.intel.com>
 * \author Keyon Jie <yang.jie@linux.intel.com>
 */

#ifndef __INCLUDE_UAPI_IPC_HEADER_H__
#define __INCLUDE_UAPI_IPC_HEADER_H__

#include <uapi/abi.h>

/** \addtogroup sof_uapi uAPI
 *  SOF uAPI specification.
 *  @{
 */

/*
 * IPC messages have a prefixed 32 bit identifier made up as follows :-
 *
 * 0xGCCCNNNN where
 * G is global cmd type (4 bits)
 * C is command type (12 bits)
 * I is the ID number (16 bits) - monotonic and overflows
 *
 * This is sent at the start of the IPM message in the mailbox. Messages should
 * not be sent in the doorbell (special exceptions for firmware .
 */

/* Global Message - Generic */
#define SOF_GLB_TYPE_SHIFT			28
#define SOF_GLB_TYPE_MASK			(0xf << SOF_GLB_TYPE_SHIFT)
#define SOF_GLB_TYPE(x)				((x) << SOF_GLB_TYPE_SHIFT)

/* Command Message - Generic */
#define SOF_CMD_TYPE_SHIFT			16
#define SOF_CMD_TYPE_MASK			(0xfff << SOF_CMD_TYPE_SHIFT)
#define SOF_CMD_TYPE(x)				((x) << SOF_CMD_TYPE_SHIFT)

/* Global Message Types */
#define SOF_IPC_GLB_REPLY			SOF_GLB_TYPE(0x1U)
#define SOF_IPC_GLB_COMPOUND			SOF_GLB_TYPE(0x2U)
#define SOF_IPC_GLB_TPLG_MSG			SOF_GLB_TYPE(0x3U)
#define SOF_IPC_GLB_PM_MSG			SOF_GLB_TYPE(0x4U)
#define SOF_IPC_GLB_COMP_MSG			SOF_GLB_TYPE(0x5U)
#define SOF_IPC_GLB_STREAM_MSG			SOF_GLB_TYPE(0x6U)
#define SOF_IPC_FW_READY			SOF_GLB_TYPE(0x7U)
#define SOF_IPC_GLB_DAI_MSG			SOF_GLB_TYPE(0x8U)
#define SOF_IPC_GLB_TRACE_MSG			SOF_GLB_TYPE(0x9U)

/*
 * DSP Command Message Types
 */

/* topology */
#define SOF_IPC_TPLG_COMP_NEW			SOF_CMD_TYPE(0x001)
#define SOF_IPC_TPLG_COMP_FREE			SOF_CMD_TYPE(0x002)
#define SOF_IPC_TPLG_COMP_CONNECT		SOF_CMD_TYPE(0x003)
#define SOF_IPC_TPLG_PIPE_NEW			SOF_CMD_TYPE(0x010)
#define SOF_IPC_TPLG_PIPE_FREE			SOF_CMD_TYPE(0x011)
#define SOF_IPC_TPLG_PIPE_CONNECT		SOF_CMD_TYPE(0x012)
#define SOF_IPC_TPLG_PIPE_COMPLETE		SOF_CMD_TYPE(0x013)
#define SOF_IPC_TPLG_BUFFER_NEW			SOF_CMD_TYPE(0x020)
#define SOF_IPC_TPLG_BUFFER_FREE		SOF_CMD_TYPE(0x021)

/* PM */
#define SOF_IPC_PM_CTX_SAVE			SOF_CMD_TYPE(0x001)
#define SOF_IPC_PM_CTX_RESTORE			SOF_CMD_TYPE(0x002)
#define SOF_IPC_PM_CTX_SIZE			SOF_CMD_TYPE(0x003)
#define SOF_IPC_PM_CLK_SET			SOF_CMD_TYPE(0x004)
#define SOF_IPC_PM_CLK_GET			SOF_CMD_TYPE(0x005)
#define SOF_IPC_PM_CLK_REQ			SOF_CMD_TYPE(0x006)
#define SOF_IPC_PM_CORE_ENABLE			SOF_CMD_TYPE(0x007)

/* component runtime config - multiple different types */
#define SOF_IPC_COMP_SET_VALUE			SOF_CMD_TYPE(0x001)
#define SOF_IPC_COMP_GET_VALUE			SOF_CMD_TYPE(0x002)
#define SOF_IPC_COMP_SET_DATA			SOF_CMD_TYPE(0x003)
#define SOF_IPC_COMP_GET_DATA			SOF_CMD_TYPE(0x004)

/* DAI messages */
#define SOF_IPC_DAI_CONFIG			SOF_CMD_TYPE(0x001)
#define SOF_IPC_DAI_LOOPBACK			SOF_CMD_TYPE(0x002)

/* stream */
#define SOF_IPC_STREAM_PCM_PARAMS		SOF_CMD_TYPE(0x001)
#define SOF_IPC_STREAM_PCM_PARAMS_REPLY		SOF_CMD_TYPE(0x002)
#define SOF_IPC_STREAM_PCM_FREE			SOF_CMD_TYPE(0x003)
#define SOF_IPC_STREAM_TRIG_START		SOF_CMD_TYPE(0x004)
#define SOF_IPC_STREAM_TRIG_STOP		SOF_CMD_TYPE(0x005)
#define SOF_IPC_STREAM_TRIG_PAUSE		SOF_CMD_TYPE(0x006)
#define SOF_IPC_STREAM_TRIG_RELEASE		SOF_CMD_TYPE(0x007)
#define SOF_IPC_STREAM_TRIG_DRAIN		SOF_CMD_TYPE(0x008)
#define SOF_IPC_STREAM_TRIG_XRUN		SOF_CMD_TYPE(0x009)
#define SOF_IPC_STREAM_POSITION			SOF_CMD_TYPE(0x00a)
#define SOF_IPC_STREAM_VORBIS_PARAMS		SOF_CMD_TYPE(0x010)
#define SOF_IPC_STREAM_VORBIS_FREE		SOF_CMD_TYPE(0x011)

/* trace and debug */
#define SOF_IPC_TRACE_DMA_PARAMS		SOF_CMD_TYPE(0x001)
#define SOF_IPC_TRACE_DMA_POSITION		SOF_CMD_TYPE(0x002)

/* Get message component id */
#define SOF_IPC_MESSAGE_ID(x)			((x) & 0xffff)

/* maximum message size for mailbox Tx/Rx */
#define SOF_IPC_MSG_MAX_SIZE			384

/*
 * Structure Header - Header for all IPC structures except command structs.
 * The size can be greater than the structure size and that means there is
 * extended bespoke data beyond the end of the structure including variable
 * arrays.
 */

struct sof_ipc_hdr {
	uint32_t size;			/**< size of structure */
} __attribute__((packed));

/*
 * Command Header - Header for all IPC commands. Identifies IPC message.
 * The size can be greater than the structure size and that means there is
 * extended bespoke data beyond the end of the structure including variable
 * arrays.
 */

struct sof_ipc_cmd_hdr {
	uint32_t size;			/**< size of structure */
	uint32_t cmd;			/**< SOF_IPC_GLB_ + cmd */
} __attribute__((packed));

/*
 * Generic reply message. Some commands override this with their own reply
 * types that must include this at start.
 */
struct sof_ipc_reply {
	struct sof_ipc_cmd_hdr hdr;
	int32_t error;			/**< negative error numbers */
} __attribute__((packed));

/*
 * Compound commands - SOF_IPC_GLB_COMPOUND.
 *
 * Compound commands are sent to the DSP as a single IPC operation. The
 * commands are split into blocks and each block has a header. This header
 * identifies the command type and the number of commands before the next
 * header.
 */

struct sof_ipc_compound_hdr {
	struct sof_ipc_cmd_hdr hdr;
	uint32_t count;		/**< count of 0 means end of compound sequence */
} __attribute__((packed));

/** @}*/

#endif
