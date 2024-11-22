#####
# author: https://github.com/patrislav1/cubemx.cmake
#####
set(OPENOCD_CFG "${CMAKE_SOURCE_DIR}/openocd/openocd.cfg")

if(DEFINED OPENOCD_CFG)
    set(OPENOCD_CFG_OPT -f ${OPENOCD_CFG})
endif()

#####################################
# Reset chip                        #
#####################################
add_custom_target(reset
    openocd ${OPENOCD_CFG_OPT} -c "init" -c "reset" -c "exit"
    COMMENT "Resetting chip"
)

#####################################
# Mass erase chip                   #
#####################################
add_custom_target(erase
    openocd ${OPENOCD_CFG_OPT} -c "init" -c "halt" -c "stm32f1x mass_erase 0" -c "exit"
    COMMENT "Mass erasing chip"
)

#####################################
# Flash target                      #
#####################################
add_custom_target(download
    openocd ${OPENOCD_CFG_OPT} -c "program ${CMAKE_PROJECT_NAME}.elf verify reset exit"
    DEPENDS ${CMAKE_PROJECT_NAME}.elf
    COMMENT "Flashing ${PROJ_NAME}.elf to target"
)