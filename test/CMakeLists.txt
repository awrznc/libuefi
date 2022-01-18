cmake_minimum_required(VERSION 3.10)
project(libuefi_test C)

set(CMAKE_C_LINK_EXECUTABLE "lld-link-11 /subsystem:efi_application /entry:efi_main /out:<TARGET> <OBJECTS>")
set(CMAKE_CROSSCOMPILING_EMULATOR qemu-system-x86_64 -bios OVMF.fd -nographic -drive format=raw,file=fat:rw:bin)

enable_testing()

file(GLOB_RECURSE SOURCE_CODE_LIST "${RUNTIME_OUTPUT_DIRECTORY}*.c")
foreach(SOURCE_CODE ${SOURCE_CODE_LIST})

  # Get test target name
  get_filename_component(TEST_TARGET_DIRECTORY ${SOURCE_CODE} DIRECTORY)
  string(REGEX MATCH "[^\/]+$" TEST_TARGET ${TEST_TARGET_DIRECTORY})

  # Build
  add_executable(${TEST_TARGET} ${SOURCE_CODE})
  set_target_properties(${TEST_TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin/${TEST_TARGET}/EFI/BOOT/ OUTPUT_NAME "BOOTX64.EFI")
  target_compile_options(${TEST_TARGET} PUBLIC $<$<C_COMPILER_ID:Clang>:-target x86_64-pc-win32-coff -fno-stack-protector -fshort-wchar -std=c11 -Wall -Wextra -Wpedantic>)
  target_include_directories(${TEST_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include/ ${CMAKE_CURRENT_SOURCE_DIR}/src/)

  # Run test
  add_test( NAME ${TEST_TARGET} COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR}/${TEST_TARGET} )
  set_tests_properties( ${TEST_TARGET} PROPERTIES FAIL_REGULAR_EXPRESSION "test failed" )
endforeach(SOURCE_CODE)
