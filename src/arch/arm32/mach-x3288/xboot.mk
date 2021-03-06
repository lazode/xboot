#
# Machine makefile
#

DEFINES		+= -D__ARM_ARCH__=7 -D__CORTEX_A17__ -D__ARM32_NEON__

ASFLAGS		:= -g -ggdb -Wall -O3
CFLAGS		:= -g -ggdb -Wall -O3
CXXFLAGS	:= -g -ggdb -Wall -O3
LDFLAGS		:= -T arch/$(ARCH)/$(MACH)/xboot.ld -nostdlib
MCFLAGS		:= -march=armv7-a -mtune=cortex-a17 -mfpu=vfpv3-d16 -mfloat-abi=hard -marm -mno-thumb-interwork

LIBDIRS		:=
LIBS 		:=
INCDIRS		:=
SRCDIRS		:=

ifeq ($(strip $(HOSTOS)), linux)
MK3288		:= arch/$(ARCH)/$(MACH)/tools/linux/mk3288
endif
ifeq ($(strip $(HOSTOS)), windows)
MK3288		:= arch/$(ARCH)/$(MACH)/tools/windows/mk3288
endif
LOADER		:= arch/$(ARCH)/$(MACH)/tools/images/loader

xend:
	@echo Make header information for irom booting
	@$(MK3288) $(X_NAME)pak.bin $(LOADER) $(X_NAME).bin
