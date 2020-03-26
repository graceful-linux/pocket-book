TEMPLATE = subdirs

CONFIG = ordered \
    qt

SUBDIRS += \
    $$PWD/app/app.pro


OTHER_FILES += \
    $$PWD/LICENSE \
    $$PWD/README.md \
    $$PWD/.gitignore \
    $$PWD/sql/database.sql

QT += widgets
