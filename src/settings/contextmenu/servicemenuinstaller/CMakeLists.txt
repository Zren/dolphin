remove_definitions(-DTRANSLATION_DOMAIN=\"dolphin\")
add_definitions(-DTRANSLATION_DOMAIN=\"dolphin_servicemenuinstaller\")

add_executable(servicemenuinstaller servicemenuinstaller.cpp)
target_link_libraries(servicemenuinstaller PRIVATE
    Qt5::Core
    Qt5::Gui
    KF5::I18n
    KF5::CoreAddons
)

if(HAVE_PACKAGEKIT)
    target_link_libraries(servicemenuinstaller PRIVATE PK::packagekitqt5)
endif()
install(TARGETS servicemenuinstaller ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
