#ifndef _KERNEL_H_
#define _KERNEL_H_

#define CONTROL_REGISTER0_PROTECTED_MODE_ENABLED (1 << 0)
#define CONTROL_REGISTER0_EXTENSION_TYPE (1 << 4)
#define CONTROL_REGISTER0_PAGE (1 << 31)

#define KERNEL_PHYSICAL_START 0x0000000000400000
#define KERNEL_VIRTUAL_START  0xFFFFFFFF80400000

#define KERNEL_GDT_ENTRY 1

#define KERNEL_CR0                                                             \
  (                                                                            \
   CONTROL_REGISTER0_PAGE |                                                    \
   CONTROL_REGISTER0_PROTECTED_MODE_ENABLED |                                  \
   CONTROL_REGISTER0_EXTENSION_TYPE                                            \
  )
#define KERNEL_CR4 (CONTROL_REGISTER4_PHYSICAL_ADDRESS_EXTENSION)

#define CONTROL_REGISTER4_PAGE_SIZE_EXTENSION (1 << 4)
#define CONTROL_REGISTER4_PHYSICAL_ADDRESS_EXTENSION (1 << 5)

#define KERNEL_BOOT_STACK_SIZE 0x4000
#define KERNEL_BOOT_STACK_ALIGNMENT 0x1000

#endif
