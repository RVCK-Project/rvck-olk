// SPDX-License-Identifier: GPL-2.0-only

#include <asm/vendor_extensions.h>
#include <asm/vendor_extensions/leaprise.h>
#include <asm/vendor_extensions/leaprise_hwprobe.h>
#include <asm/vendor_extensions/vendor_hwprobe.h>

#include <linux/cpumask.h>
#include <linux/types.h>

#include <uapi/asm/hwprobe.h>
#include <uapi/asm/vendor/leaprise.h>

void hwprobe_isa_vendor_ext_leaprise_0(struct riscv_hwprobe *pair,
				   const struct cpumask *cpus)
{
	pair->value = 0;
}
