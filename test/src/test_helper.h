#ifndef INCLUDED_UEFI_TEST_HELPER
#define INCLUDED_UEFI_TEST_HELPER

#include <uefi.h>

_Static_assert(sizeof(BOOLEAN) == 1, "Expecting 8 bit integers");
_Static_assert(sizeof(INTN) == 4, "Expecting 32 bit integers");
_Static_assert(sizeof(UINTN) == 4, "Expecting 32 bit integers");
_Static_assert(sizeof(INT8) == 1, "Expecting 8 bit integers");
_Static_assert(sizeof(UINT8) == 1, "Expecting 8 bit integers");
_Static_assert(sizeof(INT16) == 2, "Expecting 16 bit integers");
_Static_assert(sizeof(UINT16) == 2, "Expecting 16 bit integers");
_Static_assert(sizeof(INT32) == 4, "Expecting 32 bit integers");
_Static_assert(sizeof(UINT32) == 4, "Expecting 32 bit integers");
_Static_assert(sizeof(INT64) == 8, "Expecting 64 bit integers");
_Static_assert(sizeof(UINT64) == 8, "Expecting 64 bit integers");
_Static_assert(sizeof(INT128) == 16, "Expecting 128 bit integers");
_Static_assert(sizeof(UINT128) == 16, "Expecting 128 bit integers");
_Static_assert(sizeof(CHAR8) == 1, "Expecting 8 bit integers");
_Static_assert(sizeof(CHAR16) == 2, "Expecting 16 bit integers");
_Static_assert(sizeof(EFI_GUID) == 16, "Expecting 128 bit integers");

_Static_assert(sizeof(EFI_MAC_ADDRESS) == 32, "Expecting 32 byte integers");
_Static_assert(sizeof(EFI_IPv4_ADDRESS) == 4, "Expecting 4 byte integers");
_Static_assert(sizeof(EFI_IPv6_ADDRESS) == 16, "Expecting 16 byte integers");
_Static_assert(sizeof(EFI_IP_ADDRESS) == 16, "Expecting 16 byte integers");

#define NULL 0x0

#endif
