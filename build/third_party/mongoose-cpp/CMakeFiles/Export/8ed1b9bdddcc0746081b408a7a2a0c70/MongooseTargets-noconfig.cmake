#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mongoose" for configuration ""
set_property(TARGET mongoose APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(mongoose PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "C;CXX"
  IMPORTED_LINK_INTERFACE_LIBRARIES_NOCONFIG "dl"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libmongoose.a"
  )

list(APPEND _cmake_import_check_targets mongoose )
list(APPEND _cmake_import_check_files_for_mongoose "${_IMPORT_PREFIX}/lib/libmongoose.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
