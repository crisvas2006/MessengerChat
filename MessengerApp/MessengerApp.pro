QT += qml quick
QT += network widgets
CONFIG += c++11

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =



# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/broadcastreceiver
INSTALLS += target

HEADERS       += sender.h
HEADERS       += receiver.h

SOURCES       = sender.cpp \
                main.cpp \ receiver.cpp

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    UsersView.qml \
    MessageView.qml

# install
#target.path = $$[QT_INSTALL_EXAMPLES]/network/broadcastsender
#INSTALLS += target
