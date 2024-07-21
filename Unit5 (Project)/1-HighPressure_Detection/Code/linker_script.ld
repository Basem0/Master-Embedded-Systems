/*Linker_script Cortex_m4
Eng:Ahmed Basem
*/
MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128k
	sram(RWX) : ORIGIN = 0X20000000, LENGTH = 30k
}
SECTIONS
{
	.text : {
		  	*(.vectors*)
		 	*(.text*)
		 	*(.rodata)
			_E_text = . ;
	}> flash

	.data : {
			_S_DATA = . ;
			*(.data)
			. = ALIGN(4);
			_E_DATA = . ;

	}> sram AT> flash
	
	.debug :{
			*(.debug*)
	}
	.bss : {
			_S_bss = . ;
			*(.bss*)
			_E_bss = . ;
	}> sram
}