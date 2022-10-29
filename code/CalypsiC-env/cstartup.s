;;; Startup variant, change attribute value if you make your own
	.rtmodel cstartup,"SBCv1"
	
	.rtmodel version, "1"
	.rtmodel core, "*"
	
	.section stack
	.section cstack
	.section heap
	.section data_init_table
	
	.extern main, exit
	.extern _Dp, _Vfp
	.extern _DirectPageStart
	
#ifndef __CALYPSI_DATA_MODEL_SMALL__
	.extern _NearBaseAddress
#endif

#include "macros.h"


;;; ***************************************************************************
;;;
;;; __program_start - actual start point of the program
;;;
;;; Set up CPU stack, initialize sections and call main().
;;; You can override this with your own routine, or tailor it as needed.
;;; The easiest way to make custom initialization is to provide your own
;;; __low_level_init which gets called after stacks have been initialized.
;;;
;;; ***************************************************************************

	.section farcode, noreorder
	.pubweak __program_root_section
__program_root_section:
	.pubweak __program_start
__program_start:
	REP #0x38					; 16-bit registers, no decimal mode
	;LDX ##.sectionEnd stack
	;TXS							; set stack
	LDA ##_DirectPageStart
	TCD							; set direct page
#ifdef __CALYPSI_DATA_MODEL_SMALL__
	LDA ##0
#else
	LDA ##.word2 _NearBaseAddress
#endif
	STZ dp:.tiny(_Vfp+2)
	XBA							; A upper half = data bank
	PHA
	PLB							; pop 8 dummy
	PLB							; set data bank
	call __low_level_init

;;; **** Initialize data sections if needed.
	.section farcode, noroot, noreorder
	.pubweak __data_initialization_needed
	.extern __initialize_sections
__data_initialization_needed:
	LDA ##.word2 (.sectionEnd data_init_table)
	STA dp:.tiny(_Dp+6)
	LDA ##.word0 (.sectionEnd data_init_table)
	STA dp:.tiny(_Dp+4)
	LDA ##.word2 (.sectionStart data_init_table)
	STA dp:.tiny(_Dp+2)
	LDA ##.word0 (.sectionStart data_init_table)
	STA dp:.tiny(_Dp+0)
	call __initialize_sections

;;; **** Initialize streams if needed.
	.section farcode, noroot, noreorder
	.pubweak __call_initialize_global_streams
	.extern __initialize_global_streams
__call_initialize_global_streams:
	call __initialize_global_streams

;;; **** Initialize heap if needed.
	.section farcode, noroot, noreorder
	.pubweak __call_heap_initialize
	.extern __heap_initialize, __default_heap
__call_heap_initialize:
#ifdef __CALYPSI_DATA_MODEL_SMALL__
	LDA ##.sectionSize heap
	STA dp:.tiny(_Dp+2)
	LDA ##.sectionStart heap
	STA dp:.tiny(_Dp+0)
	LDA ##__default_heap
#else
	LDA ##.word2 (.sectionStart heap)
	STA dp:.tiny(_Dp+6)
	LDA ##.word0 (.sectionStart heap)
	STA dp:.tiny(_Dp+4)
	LDA ##.word2 __default_heap
	STA dp:.tiny(_Dp+2)
	LDA ##.word0 __default_heap
	STA dp:.tiny(_Dp+0)
	LDX ##.word2 (.sectionSize heap)
	LDA ##.word0 (.sectionSize heap)
#endif
	call __heap_initialize

	.section farcode, root, noreorder
	LDA ##0
	call main
	;call exit
	return


;;; ***************************************************************************
;;;
;;; __low_level_init - custom low level initialization
;;;
;;; This default routine just returns doing nothing. You can provide your own
;;; routine, either in C or assembly for doing custom low leve initialization.
;;;
;;; ***************************************************************************

	.section libcode
	.pubweak __low_level_init
__low_level_init:
	return

