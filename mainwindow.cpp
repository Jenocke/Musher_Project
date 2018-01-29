#include "mainwindow.h"

MainWindow::MainWindow()
{
    this->setFixedHeight(500);
    this->setFixedWidth(500);
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
        connect(actionNewMusher ,SIGNAL(triggered()), this, SLOT(newMusherForm()));
        connect(buttonAddMusher, SIGNAL(clicked()), this, SLOT(newMusherForm()));
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

    mainMenuLayout = new QHBoxLayout();
    mainMenuSubLayout = new QVBoxLayout;

    buttonAddMusher = new QPushButton("Ajouter Musher");
        buttonAddMusher->setFixedWidth(200);
        buttonAddMusher->setFixedHeight(80);
    buttonAddDogTeam = new QPushButton("Ajouter Attelage");
        buttonAddDogTeam->setFixedWidth(200);
        buttonAddDogTeam->setFixedHeight(80);
    buttonDisplayListing = new QPushButton("Afficher le listing");
        buttonDisplayListing->setFixedWidth(200);
        buttonDisplayListing->setFixedHeight(80);
    buttonQuit = new QPushButton("Quitter");
        buttonQuit->setFixedWidth(200);
        buttonQuit->setFixedHeight(80);

    mainMenuSubLayout->addWidget(buttonAddMusher);
    mainMenuSubLayout->addWidget(buttonAddDogTeam);
    mainMenuSubLayout->addWidget(buttonDisplayListing);
    mainMenuSubLayout->addWidget(buttonQuit);

    mainMenuLayout->addLayout(mainMenuSubLayout);
}

void MainWindow::removeLayout (QWidget* widget)
{
    QLayout* layout = widget->layout();
    if (layout != NULL)
    {

        QLayoutItem *item;
        item = layout->takeAt(0);
        QLayout *subLayout = item->layout();
    while ((item = subLayout->takeAt(0)) != NULL)
    {
        delete item->widget();

        layout->removeItem (item);
    }
    delete subLayout;
    delete layout;
    delete item;
    }
}

void MainWindow::newMusherForm()
{

    removeLayout(centralZone);
    generateMusherLayout();
    centralZone->setLayout(musherMainLayout);
}

void MainWindow::generateMusherLayout()
{
    musherMainLayout = new QVBoxLayout();
    musherFormLayout = new QFormLayout();
    champNom = new QLineEdit();
    champPrenom = new QLineEdit();
    labelMandatory = new QLabel();

    subLayoutMusherForm = new QHBoxLayout();
    buttonCancel = new QPushButton("Annuler");
    buttonReset = new QPushButton("Réinitialiser");
    buttonAccept = new QPushButton("OK");
    subLayoutMusherForm->addWidget(buttonCancel);
    subLayoutMusherForm->addWidget(buttonReset);
    subLayoutMusherForm->addWidget(buttonAccept);

    labelMandatory->setText("Les champs précédés d'un * sont obligatoires.");

    musherFormLayout->addRow(labelMandatory);
    musherFormLayout->addRow("* Nom : ", champNom);
    musherFormLayout->addRow("* Prénom : ", champPrenom);

    musherMainLayout->addLayout(musherFormLayout);
    musherMainLayout->addLayout(subLayoutMusherForm);
}
