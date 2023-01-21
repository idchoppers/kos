CC=x86_64-elf-gcc
SHARED_FLAGS = -fno-builtin -O2 -nostdinc -nostdlib -ffreestanding -g -Wall -Wextra \
               -Werror -I. -I/home/ks/src/gnu-efi/inc -MMD -mno-red-zone -mcmodel=kernel -fno-pie
CFLAGS = $(SHARED_FLAGS)
ASFLAGS = $(SHARED_FLAGS) -Wa,--divide

OBJS := boot.o
OBJS += kernel.o

DFILES = $(patsubst %.o,%.d,$(OBJS))

all: kernel

kernel: $(OBJS) kernel.ld Makefile
	$(CC) -z max-page-size=0x1000 $(CFLAGS) -fno-pie -Wl,--build-id=none -T kernel.ld -o $@ $(OBJS)

clean:
	find -name "*~" -delete
	rm -rf $(OBJS) $(DFILES) kernel

$(OBJS): Makefile
-include $(DFILES)
