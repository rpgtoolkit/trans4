# Unofficial Development of RPG Toolkit 4

Unofficial developing of the 4th RPG Toolkit (rpgtoolkit.net).

# Dependencies

The current version depends on SDL2 (not included) and Lua (included). You will need to download (https://www.libsdl.org/download-2.0.php) and extract SDL2 to the external directory. This will give you extract/SDL2/include and extract/SDL2/lib directories which are necessary to compile.

A visual studio solution file is available in the VS2013 directory. After extracting SDL2, you should be able to compile all projects in either Release or Debug configurations. You will be able to find the binaries in build/CONFIGURATION/. In order to run the application you will have to copy+paste SDL2.dll into the same directory as the binary. SDL2.dll can be found in the lib folder where you extracted SDL2. Compilation currently defaults to x86.
