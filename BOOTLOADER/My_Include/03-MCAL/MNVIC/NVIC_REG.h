/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef NVIC_REG_H_
#define NVIC_REG_H_

typedef struct{

	volatile u32 ISER    	[ 32 ];
	volatile u32 ICER    	[ 32 ];
	volatile u32 ISPR    	[ 32 ];
	volatile u32 ICPR    	[ 32 ];
	volatile u32 IAPR    	[ 32 ];
	volatile u32 RESERVED1	[ 32 ];
	volatile u8  IPR      	[ 240 ];
	volatile u32 RESERVED2 	[ 644];
	volatile u32 STIR;

}NVIC;

#define MNVIC      ( ( volatile NVIC *)0xE000E100 )

#define MNVIC_STIR ( ( volatile u32  *)0xE000EF00 )

//SCB
typedef struct{

	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCSR;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 RESERVED;
	volatile u32 MMFAR;
	volatile u32 BFAR;

}SCB__Type;

#define SCB_ ((volatile SCB__Type *) 0xE000ED00 )



#endif /* NVIC_REG_H_ */
