#ifndef __S5PV210_REG_CLK_H__
#define __S5PV210_REG_CLK_H__

#include <xboot.h>

#define S5PV210_APLL_LOCK				(0xE0100000 + 0x0000)
#define S5PV210_MPLL_LOCK				(0xE0100000 + 0x0008)
#define S5PV210_EPLL_LOCK				(0xE0100000 + 0x0010)
#define S5PV210_VPLL_LOCK				(0xE0100000 + 0x0020)
#define S5PV210_APLL_CON0				(0xE0100000 + 0x0100)
#define S5PV210_APLL_CON1				(0xE0100000 + 0x0104)
#define S5PV210_MPLL_CON				(0xE0100000 + 0x0108)
#define S5PV210_EPLL_CON0				(0xE0100000 + 0x0110)
#define S5PV210_EPLL_CON1				(0xE0100000 + 0x0114)
#define S5PV210_VPLL_CON				(0xE0100000 + 0x0120)
#define S5PV210_CLK_SRC0				(0xE0100000 + 0x0200)
#define S5PV210_CLK_SRC1				(0xE0100000 + 0x0204)
#define S5PV210_CLK_SRC2				(0xE0100000 + 0x0208)
#define S5PV210_CLK_SRC3				(0xE0100000 + 0x020C)
#define S5PV210_CLK_SRC4				(0xE0100000 + 0x0210)
#define S5PV210_CLK_SRC5				(0xE0100000 + 0x0214)
#define S5PV210_CLK_SRC6				(0xE0100000 + 0x0218)
#define S5PV210_CLK_SRC_MASK0			(0xE0100000 + 0x0280)
#define S5PV210_CLK_SRC_MASK1			(0xE0100000 + 0x0284)
#define S5PV210_CLK_DIV0				(0xE0100000 + 0x0300)
#define S5PV210_CLK_DIV1				(0xE0100000 + 0x0304)
#define S5PV210_CLK_DIV2				(0xE0100000 + 0x0308)
#define S5PV210_CLK_DIV3				(0xE0100000 + 0x030C)
#define S5PV210_CLK_DIV4				(0xE0100000 + 0x0310)
#define S5PV210_CLK_DIV5				(0xE0100000 + 0x0314)
#define S5PV210_CLK_DIV6				(0xE0100000 + 0x0318)
#define S5PV210_CLK_DIV7				(0xE0100000 + 0x031C)
#define S5PV210_CLK_GATE_IP0			(0xE0100000 + 0x0460)
#define S5PV210_CLK_GATE_IP1			(0xE0100000 + 0x0464)
#define S5PV210_CLK_GATE_IP2			(0xE0100000 + 0x0468)
#define S5PV210_CLK_GATE_IP3			(0xE0100000 + 0x046C)
#define S5PV210_CLK_GATE_IP4			(0xE0100000 + 0x0470)
#define S5PV210_CLK_GATE_BLOCK			(0xE0100000 + 0x0480)
#define S5PV210_CLK_GATE_IP5			(0xE0100000 + 0x0484)
#define S5PV210_CLK_OUT					(0xE0100000 + 0x0500)
#define S5PV210_CLK_STAT0				(0xE0100000 + 0x1000)
#define S5PV210_CLK_STAT1				(0xE0100000 + 0x1004)
#define S5PV210_MUX_STAT0				(0xE0100000 + 0x1100)
#define S5PV210_MUX_STAT1				(0xE0100000 + 0x1104)

/*
 * CLKDIV0
 */
#define S5PV210_CLKDIV0_PCLK_PSYS_MASK	(0x7 << 28)
#define S5PV210_CLKDIV0_PCLK_PSYS_SHIFT	(28)
#define S5PV210_CLKDIV0_HCLK_PSYS_MASK	(0x7 << 24)
#define S5PV210_CLKDIV0_HCLK_PSYS_SHIFT	(24)
#define S5PV210_CLKDIV0_PCLK_DSYS_MASK	(0x7 << 20)
#define S5PV210_CLKDIV0_PCLK_DSYS_SHIFT	(20)
#define S5PV210_CLKDIV0_HCLK_DSYS_MASK	(0xf << 16)
#define S5PV210_CLKDIV0_HCLK_DSYS_SHIFT	(16)
#define S5PV210_CLKDIV0_PCLK_MSYS_MASK	(0x7 << 12)
#define S5PV210_CLKDIV0_PCLK_MSYS_SHIFT	(12)
#define S5PV210_CLKDIV0_HCLK_MSYS_MASK	(0x7 << 8)
#define S5PV210_CLKDIV0_HCLK_MSYS_SHIFT	(8)
#define S5PV210_CLKDIV0_A2M_MASK		(0x7 << 4)
#define S5PV210_CLKDIV0_A2M_SHIFT		(4)
#define S5PV210_CLKDIV0_APLL_MASK		(0x7 << 0)
#define S5PV210_CLKDIV0_APLL_SHIFT		(0)

#endif /* __S5PV210_REG_CLK_H__ */
