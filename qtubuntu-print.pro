TARGET = qtubuntu-print
TEMPLATE = lib

QT += core-private dbus gui-private printsupport printsupport-private

QMAKE_CXXFLAGS += -std=c++14

target.path += $$[QT_INSTALL_PLUGINS]/printsupport

CONFIG += plugin
INSTALLS += target

DEFINES += "QT_NO_CUPS"

HEADERS += \
    qubuntuprintsupport_p.h \
    qubuntuprintengine_p.h \
    qubuntuprintdevice_p.h

SOURCES += main.cpp \
    qubuntuprintsupport.cpp \
    qubuntuprintengine.cpp \
    qubuntuprintdevice.cpp

DISTFILES += \
    qtubuntu-print.json

OTHER_FILES += qtubuntu-print.json

unix|win32: LIBS += -lcontent-hub
