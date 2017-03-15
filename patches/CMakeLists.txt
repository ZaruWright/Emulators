
message (${CMAKE_CURRENT_SOURCE_DIR})
add_custom_target( sfmlPatch ALL
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND /bin/sh ${CMAKE_CURRENT_SOURCE_DIR}/patchSFML.sh
    COMMENT "Patch SFML project. Fixing hidden symbol `__cpu_model' error"
    )