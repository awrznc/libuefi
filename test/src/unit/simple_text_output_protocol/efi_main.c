#include <test_helper.h>

EFI_STATUS efi_main(
    EFI_HANDLE ImageHandle,
    EFI_SYSTEM_TABLE *SystemTable
) {
    if ( SystemTable == NULL || ImageHandle == NULL ) {
        SystemTable->RuntimeServices->ResetSystem(EfiResetShutdown, EFI_LOAD_ERROR, 0, NULL);
    }

    EFI_STATUS status = EFI_SUCCESS;

    // OutputString() test
    {
        status = SystemTable->ConOut->OutputString( SystemTable->ConOut, (CHAR16 *)L"example text.\r\n" );
        if ( status != EFI_SUCCESS ) {
            SystemTable->ConOut->OutputString( SystemTable->ConOut, L"OutputString() test failed.\r\n");
            SystemTable->RuntimeServices->ResetSystem( EfiResetShutdown, status, 0, NULL );
        }
    }

    SystemTable->ConOut->OutputString( SystemTable->ConOut, (CHAR16 *)L"test success.\r\n" );
    SystemTable->RuntimeServices->ResetSystem( EfiResetShutdown, status, 0, NULL );

    return EFI_SUCCESS;
}
