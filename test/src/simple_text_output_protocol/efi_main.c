#include <test_helper.h>

EFI_STATUS efi_main(
    EFI_HANDLE ImageHandle,
    EFI_SYSTEM_TABLE *SystemTable
) {
    if ( SystemTable == NULL || ImageHandle == NULL ) {
        SystemTable->RuntimeServices->ResetSystem(EfiResetShutdown, EFI_LOAD_ERROR, 0, NULL);
    }

    EFI_STATUS result = SystemTable->ConOut->OutputString( SystemTable->ConOut, (CHAR16 *)L"example text.\r\n" );
    SystemTable->RuntimeServices->ResetSystem( EfiResetShutdown, result, 0, NULL );

    return EFI_SUCCESS;
}
