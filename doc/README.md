# Project-specific documentation folder for the Arch component

## Overview

This folder contains items that pertain only to this project. The actual component documentation is in the `doc_arch` folder.

~~The project-specific files can be duplicated in the doc folder of the projects that use this component; the submodule is intended to be inserted in this location as a GIT submodule.~~


**NOTE**:
The Doxygen project is best rendered from the Integration project; because the component repo contains no dependencies on other CWSW Library components, the core settings are not available.



## Important folders

Folder              | Description
:---                | :---
doc_arch            | home to the documentation for this component

## Important files

File                | Description
:---                | :---
cwsw_arch.doxyfile  | Project-specific Doxygen project. For most developers, this will be the project to use to generate output.

## Tool-Related Tidbits

File `cwsw_arch.klb.doxyfile` is an example of how to override behavior or
settings of the project, in case they don't work for the specific
deployment environment.
