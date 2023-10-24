TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Elektroartikel.cpp \
        datum.cpp \
        lagerverwaltung.cpp \
        main.cpp \
        verbrauchsmaterial.cpp \
        warengruppe.cpp

HEADERS += \
    Elektroartikel.h \
    datum.h \
    lagerverwaltung.h \
    verbrauchsmaterial.h \
    warengruppe.h
