#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <layoutsformlisting.h>
#include <iostream>


class MainWindow : public QMainWindow
{
    Q_OBJECT

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

        QHBoxLayout *mainMenuLayout;
        QVBoxLayout *mainMenuSubLayout;
        QFormLayout *musherFormLayout;
        QVBoxLayout *dogTeamLayout;
        QVBoxLayout *listingLayout;

        QPushButton *buttonAddMusher;
        QPushButton *buttonAddDogTeam;
        QPushButton *buttonDisplayListing;
        QPushButton *buttonQuit;

        QLineEdit *champNom;
        QLineEdit *champPrenom;
        QLabel *labelMandatory;
        QPushButton *buttonCancel;
        QPushButton *buttonReset;
        QPushButton *buttonAccept;
        QVBoxLayout *musherMainLayout;
        QHBoxLayout *subLayoutMusherForm;

        void generateMenu();
        void generateMainMenu();
        void generateMusherLayout();
        void generateDogTeamLayout();
        void generateListingLayout();
        void removeLayout(QWidget*);



private slots:
            void newMusherForm();
};






#endif
