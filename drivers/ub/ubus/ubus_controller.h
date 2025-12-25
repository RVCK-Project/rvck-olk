/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) HiSilicon Technologies Co., Ltd. 2025. All rights reserved.
 */

#ifndef __UBUS_CONTROLLER_H__
#define __UBUS_CONTROLLER_H__

#include <ub/ubus/ubus.h>
#include "decoder.h"

struct ub_bus_controller;
struct ub_bus_controller_ops {
	int (*eu_table_init)(struct ub_bus_controller *ubc);
	void (*eu_table_uninit)(struct ub_bus_controller *ubc);
	int (*eu_cfg)(struct ub_bus_controller *ubc, bool flag, u32 eid, u16 upi);
	int (*mem_decoder_create)(struct ub_bus_controller *ubc);
	void (*mem_decoder_remove)(struct ub_bus_controller *ubc);
	void (*register_ubmem_irq)(struct ub_bus_controller *ubc);
	void (*unregister_ubmem_irq)(struct ub_bus_controller *ubc);
	int (*init_decoder_queue)(struct ub_decoder *decoder);
	void (*uninit_decoder_queue)(struct ub_decoder *decoder);
	int (*entity_enable)(struct ub_entity *uent, u8 enable);
	int (*create_decoder_table)(struct ub_decoder *decoder);
	void (*free_decoder_table)(struct ub_decoder *decoder);
	int (*decoder_map)(struct ub_decoder *decoder,
			   struct decoder_map_info *info);
	int (*decoder_unmap)(struct ub_decoder *decoder, phys_addr_t addr,
			     u64 size);
	void (*decoder_event_deal)(struct ub_decoder *decoder);

	KABI_RESERVE(1)
	KABI_RESERVE(2)
	KABI_RESERVE(3)
	KABI_RESERVE(4)
	KABI_RESERVE(5)
	KABI_RESERVE(6)
	KABI_RESERVE(7)
	KABI_RESERVE(8)
};

struct ub_bus_controller *ub_find_bus_controller_by_cna(u32 cna);
void ub_bus_controllers_remove(void);
int ub_bus_controllers_probe(void);
int ub_ubc_to_node(struct ub_bus_controller *ubc);

#endif /* __UBUS_CONTROLLER_H__  */
