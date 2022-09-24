#include <test_helper.h>

#define CAPSULE_HEADER_SIZE 1

VOID reset_process() {}

EFI_STATUS efi_main(
    EFI_HANDLE ImageHandle,
    EFI_SYSTEM_TABLE *SystemTable
) {

    EFI_STATUS status = EFI_SUCCESS;
    if ( SystemTable == NULL || ImageHandle == NULL ) {
        status = EFI_LOAD_ERROR;
        return status;
    }

    // GetNextHighMonotonicCount() test
    {
        UINT32 count = 0;
        status = SystemTable->RuntimeServices->GetNextHighMonotonicCount(&count);
        if ( status != EFI_SUCCESS ) {
            SystemTable->ConOut->OutputString( SystemTable->ConOut, L"GetNextHighMonotonicCount() test failed.\r\n");
            SystemTable->RuntimeServices->ResetSystem( EfiResetShutdown, status, 0, NULL );
        }
    }

    // UpdateCapsule() test
    {
        EFI_CAPSULE_HEADER* capsule_headers[CAPSULE_HEADER_SIZE] = { 0 };
        EFI_CAPSULE_HEADER capsule_header = {
            .CapsuleGuid = (EFI_GUID)EFI_MEMORY_RANGE_CAPSULE_GUID,
            .HeaderSize = sizeof(EFI_CAPSULE_HEADER),
            .Flags = (UINT32)CAPSULE_FLAGS_PERSIST_ACROSS_RESET,
            .CapsuleImageSize = sizeof(EFI_CAPSULE_HEADER)
        };

        capsule_headers[0] = (EFI_CAPSULE_HEADER *)(&capsule_header);

        status = SystemTable->RuntimeServices->UpdateCapsule(
            capsule_headers,
            ( UINTN )CAPSULE_HEADER_SIZE,
            ( EFI_PHYSICAL_ADDRESS )( &reset_process )
        );

        if ( !(status == EFI_SUCCESS || status == EFI_UNSUPPORTED) ) {
            SystemTable->ConOut->OutputString( SystemTable->ConOut, L"UpdateCapsule() test failed.\r\n");
            SystemTable->RuntimeServices->ResetSystem( EfiResetShutdown, status, 0, NULL );
        }
    }

    // ResetSystem() test
    {
        SystemTable->ConOut->OutputString( SystemTable->ConOut, (CHAR16 *)L"test success.\r\n" );
        SystemTable->RuntimeServices->ResetSystem(EfiResetShutdown, 10, 0, NULL);
        SystemTable->ConOut->OutputString( SystemTable->ConOut, L"ResetSystem() test failed.\r\n");
    }

    return EFI_SUCCESS;
}
