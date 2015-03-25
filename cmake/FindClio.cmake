# Copyright (c) 2015, Chris Hutchinson
#
# See LICENSE.md in the distribution for the full license text including,
# but not limited to, a notice of warranty and distribution rights.

# Find Clio depdendency

include(FindPackageHandleStandardArgs)

if (CLIO_INCLUDE_DIR)
  set(CLIO_FIND_QUIETLY TRUE)
endif ()

# Set default search directories...

set (CLIO_SEARCH_DIRS
  "/usr/include"
  "/usr/local/include"
)

# If root specified then add more directories to the search paths

if (CLIO_ROOT_DIR)
  set(CLIO_SEARCH_DIRS "${CLIO_ROOT_DIR}"
                            "${CLIO_ROOT_DIR}/include"
                             ${CLIO_SEARCH_DIRS})
endif ()

# Look for Clio...

find_path(CLIO_INCLUDE_DIR Clio.h
  PATHS ${CLIO_SEARCH_DIRS}
)

find_library(CLIO_LIBRARY_RELEASE NAMES Clio
             HINTS ${PC_CLIO_LIBDIR} ${PC_CLIO_LIBRARY_DIRS} )
			 
find_library(CLIO_LIBRARY_DEBUG NAMES Cliod
             HINTS ${PC_CLIO_LIBDIR} ${PC_CLIO_LIBRARY_DIRS} )

SET(CLIO_LIBRARY
debug ${CLIO_LIBRARY_DEBUG}
optimized ${CLIO_LIBRARY_RELEASE}
)

find_package_handle_standard_args(CLIO DEFAULT_MSG CLIO_INCLUDE_DIR)
mark_as_advanced(CLIO_INCLUDE_DIR)

# Set friendly / useful variables

if (CLIO_FOUND)
  set(CLIO_INCLUDE_DIRS "${CLIO_INCLUDE_DIR}")
  set(CLIO_LIBRARIES ${CLIO_LIBRARY} )
endif ()
