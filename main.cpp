#include "src/API/AddToFavoriteList/AddToFavoriteList.h"
#include "src/API/RemoveFromFavoriteList/RemoveFromFavoriteList.h"
#include "src/Data/Data.h"
#include "src/GUI/MainWindow/MainWindow.h"
#include "src/GlobalVar/GlobalVar.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    AddToFavoriteList(L"Ahihi");
    removeFromFavoriteList(L"Hello");
    return app.exec();
}
