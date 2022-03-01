# Need to check things per compiler brand since they're different
if(CMAKE_C_COMPILER_ID STREQUAL "Intel")
  option_with_flags(ENABLE_XHOST "Enable processor-specific optimization" ON "-xHost")
elseif(CMAKE_C_COMPILER_ID STREQUAL "GNU")
  option_with_flags(ENABLE_XHOST "Enable processor-specific optimization" ON  "-march=native")
elseif(CMAKE_C_COMPILER_ID STREQUAL "Clang")
    if (CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
        # clang-cl
        option_with_flags(ENABLE_XHOST "Enable processor-specific optimization" ON  "/arch:AVX2")
    elseif (CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "GNU")
        if (NOT CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "arm64")
            option_with_flags(ENABLE_XHOST "Enable processor-specific optimization" ON  "-march=native")
        endif()
    endif()
elseif(CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
  option_with_flags(ENABLE_XHOST "Enable processor-specific optimization" ON  "-march=native")
elseif(CMAKE_C_COMPILER_ID STREQUAL "PGI")
  option_with_flags(ENABLE_XHOST "Enable processor-specific optimization" ON  "-tp host")
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
  option_with_flags(ENABLE_XHOST "Enable processor-specific optimization" ON  "/arch:AVX2")
endif()
# IntelLLVM
