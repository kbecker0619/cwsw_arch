# Reusable Component : MCU Architecture Support

## Overview

This folder is contains the implementation files for the MCU architectures supported by the CWSW Software libraries.

There is one directory for each supported architecture; in your build system, simply exclude all architectures except for the one around which your project is built.

Please see the detailed design documentation, created by Doxygen, for detailed information.

## Important folders

Folder          | Description
:---            | :---
i386            | Arch support for PC builds (Win + Lin)

## Important files

File | Description
:--- | :---
cwsw_arch_common.h | Supplemental API header; DO NOT INCLUDE DIRECTLY
