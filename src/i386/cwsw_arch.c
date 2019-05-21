/** @file
 *	@brief	Initialize the MCU.
 *
 *	Description:
 *
 *	Copyright (c) 2019 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Jan 3, 2018
 *	Author: kbecker
 *
 *	Current:
 *	$Revision: $
 *	$Date: $
 */

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

#include "projcfg.h"
#if !(  (XPRJ_Win_MinGW_Debug)	||	\
        (XPRJ_Debug_Linux_GCC)	||	\
        (XPRJ_NB_Debug)			||	\
		(XPRJ_Win_MSVC_Debug)	||	\
        (XPRJ_CVI_Debug) )			/* { */
#error Unknown CPU Architecture
#endif															/* } */

// ----	System Headers --------------------------
#include <stddef.h>		/* NULL */
#include <stdbool.h>

// ----	Project Headers -------------------------
//#include "cwsw_lib.h"

// ----	Module Headers --------------------------
#include "cwsw_arch.h"


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Global Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Module-level Variables ------------------------------------------------
// ============================================================================

static bool initialized = false;


// ============================================================================
// ----	Private Prototypes ----------------------------------------------------
// ============================================================================

#if (USE_SYS_CLK)
#include "system/clk/sys_clk.h"

#else
#define SYS_CLK_Initialize(a)			do { (void)(a); } while(0)

#endif

#if (USE_SYS_DEVCON)
#else
#define SYS_DEVCON_Initialize(a, b)		do { (void)(a); (void)(b); } while(0)
#define SYS_DEVCON_PerformanceConfig(a)	do { (void)(a); } while(0)
#endif

#if (USE_SYS_PORTS)
#include "system/ports/sys_ports.h"
#else
#define SYS_PORTS_Initialize()			do {} while(0)
#endif


// ============================================================================
// ----	Public Functions ------------------------------------------------------
// ============================================================================

uint16_t
Cwsw_Arch__Init(void)
{

#if defined(UNIT_TEST)
	// for desktop use, there's really not much to do here.

	#if defined(__GNUC__)	/* --- GNU Environment ------------------------------ */
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wpedantic"
	#endif

	dbg_printf(
			"\tModule ID %i\t%s\t%s\n"
			"\tEntering %s()\n\n",
			Cwsw_Arch, __FILE__, cwsw_arch_RevString,
			__FUNCTION__);

	#if defined(__GNUC__)	/* --- GNU Environment ------------------------------ */
	#pragma GCC diagnostic pop
	#endif
#endif

	/* Core Processor Initialization
	 * forgive this flagrant violation of personal ingenuity, but the names and call order is
	 * borrowed, /FOR NOW/, from MHC. I fully intend to abstract this so it's my own implementation,
	 * not a blatant borrowing of someone else's favored methods.
	 */
	SYS_CLK_Initialize( NULL );
	SYS_DEVCON_Initialize(0, NULL);
	SYS_DEVCON_PerformanceConfig(0);
	SYS_PORTS_Initialize();

	initialized = true;
	return 0;

}


bool
Cwsw_Arch__Get_Initialized(void)
{
	return initialized;
}
