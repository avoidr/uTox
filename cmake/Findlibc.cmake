# - Try to find libc
# Once done this will define
#  LIBC_FOUND - System has libc
#  LIBC_INCLUDE_DIRS - The libc include directories
#  LIBC_LIBRARIES - The libraries needed to use libc
#  LIBC_DEFINITIONS - Compiler switches required for using libc

find_package(PkgConfig)

pkg_check_modules(PKG_LIBC QUIET libc)
set(LIBC_DEFINITIONS ${PKG_LIBC_CFLAGS_OTHER})

find_path(LIBC_INCLUDE_DIR stdlib.h HINTS
    ${PKG_LIBC_INCLUDEDIR}
    ${PKG_LIBC_INCLUDE_DIRS}
)

if(STATIC_ALL OR STATIC_C)
    find_library(LIBC_LIBRARY NAMES libc.a HINTS
        ${PKG_LIBC_LIBDIR}
        ${PKG_LIBC_LIBRARY_DIRS}
    )
else()
    find_library(LIBC_LIBRARY NAMES c HINTS
        ${PKG_LIBC_LIBDIR}
        ${PKG_LIBC_LIBRARY_DIRS}
    )
endif()

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBC_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(
    libc
    DEFAULT_MSG
    LIBC_LIBRARY
    LIBC_INCLUDE_DIR
)

mark_as_advanced(LIBC_INCLUDE_DIR LIBC_LIBRARY)

set(LIBC_LIBRARIES ${LIBC_LIBRARY})
set(LIBC_INCLUDE_DIRS ${LIBC_INCLUDE_DIR})
