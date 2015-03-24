# Copyright (c) 2015, Chris Hutchinson
#
# See LICENSE.md in the distribution for the full license text including,
# but not limited to, a notice of warranty and distribution rights.

# Find LuaBridge depdendency

include(FindPackageHandleStandardArgs)

if (LUABRIDGE_INCLUDE_DIR)
  set(LUABRIDGE_FIND_QUIETLY TRUE)
endif ()

# Set default search directories...

set (LUABRIDGE_SEARCH_DIRS
  "/usr/include"
  "/usr/local/include"
)

# If root specified then add more directories to the search paths

if (LUABRIDGE_ROOT_DIR)
  set(LUABRIDGE_SEARCH_DIRS "${LUABRIDGE_ROOT_DIR}"
                            "${LUABRIDGE_ROOT_DIR}/Source/LuaBridge"
                             ${LUABRIDGE_SEARCH_DIRS})
endif ()

# Look for LuaBridge...

find_path(LUABRIDGE_INCLUDE_DIR LuaBridge.h
  PATHS ${LUABRIDGE_SEARCH_DIRS}
)

find_package_handle_standard_args(LUABRIDGE DEFAULT_MSG LUABRIDGE_INCLUDE_DIR)
mark_as_advanced(LUABRIDGE_INCLUDE_DIR)

# Set friendly / useful variables

if (LUABRIDGE_FOUND)
  set(LUABRIDGE_INCLUDE_DIRS "${LUABRIDGE_INCLUDE_DIR}")
endif ()
