/**
  * UEFI Images
  **/
#define EFI_IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#define EFI_IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#define EFI_IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12

#define EFI_IMAGE_MACHINE_IA32 0x014c
#define EFI_IMAGE_MACHINE_IA64 0x0200
#define EFI_IMAGE_MACHINE_EBC 0x0EBC
#define EFI_IMAGE_MACHINE_x64 0x8664
#define EFI_IMAGE_MACHINE_ARMTHUMB_MIXED 0x01C2
#define EFI_IMAGE_MACHINE_AARCH64 0xAA64
#define EFI_IMAGE_MACHINE_RISCV32 0x5032
#define EFI_IMAGE_MACHINE_RISCV64 0x5064
#define EFI_IMAGE_MACHINE_RISCV128 0x5128


/**
  * Data Types
  **/
typedef signed char BOOLEAN;
typedef signed long int INTN;
typedef unsigned long int UINTN;
typedef signed char INT8;
typedef unsigned char UINT8;
typedef signed short int INT16;
typedef unsigned short int UINT16;
typedef signed long int INT32;
typedef unsigned long int UINT32;
typedef signed long long int INT64;
typedef unsigned long long int UINT64;
// typedef (16-byte signed type) INT128;
// typedef (16-byte unsigned type) UINT128;
typedef signed char CHAR8;
typedef signed short int CHAR16;
typedef void VOID;

typedef struct {
    unsigned int Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} EFI_GUID;

typedef UINTN EFI_STATUS;
typedef VOID* EFI_HANDLE;
typedef VOID* EFI_EVENT;
typedef UINT64 EFI_LBA;
typedef UINTN EFI_TPL;

typedef struct {
    UINT8 Addr[32];
} EFI_MAC_ADDRESS;

typedef struct {
    UINT8 Addr[4];
} EFI_IPv4_ADDRESS;

typedef struct {
    UINT8 Addr[16];
} EFI_IPv6_ADDRESS;

typedef union {
    UINT32 Addr[4];
    EFI_IPv4_ADDRESS v4;
    EFI_IPv6_ADDRESS v6;
} EFI_IP_ADDRESS;

#define IN
#define OUT
#define OPTIONAL
#define CONST
#define EFIAPI


/**
  * Memory types
  **/
#define EFI_MEMORY_UC 0x0000000000000001
#define EFI_MEMORY_WC 0x0000000000000002
#define EFI_MEMORY_WT 0x0000000000000004
#define EFI_MEMORY_WB 0x0000000000000008
#define EFI_MEMORY_UCE 0x0000000000000010
#define EFI_MEMORY_WP 0x0000000000001000
#define EFI_MEMORY_RP 0x0000000000002000
#define EFI_MEMORY_XP 0x0000000000004000
#define EFI_MEMORY_NV 0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE 0x0000000000010000
#define EFI_MEMORY_RO 0x0000000000020000
#define EFI_MEMORY_SP 0x0000000000040000
#define EFI_MEMORY_CPU_CRYPTO 0x0000000000080000
#define EFI_MEMORY_RUNTIME 0x8000000000000000

typedef struct {
    UINT16 ScanCode;
    CHAR16 UnicodeChar;
} EFI_INPUT_KEY;

typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef EFI_STATUS (EFIAPI *EFI_INPUT_RESET) ( IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, IN BOOLEAN ExtendedVerification );
typedef EFI_STATUS (EFIAPI *EFI_INPUT_READ_KEY) ( IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, OUT EFI_INPUT_KEY *Key );

typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    EFI_INPUT_RESET Reset;
    EFI_INPUT_READ_KEY ReadKeyStroke;
    EFI_EVENT WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef EFI_STATUS (EFIAPI *EFI_TEXT_RESET) ( IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, IN BOOLEAN ExtendedVerification );
typedef EFI_STATUS (EFIAPI *EFI_TEXT_STRING) ( IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, IN CHAR16 *String );
typedef EFI_STATUS (EFIAPI *EFI_TEXT_TEST_STRING) ( IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, IN CHAR16 *String );
typedef EFI_STATUS (EFIAPI *EFI_TEXT_QUERY_MODE) ( IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, IN UINTN ModeNumber, OUT UINTN *Columns, OUT UINTN *Rows );
typedef EFI_STATUS (EFIAPI *EFI_TEXT_SET_MODE) ( IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, IN UINTN ModeNumber );
typedef EFI_STATUS (EFIAPI *EFI_TEXT_SET_ATTRIBUTE) ( IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, IN UINTN Attribute );
typedef EFI_STATUS (EFIAPI *EFI_TEXT_CLEAR_SCREEN) ( IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This );
typedef EFI_STATUS (EFIAPI *EFI_TEXT_SET_CURSOR_POSITION) ( IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, IN UINTN Column, IN UINTN Row );
typedef EFI_STATUS (EFIAPI *EFI_TEXT_ENABLE_CURSOR) ( IN EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, IN BOOLEAN Visible );

typedef struct {
    INT32 MaxMode;
    INT32 Mode;
    INT32 Attribute;
    INT32 CursorColumn;
    INT32 CursorRow;
    BOOLEAN CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    EFI_TEXT_RESET Reset;
    EFI_TEXT_STRING OutputString;
    EFI_TEXT_TEST_STRING TestString;
    EFI_TEXT_QUERY_MODE QueryMode;
    EFI_TEXT_SET_MODE SetMode;
    EFI_TEXT_SET_ATTRIBUTE SetAttribute;
    EFI_TEXT_CLEAR_SCREEN ClearScreen;
    EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
    EFI_TEXT_ENABLE_CURSOR EnableCursor;
    SIMPLE_TEXT_OUTPUT_MODE *Mode;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;


/**
  * Runtime Services
  **/
typedef struct {
    UINT16 Year;
    UINT8 Month;
    UINT8 Day;
    UINT8 Hour;
    UINT8 Minute;
    UINT8 Second;
    UINT8 Pad1;
    UINT32 Nanosecond;
    INT16 TimeZone;
    UINT8 Daylight;
    UINT8 Pad2;
} EFI_TIME;

#define EFI_TIME_ADJUST_DAYLIGHT 0x01
#define EFI_TIME_IN_DAYLIGHT 0x02

#define EFI_UNSPECIFIED_TIMEZONE 0x07FF

typedef struct {
    UINT32 Resolution;
    UINT32 Accuracy;
    BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

typedef EFI_STATUS (EFIAPI *EFI_GET_TIME) ( IN EFI_TIME *Time, IN EFI_TIME_CAPABILITIES *Capabilities );
typedef EFI_STATUS (EFIAPI *EFI_SET_TIME) ( IN EFI_TIME *Time);
typedef EFI_STATUS (EFIAPI *EFI_GET_WAKEUP_TIME) ( OUT BOOLEAN *Enabled, OUT BOOLEAN *Pending, OUT EFI_TIME *Time );
typedef EFI_STATUS (EFIAPI *EFI_SET_WAKEUP_TIME) ( IN BOOLEAN Enable, IN EFI_TIME *Time OPTIONAL );

typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

typedef struct {
    UINT32 Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

typedef EFI_STATUS (EFIAPI *EFI_SET_VIRTUAL_ADDRESS_MAP) ( IN UINTN MemoryMapSize, IN UINTN DescriptorSize, IN UINT32 DescriptorVersion, IN EFI_MEMORY_DESCRIPTOR *VirtualMap );
typedef EFI_STATUS (EFIAPI *EFI_CONVERT_POINTER) ( IN UINTN DebugDisposition, IN VOID **Address );

#define EFI_OPTIONAL_PTR 0x00000001

typedef EFI_STATUS (EFIAPI *EFI_GET_VARIABLE) ( IN CHAR16 *VariableName, IN EFI_GUID *VendorGuid, OUT UINT32 *Attributes OPTIONAL, IN OUT UINTN *DataSize, OUT VOID *Data OPTIONAL );
typedef EFI_STATUS (EFIAPI *EFI_GET_NEXT_VARIABLE_NAME) ( IN OUT UINTN *VariableNameSize, IN OUT CHAR16 *VariableName, IN OUT EFI_GUID *VendorGuid );
typedef EFI_STATUS (EFIAPI *EFI_SET_VARIABLE) ( IN CHAR16 *VariableName, IN EFI_GUID *VendorGuid, IN UINT32 Attributes, IN UINTN DataSize, IN VOID *Data );
typedef EFI_STATUS (EFIAPI *EFI_GET_NEXT_HIGH_MONO_COUNT) ( OUT UINT32 *HighCount );

typedef enum {
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
} EFI_RESET_TYPE;

typedef VOID (EFIAPI *EFI_RESET_SYSTEM) ( IN EFI_RESET_TYPE ResetType, IN EFI_STATUS ResetStatus, IN UINTN DataSize, IN VOID *ResetData OPTIONAL );

typedef struct {
    UINT64 Length;
    union {
        EFI_PHYSICAL_ADDRESS DataBlock;
        EFI_PHYSICAL_ADDRESS ContinuationPointer;
    } Union;
} EFI_CAPSULE_BLOCK_DESCRIPTOR;

typedef struct {
    EFI_GUID CapsuleGuid;
    UINT32 HeaderSize;
    UINT32 Flags;
    UINT32 CapsuleImageSize;
} EFI_CAPSULE_HEADER;

#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 0x00040000

typedef EFI_STATUS (EFIAPI *EFI_UPDATE_CAPSULE) ( IN EFI_CAPSULE_HEADER **CapsuleHeaderArray, IN UINTN CapsuleCount, IN EFI_PHYSICAL_ADDRESS ScatterGatherList OPTIONAL );
typedef EFI_STATUS (EFIAPI *EFI_QUERY_CAPSULE_CAPABILITIES) ( IN EFI_CAPSULE_HEADER **CapsuleHeaderArray, IN UINTN CapsuleCount, OUT UINT64 *MaximumCapsuleSize, OUT EFI_RESET_TYPE *ResetType );
typedef EFI_STATUS (EFIAPI *EFI_QUERY_VARIABLE_INFO) ( IN UINT32 Attributes, OUT UINT64 *MaximumVariableStorageSize, OUT UINT64 *RemainingVariableStorageSize, OUT UINT64 *MaximumVariableSize );

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

typedef struct {
    UINT32 CapsuleArrayNumber;
    VOID* CapsulePtr[1];
} EFI_CAPSULE_TABLE;

#define EFI_MEMORY_RANGE_CAPSULE_GUID { 0xde9f0ec, 0x88b6, 0x428f, { 0x97, 0x7a, 0x25, 0x8f, 0x1d, 0xe, 0x5e, 0x72 } }

typedef struct {
    EFI_PHYSICAL_ADDRESS Address;
    UINT64 Length;
} EFI_MEMORY_RANGE;

typedef struct {
    EFI_CAPSULE_HEADER Header;
    UINT32 OsRequestedMemoryType;
    UINT64 NumberOfMemoryRanges;
    EFI_MEMORY_RANGE MemoryRanges[];
} EFI_MEMORY_RANGE_CAPSULE;

typedef struct {
    UINT64 FirmwareMemoryRequirement;
    UINT64 NumberOfMemoryRanges;
} EFI_MEMORY_RANGE_CAPSULE_RESULT;

#define EFI_OS_INDICATIONS_BOOT_TO_FW_UI 0x0000000000000001
#define EFI_OS_INDICATIONS_TIMESTAMP_REVOCATION 0x0000000000000002
#define EFI_OS_INDICATIONS_FILE_CAPSULE_DELIVERY_SUPPORTED 0x0000000000000004
#define EFI_OS_INDICATIONS_FMP_CAPSULE_SUPPORTED 0x0000000000000008
#define EFI_OS_INDICATIONS_CAPSULE_RESULT_VAR_SUPPORTED 0x0000000000000010
#define EFI_OS_INDICATIONS_START_OS_RECOVERY 0x0000000000000020
#define EFI_OS_INDICATIONS_START_PLATFORM_RECOVERY 0x0000000000000040
#define EFI_OS_INDICATIONS_JSON_CONFIG_DATA_REFRESH 0x0000000000000080

#define EFI_CAPSULE_REPORT_GUID { 0x39b68c46, 0xf7fb, 0x441b, { 0xb6, 0xec, 0x16, 0xb0, 0xf6, 0x98, 0x21, 0xf3 } };

typedef struct {
    UINT32 VariableTotalSize;
    UINT32 Reserved;
    EFI_GUID CapsuleGuid;
    EFI_TIME CapsuleProcessed;
    EFI_STATUS CapsuleStatus;
} EFI_CAPSULE_RESULT_VARIABLE_HEADER;

typedef struct {
    UINT16 Version;
    UINT8 PayloadIndex;
    UINT8 UpdateImageIndex;
    EFI_GUID UpdateImageTypeId;
    // CHAR16 CapsuleFileName[];
    // CHAR16 CapsuleTarget[];
} EFI_CAPSULE_RESULT_VARIABLE_FMP;

typedef struct {
    UINT32 Version;
    UINT32 CapsuleId;
    UINT32 RespLength;
    UINT8 Resp[];
} EFI_CAPSULE_RESULT_VARIABLE_JSON;


typedef EFI_TPL (EFIAPI *EFI_RAISE_TPL) ( IN EFI_TPL NewTpl );
typedef VOID (EFIAPI *EFI_RESTORE_TPL) ( IN EFI_TPL OldTpl );

typedef enum {
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType
} EFI_ALLOCATE_TYPE;

typedef enum {
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiUnacceptedMemoryType,
    EfiMaxMemoryType
} EFI_MEMORY_TYPE;

typedef EFI_STATUS (EFIAPI *EFI_ALLOCATE_PAGES) ( IN EFI_ALLOCATE_TYPE Type, IN EFI_MEMORY_TYPE MemoryType, IN UINTN Pages, IN OUT EFI_PHYSICAL_ADDRESS *Memory );
typedef EFI_STATUS (EFIAPI *EFI_FREE_PAGES) ( IN EFI_PHYSICAL_ADDRESS Memory, IN UINTN Pages );
typedef EFI_STATUS (EFIAPI *EFI_GET_MEMORY_MAP) ( IN OUT UINTN *MemoryMapSize, OUT EFI_MEMORY_DESCRIPTOR *MemoryMap, OUT UINTN *MapKey, OUT UINTN *DescriptorSize, OUT UINT32 *DescriptorVersion );
typedef EFI_STATUS (EFIAPI *EFI_ALLOCATE_POOL) ( IN EFI_MEMORY_TYPE PoolType, IN UINTN Size, OUT VOID **Buffer );
typedef EFI_STATUS (EFIAPI *EFI_FREE_POOL) ( IN VOID *Buffer );

typedef VOID (EFIAPI *EFI_EVENT_NOTIFY) ( IN EFI_EVENT Event, IN VOID *Context );

typedef EFI_STATUS (EFIAPI *EFI_CREATE_EVENT) ( IN UINT32 Type, IN EFI_TPL NotifyTpl,  IN EFI_EVENT_NOTIFY NotifyFunction, OPTIONAL IN VOID *NotifyContext, OPTIONAL OUT EFI_EVENT *Event );

typedef enum {
    TimerCancel,
    TimerPeriodic,
    TimerRelative
} EFI_TIMER_DELAY;

typedef EFI_STATUS (EFIAPI *EFI_SET_TIMER) ( IN EFI_EVENT Event, IN EFI_TIMER_DELAY Type, IN UINT64 TriggerTime );
typedef EFI_STATUS (EFIAPI *EFI_WAIT_FOR_EVENT) ( IN UINTN NumberOfEvents, IN EFI_EVENT *Event, OUT UINTN *Index );
typedef EFI_STATUS (EFIAPI *EFI_SIGNAL_EVENT) ( IN EFI_EVENT Event );
typedef EFI_STATUS (EFIAPI *EFI_CLOSE_EVENT) ( IN EFI_EVENT Event );
typedef EFI_STATUS (EFIAPI *EFI_CHECK_EVENT) ( IN EFI_EVENT Event );

typedef enum {
 EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

typedef EFI_STATUS (EFIAPI *EFI_INSTALL_PROTOCOL_INTERFACE) ( IN OUT EFI_HANDLE *Handle, IN EFI_GUID *Protocol, IN EFI_INTERFACE_TYPE InterfaceType, IN VOID *Interface );
typedef EFI_STATUS (EFIAPI *EFI_REINSTALL_PROTOCOL_INTERFACE) ( IN EFI_HANDLE Handle, IN EFI_GUID *Protocol, IN VOID *OldInterface, IN VOID *NewInterface );
typedef EFI_STATUS (EFIAPI *EFI_UNINSTALL_PROTOCOL_INTERFACE) ( IN EFI_HANDLE Handle, IN EFI_GUID *Protocol, IN VOID *Interface );
typedef EFI_STATUS (EFIAPI *EFI_HANDLE_PROTOCOL) ( IN EFI_HANDLE Handle, IN EFI_GUID *Protocol, OUT VOID **Interface );

typedef EFI_STATUS (EFIAPI *EFI_REGISTER_PROTOCOL_NOTIFY) ( IN EFI_GUID *Protocol, IN EFI_EVENT Event, OUT VOID **Registration );

typedef enum {
    AllHandles,
    ByRegisterNotify,
    ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

typedef EFI_STATUS (EFIAPI *EFI_LOCATE_HANDLE) ( IN EFI_LOCATE_SEARCH_TYPE SearchType, IN EFI_GUID *Protocol OPTIONAL, IN VOID *SearchKey OPTIONAL, IN OUT UINTN *BufferSize, OUT EFI_HANDLE *Buffer );

#define EFI_DEVICE_PATH_PROTOCOL_GUID { 0x09576e91, 0x6d3f, 0x11d2, { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

typedef struct _EFI_DEVICE_PATH_PROTOCOL {
    UINT8 Type;
    UINT8 SubType;
    UINT8 Length[2];
} EFI_DEVICE_PATH_PROTOCOL;

typedef EFI_STATUS (EFIAPI *EFI_LOCATE_DEVICE_PATH) ( IN EFI_GUID *Protocol, IN OUT EFI_DEVICE_PATH_PROTOCOL **DevicePath, OUT EFI_HANDLE *Device );
typedef EFI_STATUS (EFIAPI *EFI_INSTALL_CONFIGURATION_TABLE) ( IN EFI_GUID *Guid, IN VOID *Table );
typedef EFI_STATUS (EFIAPI *EFI_IMAGE_LOAD) ( IN BOOLEAN BootPolicy, IN EFI_HANDLE ParentImageHandle, IN EFI_DEVICE_PATH_PROTOCOL *DevicePath, IN VOID *SourceBuffer OPTIONAL, IN UINTN SourceSize, OUT EFI_HANDLE *ImageHandle );
typedef EFI_STATUS (EFIAPI *EFI_IMAGE_START) ( IN EFI_HANDLE ImageHandle, OUT UINTN *ExitDataSize, OUT CHAR16 **ExitData OPTIONAL );
typedef EFI_STATUS (EFIAPI *EFI_EXIT) ( IN EFI_HANDLE ImageHandle, IN EFI_STATUS ExitStatus, IN UINTN ExitDataSize, IN CHAR16 *ExitData OPTIONAL );
typedef EFI_STATUS (EFIAPI *EFI_IMAGE_UNLOAD) ( IN EFI_HANDLE ImageHandle );
typedef EFI_STATUS (EFIAPI *EFI_EXIT_BOOT_SERVICES) ( IN EFI_HANDLE ImageHandle, IN UINTN MapKey );
typedef EFI_STATUS (EFIAPI *EFI_GET_NEXT_MONOTONIC_COUNT) ( OUT UINT64 *Count );
typedef EFI_STATUS (EFIAPI *EFI_STALL) ( IN UINTN Microseconds );
typedef EFI_STATUS (EFIAPI *EFI_SET_WATCHDOG_TIMER) ( IN UINTN Timeout, IN UINT64 WatchdogCode, IN UINTN DataSize, IN CHAR16 *WatchdogData OPTIONAL );
typedef EFI_STATUS (EFIAPI *EFI_CONNECT_CONTROLLER) ( IN EFI_HANDLE ControllerHandle, IN EFI_HANDLE *DriverImageHandle OPTIONAL, IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL, IN BOOLEAN Recursive );
typedef EFI_STATUS (EFIAPI *EFI_DISCONNECT_CONTROLLER) ( IN EFI_HANDLE ControllerHandle, IN EFI_HANDLE DriverImageHandle OPTIONAL, IN EFI_HANDLE ChildHandle OPTIONAL );
typedef EFI_STATUS (EFIAPI *EFI_OPEN_PROTOCOL) ( IN EFI_HANDLE Handle, IN EFI_GUID *Protocol, OUT VOID **Interface OPTIONAL, IN EFI_HANDLE AgentHandle, IN EFI_HANDLE ControllerHandle, IN UINT32 Attributes );
typedef EFI_STATUS (EFIAPI *EFI_CLOSE_PROTOCOL) ( IN EFI_HANDLE Handle, IN EFI_GUID *Protocol, IN EFI_HANDLE AgentHandle, IN EFI_HANDLE ControllerHandle );

typedef struct {
    EFI_HANDLE AgentHandle;
    EFI_HANDLE ControllerHandle;
    UINT32 Attributes;
    UINT32 OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

typedef EFI_STATUS (EFIAPI *EFI_OPEN_PROTOCOL_INFORMATION) ( IN EFI_HANDLE Handle, IN EFI_GUID *Protocol, OUT EFI_OPEN_PROTOCOL_INFORMATION_ENTRY **EntryBuffer, OUT UINTN *EntryCount );
typedef EFI_STATUS (EFIAPI *EFI_PROTOCOLS_PER_HANDLE) ( IN EFI_HANDLE Handle, OUT EFI_GUID ***ProtocolBuffer, OUT UINTN *ProtocolBufferCount );
typedef EFI_STATUS (EFIAPI *EFI_LOCATE_HANDLE_BUFFER) ( IN EFI_LOCATE_SEARCH_TYPE SearchType, IN EFI_GUID *Protocol OPTIONAL, IN VOID *SearchKey OPTIONAL, OUT UINTN *NoHandles, OUT EFI_HANDLE **Buffer );
typedef EFI_STATUS (EFIAPI *EFI_LOCATE_PROTOCOL) ( IN EFI_GUID *Protocol, IN VOID *Registration OPTIONAL, OUT VOID **Interface );
typedef EFI_STATUS (EFIAPI *EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES) ( IN OUT EFI_HANDLE *Handle, ... );
typedef EFI_STATUS (EFIAPI *EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES) ( IN EFI_HANDLE Handle, ... );
typedef VOID (EFIAPI *EFI_COPY_MEM) ( IN VOID *Destination, IN VOID *Source, IN UINTN Length );
typedef VOID (EFIAPI *EFI_SET_MEM) ( IN VOID *Buffer, IN UINTN Size, IN UINT8 Value );
typedef EFI_STATUS (EFIAPI *EFI_CREATE_EVENT_EX) ( IN UINT32 Type, IN EFI_TPL NotifyTpl,  IN EFI_EVENT_NOTIFY NotifyFunction OPTIONAL, IN CONST VOID *NotifyContext OPTIONAL, IN CONST EFI_GUID *EventGroup OPTIONAL, OUT EFI_EVENT *Event );

/**
  * Boot Manager
  **/
typedef struct _EFI_LOAD_OPTION {
    UINT32 Attributes;
    UINT16 FilePathListLength;
    // CHAR16 Description[];
    // EFI_DEVICE_PATH_PROTOCOL FilePathList[];
    // UINT8 OptionalData[];
} EFI_LOAD_OPTION;

#define LOAD_OPTION_ACTIVE 0x00000001
#define LOAD_OPTION_FORCE_RECONNECT 0x00000002
#define LOAD_OPTION_HIDDEN 0x00000008
#define LOAD_OPTION_CATEGORY 0x00001F00
#define LOAD_OPTION_CATEGORY_BOOT 0x00000000
#define LOAD_OPTION_CATEGORY_APP 0x00000100

#define EFI_BOOT_OPTION_SUPPORT_KEY 0x00000001
#define EFI_BOOT_OPTION_SUPPORT_APP 0x00000002
#define EFI_BOOT_OPTION_SUPPORT_SYSPREP 0x00000010
#define EFI_BOOT_OPTION_SUPPORT_COUNT 0x00000300

typedef union {
    struct {
        UINT32 Revision : 8;
        UINT32 ShiftPressed : 1;
        UINT32 ControlPressed : 1;
        UINT32 AltPressed : 1;
        UINT32 LogoPressed : 1;
        UINT32 MenuPressed : 1;
        UINT32 SysReqPressed : 1;
        UINT32 Reserved : 16;
        UINT32 InputKeyCount : 2;
    } Options;
    UINT32 PackedValue;
} EFI_BOOT_KEY_DATA;

typedef struct _EFI_KEY_OPTION {
    EFI_BOOT_KEY_DATA KeyData;
    UINT32 BootOptionCrc;
    UINT16 BootOption;
    // EFI_INPUT_KEY Keys[];
} EFI_KEY_OPTION;

#define EFI_BOOT_MANAGER_POLICY_PROTOCOL_GUID  { 0xfedf8e0c, 0xe147, 0x11e3, { 0x99, 0x03, 0xb8, 0xe8, 0x56, 0x2c, 0xba, 0xfa } }

typedef struct _EFI_BOOT_MANAGER_POLICY_PROTOCOL EFI_BOOT_MANAGER_POLICY_PROTOCOL;

#define EFI_BOOT_MANAGER_POLICY_PROTOCOL_REVISION 0x00010000

typedef EFI_STATUS (EFIAPI *EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_PATH) ( IN EFI_BOOT_MANAGER_POLICY_PROTOCOL *This, IN EFI_DEVICE_PATH *DevicePath, IN BOOLEAN Recursive );
typedef EFI_STATUS (EFIAPI *EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_CLASS) ( IN EFI_BOOT_MANAGER_POLICY_PROTOCOL *This, IN EFI_GUID *Class );

typedef struct _EFI_BOOT_MANAGER_POLICY_PROTOCOL {
    UINT64 Revision;
    EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_PATH ConnectDevicePath;
    EFI_BOOT_MANAGER_POLICY_CONNECT_DEVICE_CLASS ConnectDeviceClass;
} EFI_BOOT_MANAGER_POLICY_PROTOCOL;

#define EFI_BOOT_MANAGER_POLICY_CONSOLE_GUID { 0xcab0e94c, 0xe15f, 0x11e3, { 0x91, 0x8d, 0xb8, 0xe8, 0x56, 0x2c, 0xba, 0xfa } }
#define EFI_BOOT_MANAGER_POLICY_NETWORK_GUID { 0xd04159dc, 0xe15f, 0x11e3, { 0xb2, 0x61, 0xb8, 0xe8, 0x56, 0x2c, 0xba, 0xfa } }
#define EFI_BOOT_MANAGER_POLICY_CONNECT_ALL_GUID { 0x113b2126, 0xfc8a, 0x11e3, { 0xbd, 0x6c, 0xb8, 0xe8, 0x56, 0x2c, 0xba, 0xfa } }

#define EFI_GLOBAL_VARIABLE { 0x8be4df61, 0x93ca, 0x11d2, { 0xaa, 0x0d, 0x00, 0xe0, 0x98, 0x03, 0x2b, 0x8c } }


/**
  * EFI System Table
  **/
typedef struct _EFI_TABLE_HEADER {
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
} EFI_TABLE_HEADER;

#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249
#define EFI_2_90_SYSTEM_TABLE_REVISION ((2<<16) | (90))
#define EFI_2_80_SYSTEM_TABLE_REVISION ((2<<16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION ((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2<<16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION ((2<<16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1<<16) | (02))
#define EFI_SPECIFICATION_VERSION EFI_SYSTEM_TABLE_REVISION
#define EFI_SYSTEM_TABLE_REVISION EFI_2_90_SYSTEM_TABLE_REVISION

typedef struct {
    EFI_TABLE_HEADER Hdr;
    EFI_GET_TIME GetTime;
    EFI_SET_TIME SetTime;
    EFI_GET_WAKEUP_TIME GetWakeupTime;
    EFI_SET_WAKEUP_TIME SetWakeupTime;
    EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
    EFI_CONVERT_POINTER ConvertPointer;
    EFI_GET_VARIABLE GetVariable;
    EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
    EFI_SET_VARIABLE SetVariable;
    EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
    EFI_RESET_SYSTEM ResetSystem;
    EFI_UPDATE_CAPSULE UpdateCapsule;
    EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;
    EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
} EFI_RUNTIME_SERVICES;

#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION EFI_SPECIFICATION_VERSION

typedef struct {
    EFI_TABLE_HEADER Hdr;
    EFI_RAISE_TPL RaiseTPL;
    EFI_RESTORE_TPL RestoreTPL;
    EFI_ALLOCATE_PAGES AllocatePages;
    EFI_FREE_PAGES FreePages;
    EFI_GET_MEMORY_MAP GetMemoryMap;
    EFI_ALLOCATE_POOL AllocatePool;
    EFI_FREE_POOL FreePool;
    EFI_CREATE_EVENT CreateEvent;
    EFI_SET_TIMER SetTimer;
    EFI_WAIT_FOR_EVENT WaitForEvent;
    EFI_SIGNAL_EVENT SignalEvent;
    EFI_CLOSE_EVENT CloseEvent;
    EFI_CHECK_EVENT CheckEvent;
    EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;
    EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface;
    EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface;
    EFI_HANDLE_PROTOCOL HandleProtocol;
    VOID* Reserved;
    EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify;
    EFI_LOCATE_HANDLE LocateHandle;
    EFI_LOCATE_DEVICE_PATH LocateDevicePath;
    EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable;
    EFI_IMAGE_LOAD LoadImage;
    EFI_IMAGE_START StartImage;
    EFI_EXIT Exit;
    EFI_IMAGE_UNLOAD UnloadImage;
    EFI_EXIT_BOOT_SERVICES ExitBootServices;
    EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount;
    EFI_STALL Stall;
    EFI_SET_WATCHDOG_TIMER SetWatchdogTimer;
    EFI_CONNECT_CONTROLLER ConnectController;
    EFI_DISCONNECT_CONTROLLER DisconnectController;
    EFI_OPEN_PROTOCOL OpenProtocol;
    EFI_CLOSE_PROTOCOL CloseProtocol;
    EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation;
    EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle;
    EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer;
    EFI_LOCATE_PROTOCOL LocateProtocol;
    EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces;
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces;
    EFI_COPY_MEM CopyMem;
    EFI_SET_MEM SetMem;
    EFI_CREATE_EVENT_EX CreateEventEx;
} EFI_BOOT_SERVICES;

typedef struct {
    EFI_GUID VendorGuid;
    VOID *VendorTable;
} EFI_CONFIGURATION_TABLE;

typedef struct {
    EFI_TABLE_HEADER Hdr;
    CHAR16 *FirmwareVendor;
    UINT32 FirmwareRevision;
    EFI_HANDLE ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
    EFI_RUNTIME_SERVICES *RuntimeServices;
    EFI_BOOT_SERVICES *BootServices;
    UINTN NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE *ConfigurationTable;
} EFI_SYSTEM_TABLE;

#define ACPI_TABLE_GUID { 0xeb9d2d30, 0x2d88, 0x11d3, { 0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }
#define SAL_SYSTEM_TABLE_GUID { 0xeb9d2d32, 0x2d88, 0x11d3, { 0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }
#define SMBIOS_TABLE_GUID { 0xeb9d2d31, 0x2d88, 0x11d3, { 0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }
#define SMBIOS3_TABLE_GUID { 0xf2fd1544,  0x9794,  0x4a2c, { 0x99, 0x2e, 0xe5, 0xbb, 0xcf, 0x20, 0xe3, 0x94 } }
#define MPS_TABLE_GUID { 0xeb9d2d2f, 0x2d88, 0x11d3, { 0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }
#define EFI_ACPI_TABLE_GUID { 0x8868e871, 0xe4f1, 0x11d3, { 0xbc, 0x22, 0x00, 0x80, 0xc7, 0x3c, 0x88, 0x81 } }
#define EFI_ACPI_20_TABLE_GUID EFI_ACPI_TABLE_GUID
#define ACPI_TABLE_GUID { 0xeb9d2d30, 0x2d88, 0x11d3, { 0x9a, 0x16, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }
#define ACPI_10_TABLE_GUID ACPI_TABLE_GUID
#define EFI_JSON_CONFIG_DATA_TABLE_GUID { 0x87367f87, 0x1119, 0x41ce, { 0xaa, 0xec, 0x8b, 0xe0, 0x11, 0x1f, 0x55, 0x8a } }
#define EFI_JSON_CAPSULE_DATA_TABLE_GUID { 0x35e7a725, 0x8dd2, 0x4cac, { 0x80, 0x11, 0x33, 0xcd, 0xa8, 0x10, 0x90, 0x56 } }
#define EFI_JSON_CAPSULE_RESULT_TABLE_GUID { 0xdbc461c3, 0xb3de, 0x422a, { 0xb9, 0xb4, 0x98, 0x86, 0xfd, 0x49, 0xa1, 0xe5 } }

#define EFI_RT_PROPERTIES_TABLE_GUID { 0xeb66918a, 0x7eef, 0x402a, { 0x84, 0x2e, 0x93, 0x1d, 0x21, 0xc3, 0x8a, 0xe9 } }

typedef struct {
    UINT16 Version;
    UINT16 Length;
    UINT32 RuntimeServicesSupported;
} EFI_RT_PROPERTIES_TABLE;

#define EFI_RT_PROPERTIES_TABLE_VERSION 0x1

#define EFI_RT_SUPPORTED_GET_TIME 0x0001
#define EFI_RT_SUPPORTED_SET_TIME 0x0002
#define EFI_RT_SUPPORTED_GET_WAKEUP_TIME 0x0004
#define EFI_RT_SUPPORTED_SET_WAKEUP_TIME 0x0008
#define EFI_RT_SUPPORTED_GET_VARIABLE 0x0010
#define EFI_RT_SUPPORTED_GET_NEXT_VARIABLE_NAME 0x0020
#define EFI_RT_SUPPORTED_SET_VARIABLE 0x0040
#define EFI_RT_SUPPORTED_SET_VIRTUAL_ADDRESS_MAP 0x0080
#define EFI_RT_SUPPORTED_CONVERT_POINTER 0x0100
#define EFI_RT_SUPPORTED_GET_NEXT_HIGH_MONOTONIC_COUNT 0x0200
#define EFI_RT_SUPPORTED_RESET_SYSTEM 0x0400
#define EFI_RT_SUPPORTED_UPDATE_CAPSULE 0x0800
#define EFI_RT_SUPPORTED_QUERY_CAPSULE_CAPABILITIES 0x1000
#define EFI_RT_SUPPORTED_QUERY_VARIABLE_INFO 0x2000

#define EFI_MEMORY_ATTRIBUTES_TABLE_GUID { 0xdcfa911d, 0x26eb, 0x469f, {0xa2, 0x20, 0x38, 0xb7, 0xdc, 0x46, 0x12, 0x20 } }

typedef struct {
    UINT32 Version ;
    UINT32 NumberOfEntries ;
    UINT32 DescriptorSize ;
    UINT32 Reserved;
    // EFI_MEMORY_DESCRIPTOR Entry [1];
} EFI_MEMORY_ATTRIBUTES_TABLE;

#define EFI_LOADED_IMAGE_PROTOCOL_GUID { 0x5b1b31a1, 0x9562, 0x11d2, { 0x8e, 0x3f, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }
#define EFI_LOADED_IMAGE_PROTOCOL_REVISION 0x1000

typedef struct {
    UINT32 Revision;
    EFI_HANDLE ParentHandle;
    EFI_SYSTEM_TABLE *SystemTable;
    EFI_HANDLE DeviceHandle;
    EFI_DEVICE_PATH_PROTOCOL *FilePath;
    VOID *Reserved;
    UINT32 LoadOptionsSize;
    VOID *LoadOptions;
    VOID *ImageBase;
    UINT64 ImageSize;
    EFI_MEMORY_TYPE ImageCodeType;
    EFI_MEMORY_TYPE ImageDataType;
    EFI_IMAGE_UNLOAD Unload;
} EFI_LOADED_IMAGE_PROTOCOL;

#define EFI_LOADED_IMAGE_DEVICE_PATH_PROTOCOL_GUID { 0xbc62157e, 0x3e33, 0x4fec, { 0x99, 0x20, 0x2d, 0x3b, 0x36, 0xd7, 0x50, 0xdf } }

#define EFI_DECOMPRESS_PROTOCOL_GUID { 0xd8117cfe, 0x94a6, 0x11d4, { 0x9a, 0x3a, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }

typedef struct _EFI_DECOMPRESS_PROTOCOL EFI_DECOMPRESS_PROTOCOL;

typedef EFI_STATUS (EFIAPI *EFI_DECOMPRESS_GET_INFO) ( IN EFI_DECOMPRESS_PROTOCOL *This, IN VOID *Source, IN UINT32 SourceSize, OUT UINT32 *DestinationSize, OUT UINT32 *ScratchSize );
typedef EFI_STATUS (EFIAPI *EFI_DECOMPRESS_DECOMPRESS) ( IN EFI_DECOMPRESS_PROTOCOL *This, IN VOID *Source, IN UINT32 SourceSize, IN OUT VOID *Destination, IN UINT32 DestinationSize, IN OUT VOID *Scratch, IN UINT32 ScratchSize );

typedef struct _EFI_DECOMPRESS_PROTOCOL {
    EFI_DECOMPRESS_GET_INFO GetInfo;
    EFI_DECOMPRESS_DECOMPRESS Decompress;
} EFI_DECOMPRESS_PROTOCOL;

#define EFI_DEVICE_PATH_UTILITIES_PROTOCOL_GUID { 0x379be4e, 0xd706, 0x437d, { 0xb0, 0x37, 0xed, 0xb8, 0x2f, 0xb7, 0x72, 0xa4 } }

typedef UINTN (EFIAPI *EFI_DEVICE_PATH_UTILS_GET_DEVICE_PATH_SIZE) ( IN CONST EFI_DEVICE_PATH_PROTOCOL *DevicePath );
typedef EFI_DEVICE_PATH_PROTOCOL* (EFIAPI *EFI_DEVICE_PATH_UTILS_DUP_DEVICE_PATH) ( IN CONST EFI_DEVICE_PATH_PROTOCOL *DevicePath );
typedef EFI_DEVICE_PATH_PROTOCOL* (EFIAPI *EFI_DEVICE_PATH_UTILS_APPEND_PATH) ( IN CONST EFI_DEVICE_PATH_PROTOCOL *Src1, IN CONST EFI_DEVICE_PATH_PROTOCOL *Src2 );
typedef EFI_DEVICE_PATH_PROTOCOL* (EFIAPI *EFI_DEVICE_PATH_UTILS_APPEND_NODE) ( IN CONST EFI_DEVICE_PATH_PROTOCOL *DevicePath, IN CONST EFI_DEVICE_PATH_PROTOCOL *DeviceNode );
typedef EFI_DEVICE_PATH_PROTOCOL* (EFIAPI *EFI_DEVICE_PATH_UTILS_APPEND_INSTANCE) ( IN CONST EFI_DEVICE_PATH_PROTOCOL *DevicePath, IN CONST EFI_DEVICE_PATH_PROTOCOL *DevicePathInstance );
typedef EFI_DEVICE_PATH_PROTOCOL* (EFIAPI *EFI_DEVICE_PATH_UTILS_GET_NEXT_INSTANCE) ( IN OUT EFI_DEVICE_PATH_PROTOCOL **DevicePathInstance, OUT UINTN *DevicePathInstanceSize OPTIONAL );
typedef BOOLEAN (EFIAPI *EFI_DEVICE_PATH_UTILS_IS_MULTI_INSTANCE) ( IN CONST EFI_DEVICE_PATH_PROTOCOL *DevicePath );
typedef EFI_DEVICE_PATH_PROTOCOL* (EFIAPI *EFI_DEVICE_PATH_UTILS_CREATE_NODE) ( IN UINT8 NodeType, IN UINT8 NodeSubType, IN UINT16 NodeLength );

typedef struct _EFI_DEVICE_PATH_UTILITIES_PROTOCOL {
    EFI_DEVICE_PATH_UTILS_GET_DEVICE_PATH_SIZE GetDevicePathSize;
    EFI_DEVICE_PATH_UTILS_DUP_DEVICE_PATH DuplicateDevicePath;
    EFI_DEVICE_PATH_UTILS_APPEND_PATH AppendDevicePath;
    EFI_DEVICE_PATH_UTILS_APPEND_NODE AppendDeviceNode;
    EFI_DEVICE_PATH_UTILS_APPEND_INSTANCE AppendDevicePathInstance;
    EFI_DEVICE_PATH_UTILS_GET_NEXT_INSTANCE GetNextDevicePathInstance;
    EFI_DEVICE_PATH_UTILS_IS_MULTI_INSTANCE IsDevicePathMultiInstance;
    EFI_DEVICE_PATH_UTILS_CREATE_NODE CreateDeviceNode;
} EFI_DEVICE_PATH_UTILITIES_PROTOCOL;


/**
  * Status Codes
  **/
#define EFI_SUCCESS 0
#define EFI_LOAD_ERROR 1
#define EFI_INVALID_PARAMETER 2
#define EFI_UNSUPPORTED 3
#define EFI_BAD_BUFFER_SIZE 4
#define EFI_BUFFER_TOO_SMALL 5
#define EFI_NOT_READY 6
#define EFI_DEVICE_ERROR 7
#define EFI_WRITE_PROTECTED 8
#define EFI_OUT_OF_RESOURCES 9
#define EFI_VOLUME_CORRUPTED 10
#define EFI_VOLUME_FULL 11
#define EFI_NO_MEDIA 12
#define EFI_MEDIA_CHANGED 13
#define EFI_NOT_FOUND 14
#define EFI_ACCESS_DENIED 15
#define EFI_NO_RESPONSE 16
#define EFI_NO_MAPPING 17
#define EFI_TIMEOUT 18
#define EFI_NOT_STARTED 19
#define EFI_ALREADY_STARTED 20
#define EFI_ABORTED 21
#define EFI_ICMP_ERROR 22
#define EFI_TFTP_ERROR 23
#define EFI_PROTOCOL_ERROR 24
#define EFI_INCOMPATIBLE_VERSION 25
#define EFI_SECURITY_VIOLATION 26
#define EFI_CRC_ERROR 27
#define EFI_END_OF_MEDIA 28
#define EFI_END_OF_FILE 31
#define EFI_INVALID_LANGUAGE 32
#define EFI_COMPROMISED_DATA 33
#define EFI_IP_ADDRESS_CONFLICT 34
#define EFI_HTTP_ERROR 35

#define EFI_WARN_UNKNOWN_GLYPH 1
#define EFI_WARN_DELETE_FAILURE 2
#define EFI_WARN_WRITE_FAILURE 3
#define EFI_WARN_BUFFER_TOO_SMALL 4
#define EFI_WARN_STALE_DATA 5
#define EFI_WARN_FILE_SYSTEM 6
#define EFI_WARN_RESET_REQUIRED 7
