/** @file
 *	@brief	API common to all instances of the cwsw_arch reusable component.
 *
 *	Description:
 *	Do not include this file directly; it is intended to be included by the architecture-specific
 *	API file in one of the supported architectures, located immediately below this file's location.
 *
 *
 *	Copyright (c) 2018 Kevin L. Becker. All rights reserved.
 *
 *	Original:
 *	Created on: Jan 3, 2018
 *	Author: kbecker
 *
 *	Current:
 *	$Revision: $
 *	$Date: $
 */

#ifndef CWSW_ARCH_COMMON_H_
#define CWSW_ARCH_COMMON_H_

#ifdef	__cplusplus
extern "C" {
#endif

// ============================================================================
// ----	Include Files ---------------------------------------------------------
// ============================================================================

#include "projcfg.h"

// ----	System Headers --------------------------
#include <stdint.h>

// ----	Project Headers -------------------------

// ----	Module Headers --------------------------


// ============================================================================
// ----	Constants -------------------------------------------------------------
// ============================================================================
#define CWSW_ARCH_COMMON_H__REVSTRING "$Revision: 0123 $"


// ============================================================================
// ----	Type Definitions ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public Variables ------------------------------------------------------
// ============================================================================

// ============================================================================
// ----	Public API ------------------------------------------------------------
// ============================================================================

// ==== Discrete Functions ================================================== {
/** Initialization for the MCU Architecture Support component.
 *	This function's responsibility is to set up the local vars, and manage the necessary HW, to
 *	prepare for the task function's 1st call (once the scheduler has been started).
 *
 *	This function shall be called before the main scheduler is started.
 *
 *	As general guidance, the CWSW Library component should have been initialized
 *	before this function is called (since this module depends on the library),
 *	though this is not a strict requirement.
 *
 *	As general guidance, this should be called before board or application
 *	initialization functions. This module sits at the "bottom" of the dependency
 *	tree, excepting for calls into support libraries.
 *
 *	@returns error code, or 0 for no problem (i.e., success).
 */
extern uint16_t Cwsw_Arch__Init(void);

// ==== /Discrete Functions ================================================= }

// ==== Targets for Get/Set APIs ============================================ {

/** "Chapter Designator" for Get/Set API.
 *	Intentionally unused symbol, designed to get you to the correct starting
 *	point, when you want to find macros for the Get/Set API; simply highlight
 *	the Module argument in your IDE (e.g, Eclipse, NetBeans, etc.), and select
 *	Go To Definition.
 */
enum { Cwsw_Arch = 1 };	/* Generic architecture for all MCU architectures */

/** Target symbol for Get(Cwsw_Arch, xxx) interface */
#define Cwsw_Arch__Get(a)		Cwsw_Arch__Get_ ## a()

/** Target for Get(Cwsw_Arch, Initialized) interface */
extern bool 					Cwsw_Arch__Get_Initialized(void);

// ==== /Targets for Get/Set APIs =========================================== }


#ifdef	__cplusplus
}
#endif

// ====	COMPONENT DOCUMENTATION ============================================= {
#if defined(IN_DOXY)				/* { */
/* klb: i apologize in advance for burdening your build, by forcing your compiler to consume all of
 * this information every build, every file that includes it. My only justification is that this is
 * the only place common to all architectures, and, I want to limit reliance on supplemental
 * documents because those get lost. At least if the documentation is in the code, there is no
 * chance it'll get lost.
 */

/**	\page Arch_Head Reusable Component : MCU Architecture Support
 *	@tableofcontents
 * 		@subpage Arch_Introduction \n
 * 		@subpage Arch_Design \n
 * 		@subpage Arch_Integration \n
 * 		@subpage Arch_srs \n
 */

/**	\page Arch_Introduction					Introduction to the Architecture reusable component
 *	@tableofcontents
 *	This chapter briefly describes the design and implementation of the Architecture reusable
 *	component member of the CWSW library.
 *
 *	This chapter also briefly describes the integration of this feature into the larger code base
 *	of the user software project.
 *
 *	The intended audience of this document is any software engineer who uses the CWSW library and
 *	wants to add support for one (or more) of the supported architectures.
 *
 *	@section arch_directory_layout			Directory Layout
 *	The Includes structure here is slightly different than in other CWSW components designed for
 *	reuse / multiple deployments.
 *
 *	In most CWSW components, the main API is published at the root of the component folder;
 *	any local-to-component headers are located within appropriate subfolders.
 *
 *	For this component, the main API is at the root of the architecture-specific folder.
 *	While there is an API file that exposes all APIs common to all architectures located at the
 *	component root, this is not intended to be used by projects that use the Architecture-Support
 *	component.
 *
 *
 *	@section arch_related_docs				Applicable Documents
 *	TBD
 *
 *	@section arch_terms						Terms, Acronyms, Abbreviations
 *	TBD
 */

/**	\page Arch_Design						Architecture Subsystem Design
 *	@tableofcontents
 *		@subpage Arch_Responsibilities \n
 *		@subpage Arch_Constraints \n
 *		@subpage Arch_Interactions \n
 *		@subpage Arch_Composition \n
 *		@subpage Arch_Resources \n
 *		@subpage Arch_Interfaces \n
 *		@subpage Arch_Main_Obj_Diag \n
 *		@subpage Arch_Dsm \n
 */

	/**	@page Arch_Responsibilities			Component Responsibilities
	 *	@tableofcontents
	 * 	The Architecture component manages all aspects of the MCU. In some cases, one Component may
	 * 	be configured to handle multiple variants of the MCU; however, in most cases, there will be
	 * 	one Arch component per MCU variant.
	 */

	/**	@page Arch_Constraints				Constraints Imposed Upon Component
	 *	@tableofcontents
	 *	-	TBD. Should be at the "bottom" of the dependency tree, except for libraries such as the
	 *		CWSW Library.
	 */

	/**	\page Arch_Resources        	   	Resources
	 *	@tableofcontents
	 *	TBD
	 */

/**	@page Arch_Integration					Integrating the Reusable Component
 *	@tableofcontents
 *	To add the facilities of the CWSW Architecture component to your project, follow these steps.
 *
 *	@Note Author's note: These steps are generic for all IDEs; however, the specific details
 *	(e.g., screen shots) are oriented toward IDEs based on Eclipse, such as NXP S32DS; ARM DS-5; or
 *	TI's Code Composer.
 *	While I have implemented these steps in Microchip's MPLAB v4.x, the steps are so close that I
 *	didn't feel IDE-specific instructions were required.
 *
 *	Integration Steps:
 *	-# [Share the Source](#arch_source_share)
 *	-# [Add Dependencies](#arch_add_depends)
 *	-# [Update Includes paths](#arch_update_includes)
 *	-# [Configuration](#arch_comp_configuration)
 *	-# [Update Initialization Code](#arch_init_code)
 *	-# Optional APIs.
 */

	/**	@page Arch_Integration				Integrating the Reusable Component
	 *	@section arch_source_share			Share the Source
	 *	Designed to be a reusable component, the CWSW Architecture component is
	 *	organized into a reusable section, and requires additional project-
	 *	specific configuration items in the project.
	 *
	 *	The component layout in your workspace looks like this:
	 *	@code{.sh}

		cwsw_arch_prj/
		├── cwsw_arch
		│   ├── i386
		│   │   └── ...
		│   ├── MPC57xx
		│   │   ├── ...
		│   └── pic32mz
		│       └── ...
		├── doc
		│   ├── dox
		│   └── images
		└── ut

	 *	@endcode
	 *	@note This component is presently under construction; as support is added
	 *	for additional MCU architecture, the exact form of the directory tree
	 *	shown above may change.
	 *	@note Some features have been omitted for clarity.
	 *
	 *	The <code>cwsw_arch_prj</code> directory is the home to the various
	 *	project-management files (such as the Doxygen configuration, the Eclipse
	 *	project files, etc.), and is the parent for the component.
	 *
	 *	The <code>ut</code> directory is the source for the developer workspace
	 *	for this reusable component, and illustrates how to configure the
	 *	component is client projects.
	 *
	 *	The <code>doc</code> directory holds relevant design information not
	 *	included in this Doxygen format.
	 *
	 *	The <code>cwsw_arch</code> directory is the sharable and reusable portion
	 *	of the component.\n
	 *	The design intent is for this folder to be shared into your project's
	 *	directory structure.
	 *	-	@b Preferred: If your code management system can share folders
	 *		(e.g., PVCS / Dimensions, MKS), this might be a good solution; else,
	 *	-	@b Symlinks: filesystem symlinks are supported by GIT, with
	 *		appropriate configuration options set properly.
	 *	-	Example (using symlinks):\n
	 *	Given the following workspace directory structure:
	 *	@code{.sh}

	 	(workspace)
	 	├── components
	 	│   ├── cwsw_arch_prj
	 	│   ├── cwsw_board_prj
	 	│   └── cwsw_lib_prj
	 	├── cwsw_example_proj
	 	│   ├── appl_swc
	 	│   ├── cfg
	 	│   ├── drivers
	 	│   ├── libs
	 	│   ├── os
	 	│   ├── rte
	 	│   └── services
	 	├── doc
	 	└── ut

	 *	@endcode
	 *	Execute the following. @note This example is given using Cygwin; the same
	 *	command line verbatim would be done in Git Bash.\n
	 *	Also, 7-Zip can create symlinks, and there are other methods in Windows to create symbolic
	 *	links.
	 *
	 *	@code{.sh}

		$ cd cwsw_example_proj/drivers/
		$ ln -s ../../components/cwsw_arch_prj/cwsw_arc cwsw_arch
		$ git add cwsw_arch

		$ tree -dL 4
		(workspace)
	 	├── components
	 	│   ├── cwsw_arch_prj
	 	│   ├── cwsw_board_prj
	 	│   └── cwsw_lib_prj
	 	├── cwsw_example_proj
	 	│   ├── appl_swc
	 	│   ├── cfg
	 	│   ├── drivers
		│   │   └── cwsw_arch -> ../../components/cwsw_arch_prj/cwsw_arch
		│   ├── libs
		│   ├── os
		│   ├── rte
	 	│   └── services
	 	├── doc
	 	└── ut

	 *	@endcode
	 *	@note The placement above, in the <code> drivers </code> folder, is
	 *	only a suggestion. Wherever you locate it, if you are using filesystem
	 *	symlinks, it is important to use relative symlinks to maintain
	 *	portability from one dev system to another. <em>(If you are using a
	 *	sharing mechanism from your source versioning system, use the most
	 *	appropriate linking or referencing mechanism is appropriate.)</em>
	 *	\n \n
	 */

	/**	@page Arch_Integration
	 *	@section arch_add_depends			Add Component Dependencies
	 *
	 *	The <code>cwsw_arch</code> component has only one dependency to any
	 *	other cwsw component: to <code>cwsw_lib</code>. To integrate this
	 *	component, refer to the integration instructions [here](@ref Lib_Integration).
	 *	\n \n
	 */

	/**	@page Arch_Integration
	 *	@section arch_update_includes		Update Includes paths
	 *	@subsection arch_update_includes_paths	Include Paths
	 *	Update your build system to add the relative paths to the selected
	 *	architecture folder in the <code>cwsw_arch</code> folder. @b Note this is
	 *	different than in other CWSW components; this path is one level "deeper."
	 *
	 *	To clarify what you're looking for, here is the annotation for each of
	 *	the files in the <code> arch </code> project.
	 *	@note The design intent, is for all references within the project, to be
	 *	relative to the project itself. Portability is greatly reduced when the
	 *	project refers to fully qualified pathnames, or those outside of the
	 *	project tree itself.
	 *
	 *	@code{.sh}

		$ tree cwsw_arch_prj/ -dL 2
		cwsw_arch_prj/
		├── cwsw_arch				<<== target for symlink into your project
		│   ├── i386					<<== point your includes path to one and only one ...
		│   ├── MPC57xx					<<== of the arch folders, and exclude the rest from ...
		│   └── pic32mz					<<== within your build system (see next section).
		├── doc
		└── ut

	 *	@endcode
	 *	@note Some elements of the tree above have been excluded for clarity.
	 *
	 *	To illustrate how this might be done in an Eclipse-based project, see
	 *	the following screen capture: \n
	 *	@image html eclipse_add_includes_path.png			"Example Includes Path"
	 *	\n
	 *
	 *	@subsection arch_exclude_undesireables	Exclude Optional Architectures
	 *	Because (at least a portion of) the API that faces "upwards" must be
	 *	the same across all supported architectures, multiple definitions of
	 *	those API functions will exist unless those modules are excluded from
	 *	your build.
	 *
	 *	In Eclipse and IDEs derived from it, the easiest way to do this is to
	 *	specifically exclude a folder from the Project Properties dialog. Here
	 *	is an example: \n
	 *	@image html eclipse_exclude_folder_from_build.png	"Exclude Directory Item from Build"
	 *	This same "exclude" checkbox appears in multiple places in the project
	 *	properties dialog.
	 *
	 *	In makefile-based projects, simply omit reference to the undesired
	 *	architectures.
	 *	\n \n
	 */

	/**	@page Arch_Integration
	 *	@section arch_comp_configuration		Configure the Reusable Component and its dependencies
	 *	In some or the supported architectures, no configuration beyond what
	 *	has already been described is necessary. In some others, additional
	 *	items may need to be configured.
	 *
	 *	If the configurations are configured via preprocessor defines, there are two
	 *	easy methods of accomplishing this:
	 *	+ command-line defines
	 *	+ preprocessor defines in the file "projcfg.h"
	 */

	/**	@page Arch_Integration
	 *	@section arch_init_code					Update application's initialization code
	 *	At the time of this writing, none of the supported architectures require
	 *	any secondary initialization (e.g., initialization calls made after the
	 *	scheduler is started).
	 *
	 *	While not strictly required, it is recommended that the CWSW Library is
	 *	initialized first; following this, the Architecture component can be
	 *	initialized. Because, conceptually, the Architecture component lies at
	 *	the "bottom" (i.e., foundation) of the dependency tree, it should be the
	 *	initialized before other components.
	 *
	 *	One of the APIs introduced is an abstraction intended to give the same signature to all
	 *	CWSW modules: <code>Init(Component)</code>. This is optional, but when used, looks like
	 *	this:
	 *	@code{.c}

	 	void main(void)
	 	{
	 		(void)Init(Cwsw_Lib);
	 		(void)Init(Cwsw_Arch);
	 		... more initilization

	 		... main code follows ...
	 	}

	 *	@endcode
	 *	\n \n
	 */


/**	\page Arch_srs							Architecture Software Requirements
 *	@tableofcontents
 *	TBD. Might be delineated in an external document.
 */

#endif								/* } */
// ==== /COMPONENT DOCUMENTATION ============================================ }


#endif /* CWSW_ARCH_COMMON_H_ */
