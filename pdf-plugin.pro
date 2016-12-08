TARGET = pdfsupport
TEMPLATE = lib

QT += dbus printsupport printsupport-private

target.path += $$[QT_INSTALL_PLUGINS]/printsupport

CONFIG += plugin
INSTALLS += target

DEFINES += "QT_NO_CUPS"

HEADERS += \
    qpdfsupport_p.h \
    qpdfengine_p.h \
    qpdfdevice_p.h

SOURCES += main.cpp \
    qpdfsupport.cpp \
    qpdfengine.cpp \
    qpdfdevice.cpp

DISTFILES += \
    pdf.json

OTHER_FILES += pdf.json

unix|win32: LIBS += -lcontent-hub
