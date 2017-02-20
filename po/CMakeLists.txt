project(qtubuntu-print-translations)

include(FindGettext)
find_program(GETTEXT_XGETTEXT_EXECUTABLE xgettext)

set(DOMAIN ${GETTEXT_PACKAGE})
set(POT_FILE ${DOMAIN}.pot)
file(GLOB PO_FILES *.po)

file(GLOB I18N_SRC_FILES
    RELATIVE ${CMAKE_SOURCE_DIR}
    ${SRC_SOURCE_DIR}/*.h ${SRC_SOURCE_DIR}/*.cpp)

add_custom_target(${POT_FILE} ALL
                  COMMAND touch ${POT_FILE}
                  COMMAND ${GETTEXT_XGETTEXT_EXECUTABLE} -o ${POT_FILE}
                          -D ${CMAKE_SOURCE_DIR}
                          --from-code=UTF-8
                          --c++ --qt --add-comments=TRANSLATORS
                          --keyword=__
                          -j
                          --package-name=qtubuntu-print
                          --copyright-holder='Canonical Ltd.'
                          ${I18N_SRC_FILES}
                  COMMAND ${CMAKE_COMMAND} -E copy ${POT_FILE} ${CMAKE_CURRENT_SOURCE_DIR})

foreach(PO_FILE ${PO_FILES})
    get_filename_component(LANG ${PO_FILE} NAME_WE)
    gettext_process_po_files(${LANG} ALL PO_FILES ${PO_FILE})
    set(INSTALL_DIR ${CMAKE_INSTALL_LOCALEDIR}/${LANG}/LC_MESSAGES)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${LANG}.gmo
            DESTINATION ${INSTALL_DIR}
            RENAME ${DOMAIN}.mo)
endforeach(PO_FILE)

# Show .pot in QtC
add_custom_target(qtubuntu_print_qtc_pot_files SOURCES ${POT_FILE})
