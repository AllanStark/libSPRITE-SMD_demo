## Overview
This is a minimal demo of using libSPRITE. This demo exercies a
sping-mass-damper system.

## Build
Execute 'make'

libSPRITE assumes the Lua headers are install in /usr/local/include. Some
distributions place it elsewhere. You can change where the Makefile looks for
the Lua include files by specifying the `LUA_INCLUDE` variable in the arguments
to `make`.

You can also change the number of Lua library to link to by setting the
`LUA_LIB` variable. ex.:

    `make LUA_INCLUDE=/usr/include/lua5.2`

## Run
As root (or sudo), execute './sprite_main smd.lua' where sprite_main is the
application and demo.lua is a script that describes what and how tasks built
using libSPRITE should do, such as task execution rates, priorities, etc...
These scripts can get much more sophisticated for larger applications.

## Modify
The parameters of the system can be modified in from the Lua script. Near the
top of the file are the spring constant (k), damper constant (B), and the mass.
Change these are rerun. There is not need to recompile the code. The parameters
are passed to the application through the script.
