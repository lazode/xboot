/*
 * arch/arm/mach-smdkc100/mach-smdkc100.c
 *
 * Copyright (c) 2007-2008  jianjun jiang <jerryjianjun@gmail.com>
 * official site: http://xboot.org
 *
 * This program is free software; you can redistribute it and/or modify
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
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <xboot.h>
#include <types.h>
#include <macros.h>
#include <io.h>
#include <mode/mode.h>
#include <xboot/log.h>
#include <xboot/printk.h>
#include <xboot/machine.h>
#include <xboot/initcall.h>
#include <s5pc100-cp15.h>
#include <s5pc100/reg-gpio.h>
#include <s5pc100/reg-wdg.h>


extern u8_t	__text_start[];
extern u8_t __text_end[];
extern u8_t __ramdisk_start[];
extern u8_t __ramdisk_end[];
extern u8_t __data_shadow_start[];
extern u8_t __data_shadow_end[];
extern u8_t __data_start[];
extern u8_t __data_end[];
extern u8_t __bss_start[];
extern u8_t __bss_end[];
extern u8_t __heap_start[];
extern u8_t __heap_end[];
extern u8_t __stack_start[];
extern u8_t __stack_end[];

/*
 * system initial, like power lock
 */
static void mach_init(void)
{

}

/*
 * system halt, shutdown machine.
 */
static bool_t mach_halt(void)
{
	return TRUE;
}

/*
 * reset the cpu by setting up the watchdog timer and let him time out
 */
static bool_t mach_reset(void)
{
	/* disable watchdog */
	writel(S5PC100_WTCON, 0x0000);

	/* initialize watchdog timer count register */
	writel(S5PC100_WTCNT, 0x0001);

	/* enable watchdog timer; assert reset at timer timeout */
	writel(S5PC100_WTCON, 0x0021);

	return TRUE;
}

/*
 * get system mode
 */
static enum mode mach_getmode(void)
{
	return MODE_MENU;
}

/*
 * clean up system before running os.
 */
bool_t mach_cleanup(void)
{
	/* disable irq */
	irq_disable();

	/* disable fiq */
	fiq_disable();

	/* disable icache */
	icache_disable();

	/* disable dcache */
	dcache_disable();

	/* disable mmu */
	mmu_disable();

	/* disable vic */
	vic_disable();

	return TRUE;
}

/*
 * for anti-piracy
 */
static bool_t mach_genuine(void)
{
	return TRUE;
}

/*
 * a portable data interface for machine.
 */
static struct machine smdkc100 = {
	.info = {
		.board_name 		= "smdkc100",
		.board_desc 		= "smdk s5pc100 base board by samsung",
		.board_id			= "0x00000000",

		.cpu_name			= "s5pc100",
		.cpu_desc			= "cortex-a8",
		.cpu_id				= "0x00000000",
	},

	.res = {
		.mem_banks = {
			[0] = {
				.start		= (void *)(0x20000000),
				.end		= (void *)(0x20000000 + SZ_256M - 1),
			},

			[1] = {
				.start		= 0,
				.end		= 0,
			},
		},

		.xtal				= 12*1000*1000,
	},

	.link = {
		.text_start			= (const void *)__text_start,
		.text_end			= (const void *)__text_end,

		.ramdisk_start		= (const void *)__ramdisk_start,
		.ramdisk_end		= (const void *)__ramdisk_end,

		.data_shadow_start	= (const void *)__data_shadow_start,
		.data_shadow_end	= (const void *)__data_shadow_end,

		.data_start			= (const void *)__data_start,
		.data_end			= (const void *)__data_end,

		.bss_start			= (const void *)__bss_start,
		.bss_end			= (const void *)__bss_end,

		.heap_start			= (const void *)__heap_start,
		.heap_end			= (const void *)__heap_end,

		.stack_start		= (const void *)__stack_start,
		.stack_end			= (const void *)__stack_end,
	},

	.pm = {
		.init 				= mach_init,
		.suspend			= NULL,
		.resume				= NULL,
		.halt				= mach_halt,
		.reset				= mach_reset,
	},

	.misc = {
		.getmode			= mach_getmode,
		.cleanup			= mach_cleanup,
		.genuine			= mach_genuine,
	},

	.priv					= NULL,
};

static __init void mach_smdkc100_init(void)
{
	if(!machine_register(&smdkc100))
		LOG_E("failed to register machine 'smdkc100'");
}

module_init(mach_smdkc100_init, LEVEL_MACH);
