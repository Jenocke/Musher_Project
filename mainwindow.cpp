#include "mainwindow.h"

MainWindow::MainWindow()
{
        //création du SDI
    centralZone = new QWidget;
    setCentralWidget(centralZone);
        //création du menu
    generateMenu();

        //affichage menu principal
    generateMainMenu();
    centralZone->setLayout(mainMenuLayout);

    //connection des actions aux slots
        connect(actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
        connect(buttonQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MainWindow::generateMenu()
{
    //Création des menus
       filesMenu = menuBar()->addMenu("&Fichier");
       displayMenu = menuBar()->addMenu("&Affichage");
       optionMenu = menuBar()->addMenu("&Options");

    //création des sous-menus

    //création des actions
       actionNewMusher = new QAction("Inscrire un nouveau Musher", this);
       actionNewDogTeam = new QAction("Ajouter un nouvel attelage", this);
       actionQuit = new QAction("&Quitter", this);
       actionListing = new QAction("Afficher la liste", this);
       actionPreference = new QAction("Préférences", this);
    //Création des shortcuts
       actionNewMusher->setShortcut(QKeySequence("Ctrl+M"));
       actionNewDogTeam->setShortcut(QKeySequence("Ctrl+A"));
       actionListing->setShortcut(QKeySequence("Ctrl+L"));
       actionQuit->setShortcut(QKeySequence("Ctrl+Q"));
       actionPreference->setShortcut(QKeySequence("Ctrl+O"));

    //Création des icônes
       actionQuit->setIcon(QIcon("quitter.png"));
    //ajout des actions dans les menus & sous-menus
       filesMenu->addAction(actionNewMusher);
       filesMenu->addAction(actionNewDogTeam);
       filesMenu->addAction(actionQuit);

       displayMenu->addAction(actionListing);

       optionMenu->addAction(actionPreference);


}


void MainWindow::generateMainMenu()
{
    mainMenuLayout = new QVBoxLayout();

    buttonAddMusher = new QPushButton("Ajouter Musher");
    buttonAddDogTeam = new QPushButton("Ajouter Attelage");
    buttonDisplayListing = new QPushButton("Afficher le listing");
    buttonQuit = new QPushButton("Quitter");


    mainMenuLayout->addWidget(buttonAddMusher);
    mainMenuLayout->addWidget(buttonAddDogTeam);
    mainMenuLayout->addWidget(buttonDisplayListing);
    mainMenuLayout->addWidget(buttonQuit);


}