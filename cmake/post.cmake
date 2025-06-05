# post build
# used to post-process a binary after linking

set(CMAKE_EXECUTABLE_SUFFIX ".elf")

add_custom_command(TARGET
    ${PROJECT_NAME}
    POST_BUILD
    ## Convert ELF to Motorola S-records
    COMMAND
    ${CMAKE_CCRH_LINKER}
    ${PROJECT_NAME}.elf
    -form=stype
    -output=${PROJECT_NAME}.srec
    ## Convert ELF to Raw Binary
    COMMAND
    ${CMAKE_CCRH_LINKER}
    ${PROJECT_NAME}.elf
    -form=binary
    -output=${PROJECT_NAME}.bin
)

