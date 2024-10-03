.text :
{
  . = ALIGN(4);
  *(.text)            /* .text sections (code) */
  *(.text*)           /* .text* sections (code) */
  *(.glue_7)          /* glue arm to thumb code */
  *(.glue_7t)         /* glue thumb to arm code */
  *(.eh_frame)

  KEEP (*(.init))
  KEEP (*(.fini))

  . = ALIGN(4);
  _etext = .;         /* define a global symbol at the end of code */
} >FLASH(RX) /* Specify Read-Execute permissions for .text section */

.rodata :
{
  . = ALIGN(4);
  *(.rodata)          /* .rodata sections (constants, strings, etc.) */
  *(.rodata*)         /* .rodata* sections (constants, strings, etc.) */
  . = ALIGN(4);
} >FLASH

.data :
{
  . = ALIGN(4);
  _sdata = .;         /* create a global symbol at data start */
  *(.data)            /* .data sections */
  *(.data*)           /* .data* sections */
  . = ALIGN(4);
  _edata = .;         /* define a global symbol at data end */
} >RAM(AT> FLASH) /* Specify Read-Write permissions for .data section, loaded from FLASH to RAM */

.bss :
{
  . = ALIGN(4);
  _sbss = .;          /* define a global symbol at bss start */
  __bss_start__ = _sbss;
  *(.bss)
  *(.bss*)
  *(COMMON)
  . = ALIGN(4);
  _ebss = .;          /* define a global symbol at bss end */
  __bss_end__ = _ebss;
} >RAM /* Specify Read-Write permissions for .bss section in RAM */
