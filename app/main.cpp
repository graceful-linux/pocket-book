#include <QApplication>
#include "app.h"

int main (int argc, char* argv[])
{
    QApplication qmain(argc, argv);

    App* app = new App();

    app->show();

    if (!app->canLogin()) {
        goto out;
    }

    qmain.exec();

out:
    if (nullptr != app) {delete app;}

    return 0;
}
