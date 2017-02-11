#include <xboot.h>
#include "lwip/debug.h"
#include "lwip/def.h"
#include "lwip/sys.h"
#include "lwip/opt.h"
#include "lwip/stats.h"

u32_t sys_now(void)
{
	return (u32_t)time(0);
}

u32_t sys_jiffies(void)
{
	return (u32_t)time(0);
}

void sys_init(void)
{
}
