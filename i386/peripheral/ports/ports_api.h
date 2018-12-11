/** @file
 *	@brief	GPIO pin definitions for desktop.
 *
 *	Description:
 *
 *
 *	@note	This file is an as-needed COPY of the file created by Microchip's Harmony Configurator,
 *	v2.04, and/or the tool-created support files (e.g., Peripheral Libs) supplied as part of the
 *	MHC eco system. We have NO intention of stealing code or technology, or of claiming undue
 *	credit. This file is here ONLY during the buildup of support for the PIC32 MZ2048 EFM 144
 *	Starter Kit, what we call the "MZ EZ" board. Eventually, I hope to link directly to Harmony's
 *	code, in a way that allows different target architectures
 *
 *	Anyway, because this is a copy of code generated by a tool owned by Microchip, there is
 *	attribution here but no copyright notice.
 *
 *
 *	Original:
 *	Created on: Dec 28, 2017
 *	Author: kbecker
 *
 *	Current:
 *	$Revision: $
 *	$Date: $
 */

#ifndef PORTS_NONE_H_
#define PORTS_NONE_H_


// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

#include "projcfg.h"

// ----	System Headers --------------------------
#include <stdint.h>
#include <stdbool.h>	/* bool */

// ----	Project Headers -------------------------
#include "cwsw_lib.h"

// ----	Module Headers --------------------------


#ifdef	__cplusplus
extern "C" {
#endif


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================
#define PORTS_NONE_H__REVSTRING "$Revision: 0123 $"

typedef enum {

    PORTS_ID_0 = 0,
    PORTS_NUMBER_OF_MODULES = 1

} PORTS_MODULE_ID;

typedef enum {

    PORTS_BIT_POS_0 = 0,
    PORTS_BIT_POS_1 = 1,
    PORTS_BIT_POS_2 = 2,
    PORTS_BIT_POS_3 = 3,
    PORTS_BIT_POS_4 = 4,
    PORTS_BIT_POS_5 = 5,
    PORTS_BIT_POS_6 = 6,
    PORTS_BIT_POS_7 = 7,
    PORTS_BIT_POS_8 = 8,
    PORTS_BIT_POS_9 = 9,
    PORTS_BIT_POS_10 = 10,
    PORTS_BIT_POS_11 = 11,
    PORTS_BIT_POS_12 = 12,
    PORTS_BIT_POS_13 = 13,
    PORTS_BIT_POS_14 = 14,
    PORTS_BIT_POS_15 = 15

} PORTS_BIT_POS;

/** Port channel enumeration, ala Microchip PIC32 MZ */
typedef enum {

    PORT_CHANNEL_A = 0x00,
    PORT_CHANNEL_B = 0x01,
    PORT_CHANNEL_C = 0x02,
    PORT_CHANNEL_D = 0x03,
    PORT_CHANNEL_E = 0x04,
    PORT_CHANNEL_F = 0x05,
    PORT_CHANNEL_G = 0x06,
    PORT_CHANNEL_H = 0x07,
    PORT_CHANNEL_J = 0x08,
    PORT_CHANNEL_K = 0x09

} PORTS_CHANNEL;


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

/* Default definition used for all API dispatch functions */
#ifndef PLIB_INLINE_API
	#define PLIB_INLINE_API extern inline
#endif

/* Default definition used for all other functions */
#ifndef PLIB_INLINE
    #define PLIB_INLINE inline
#endif


// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================

/* Function:
    void PLIB_PORTS_PinWrite( PORTS_MODULE_ID index, PORTS_CHANNEL channel,
                              PORTS_BIT_POS       bitPos,
                              bool            value )

  Summary:
    Writes the selected digital pin/latch.

  Description:
    This function writes to the selected digital pin/latch.
    This function does not perform atomic register access.

  Precondition:
    None.

  Parameters:
    index           - Identifier for the device instance to be configured
    channel         - Identifier for the Ports channel A, B, C, etc.
    bitPos          - Possible values of PORTS_BIT_POS
    value           - Value to be written to the specific pin/latch
                      true - sets the bit, false - clears the bit

  Returns:
    None.

  Example:
    <code>

    // write 'one' in port RC4
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_C, PORTS_BIT_POS_4, 1);

    </code>

  Remarks:
	This feature may not be available on all devices. Please refer to the
	specific device data sheet to determine availability or use
	PLIB_PORTS_ExistsPortsWrite in your application to determine whether
	this feature is available.
*/
extern void PLIB_PORTS_PinWrite(
		PORTS_MODULE_ID	index, 	PORTS_CHANNEL	channel,
		PORTS_BIT_POS   bitPos,	bool            value );


extern bool PLIB_PORTS_PinGet(
		PORTS_MODULE_ID index, PORTS_CHANNEL channel,
		PORTS_BIT_POS bitPos);

#ifdef	__cplusplus
}
#endif

#endif /* PORTS_NONE_H_ */
