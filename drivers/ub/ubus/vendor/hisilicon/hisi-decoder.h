/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) HiSilicon Technologies Co., Ltd. 2025. All rights reserved.
 */

#ifndef __HISI_DECODER_H__
#define __HISI_DECODER_H__

#include <linux/types.h>
#include <ub/ubus/ubus.h>
#include "../../decoder.h"

#define DECODER_PGTBL_PGPRT_MASK GENMASK_ULL(47, 12)
#define DECODER_DMA_PAGE_ADDR_OFFSET 12

#define PGTLB_CACHE_IR_NC	0b00
#define PGTLB_CACHE_IR_WBRA	0b01
#define PGTLB_CACHE_IR_WT	0b10
#define PGTLB_CACHE_IR_WB	0b11
#define PGTLB_CACHE_OR_NC	0b0000
#define PGTLB_CACHE_OR_WBRA	0b0100
#define PGTLB_CACHE_OR_WT	0b1000
#define PGTLB_CACHE_OR_WB	0b1100
#define PGTLB_CACHE_SH_NSH	0b000000
#define PGTLB_CACHE_SH_OSH	0b100000
#define PGTLB_CACHE_SH_ISH	0b110000

#define PGTLB_ATTR_DEFAULT	(PGTLB_CACHE_IR_WBRA |	\
				 PGTLB_CACHE_OR_WBRA |	\
				 PGTLB_CACHE_SH_ISH)

#define RGTLB_TO_PGTLB 8
#define DECODER_PAGE_ENTRY_SIZE 64
#define DECODER_PAGE_SIZE (1 << 12)
#define DECODER_PAGE_TABLE_SIZE (1 << 12)
#define PAGE_TABLE_PAGE_SIZE (DECODER_PAGE_ENTRY_SIZE * DECODER_PAGE_SIZE)
#define RANGE_TABLE_PAGE_SIZE (DECODER_PAGE_ENTRY_SIZE * \
			       DECODER_PAGE_SIZE * \
			       RGTLB_TO_PGTLB)

int hi_init_decoder_queue(struct ub_decoder *decoder);
void hi_uninit_decoder_queue(struct ub_decoder *decoder);

int hi_create_decoder_table(struct ub_decoder *decoder);
void hi_free_decoder_table(struct ub_decoder *decoder);

int hi_decoder_map(struct ub_decoder *decoder, struct decoder_map_info *info);
int hi_decoder_unmap(struct ub_decoder *decoder, phys_addr_t addr, u64 size);

int hi_decoder_cmd_request(struct ub_decoder *decoder, phys_addr_t addr,
			   u64 size, enum ub_cmd_op_type op);
void hi_decoder_event_deal(struct ub_decoder *decoder);

#endif /* __HISI_DECODER_H__ */
