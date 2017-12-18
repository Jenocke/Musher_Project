#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>


class MainWindow : public QMainWindow
{
    public:
        MainWindow();

    private:
        QWidget *centralZone;

        QMenu *filesMenu;
        QMenu *displayMenu;
        QMenu *optionMenu;

        QAction *actionQuit;
        QAction *actionNewMusher;
        QAction *actionNewDogTeam;
        QAction *actionListing;
        QAction *actionPreference;

        QVBoxLayout *mainMenuLayout;
        QVBoxLayout *musherLayout;
        QVBoxLayout *dogTeamLayout;
        QVBoxLayout *listingLayout;

        QPushButton *buttonAddMusher;
        QPushButton *buttonAddDogTeam;
        QPushButton *buttonDisplayListing;
        QPushButton *buttonQuit;

        void generateMenu();
        void generateMainMenu();
        void generateMusherLayout();
        void generateDogTeamLayout();
        void generateListingLayout();
};





#endif
