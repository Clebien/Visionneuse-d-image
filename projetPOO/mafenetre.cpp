#include <QtWidgets>
#include "mafenetre.h"

MaFenetre::MaFenetre()
{
    // creation du menu

    menuFichier = menuBar()->addMenu("&Fichier");
    menuEdition = menuBar()->addMenu("&Edition");
    menuAffichage = menuBar()->addMenu("&Affichage");

    // la barre d'outils

    toolBarQuitter = addToolBar("Quitter");
    toolBarDossier = addToolBar("Ouvrir un dossier");
    toolBarDiaporama = addToolBar("Diaporama");
    toolBarAgrandir = addToolBar("zoom+");
    toolBarReduire= addToolBar("zoom-");
    toolBarPrecedent = addToolBar("Pécédent");
    toolBarSuivant = addToolBar("Suivant");
    toolBarRotateD = addToolBar("Rotation droite");
    toolBarRotateG = addToolBar("Rotation gauche");
    toolBarSupprimer = addToolBar("Supprimer");
    toolBarRenommer = addToolBar("Renommer");
    toolBarDeplacer = addToolBar("Deplacer");
    toolBarStop = addToolBar("Stop");

    // definition des QActions qui joueront le roles des boutons

    actionDossier = new QAction("&Ouvrir un dossier",this);
    actionDiaporama = new QAction("&Diaporama",this);
    actionQuitter = new QAction("&Quitter",this);
    actionSuivant = new QAction("&Suivant",this);
    actionPrecedent = new QAction("&Précédent",this);
    actionAgrandir = new QAction("&Zoom+",this);
    actionReduire = new QAction("&Zoom-",this);
    actionRotateD = new QAction ("&rotation droite",this);
    actionRotateG = new QAction ("&rotation gauche",this);
    actionSupprimer = new QAction ("&Supprimer",this);
    actionRenomer = new QAction("&Renommer",this);
    actionDeplacer = new QAction("&Deplacer",this);
    actionStop = new QAction("&Stop",this);

    // Ajout des QActions au menu

    menuFichier->addAction(actionDossier);
    menuFichier->addAction(actionQuitter);
    menuEdition->addAction(actionSupprimer);
    menuEdition->addAction(actionRenomer);
    menuEdition->addAction(actionDeplacer);
    menuAffichage->addAction(actionDiaporama);
    menuAffichage->addAction(actionAgrandir);
    menuAffichage->addAction(actionReduire);
    menuAffichage->addAction(actionRotateD);
    menuAffichage->addAction(actionRotateG);
    menuAffichage->addAction(actionSuivant);
    menuAffichage->addAction(actionPrecedent);

    // Ajout des QAction à la barre d'outils

    toolBarDossier->addAction(actionDossier);
    toolBarQuitter->addAction(actionQuitter);
    toolBarDiaporama->addAction(actionDiaporama);
    toolBarAgrandir->addAction(actionAgrandir);
    toolBarReduire->addAction(actionReduire);
    toolBarPrecedent->addAction(actionPrecedent);
    toolBarSuivant->addAction(actionSuivant);
    toolBarRotateD->addAction(actionRotateD);
    toolBarRotateG->addAction(actionRotateG);
    toolBarSupprimer->addAction(actionSupprimer);
    toolBarRenommer->addAction(actionRenomer);
    toolBarDeplacer->addAction(actionDeplacer);
    toolBarStop->addAction(actionStop);

    // Ajout d'icône et de text sur les QActions (personnalisation des QAction)

    actionDossier->setIcon(QIcon("Open.png"));
    actionQuitter->setIcon(QIcon("quitter.png"));
    actionDiaporama->setIcon(QIcon("diaporama.jpg"));
    actionAgrandir->setIcon(QIcon("zoom+.png"));
    actionReduire->setIcon(QIcon("zoom-.png"));
    actionPrecedent->setIcon(QIcon("precedent.png"));
    actionSuivant->setIcon(QIcon("suivant.png"));
    actionRotateD->setIcon(QIcon("droite.png"));
    actionRotateG->setIcon(QIcon("gauche.png"));
    actionSupprimer->setIcon(QIcon("supprimer.png"));
    //actionDeplacer->setIcon(QIcon("deplacer.jpg"));
    actionRenomer->setText("Renommer");
    actionDeplacer->setText("Deplacer");
    actionStop->setText("Stop diaporama");

    // Connection des slots (fonctions) aux differents QActions

    connect(actionQuitter,SIGNAL(triggered()), qApp,SLOT(quit()));
    connect(actionDossier,SIGNAL(triggered()),this,SLOT(ouvrirDossier()));
    connect(actionDiaporama,SIGNAL(triggered()),this,SLOT(diaporama()));
    connect(actionSuivant,SIGNAL(triggered()),this,SLOT(suivant()));
    connect(actionPrecedent,SIGNAL(triggered()),this,SLOT(precedent()));
    connect(actionRotateD,SIGNAL(triggered()),this,SLOT(rotationD()));
    connect(actionRotateG,SIGNAL(triggered()),this,SLOT(rotationG()));
    connect(actionSupprimer,SIGNAL(triggered()),this,SLOT(supprimer()));
    connect(actionRenomer,SIGNAL(triggered()),this,SLOT(renommer()));
    connect(actionDeplacer,SIGNAL(triggered()),this,SLOT(deplacer()));
    connect(actionReduire,SIGNAL(triggered()),this,SLOT(reduire()));
    connect(actionAgrandir,SIGNAL(triggered()),this,SLOT(agrandir()));
    connect(actionStop,SIGNAL(triggered()),this,SLOT(stopdiapo()));








    resize(QGuiApplication::primaryScreen()->availableSize()*2/4); // donne une taille par defaut à la fenetre à son ouverture


    //********************************************************************
     labelimage = new QLabel(this);
     grid = new QGridLayout(this);
     grid->addWidget(labelimage,0,0);
     zoneAffichage = new QWidget;
     setCentralWidget(zoneAffichage);
     zoneAffichage->setFixedSize(1200,600); // on fixe la taille de la zone d'affichage
     zoneAffichage->setLayout(grid);
     timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(suivant()));

}


void MaFenetre::supprimer()
{

    QFile file(fileList[i]); // On référence l'objet file au fichier
    if(file.exists())
    {
        int choix = QMessageBox::question(this, "Supprimer", "Supprimer?", QMessageBox::Yes | QMessageBox::No);
        if(choix==QMessageBox::Yes)
        {
                // Efface l'image affiché à l'ecran et affiche l'image suivant

                file.remove();
                fileList[i]=fileList[i+1];
                if(finlist!=0)
                 fichierImage();

        }
    }
}
void MaFenetre::ouvrirDossier()
{
    i=0;
    finlist=0;

    // On sélectionne le répertoire à partir duquel on va rechercher les fichiers image
    repertoire = QFileDialog::getExistingDirectory(this,tr("Ouvrir un répertoire"),"",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(repertoire!="") { fichierImage();}
     redimensionner();
}

void MaFenetre::fichierImage()
{
    QStringList listFilter;

    // On remplit une QStringList avec chacun des filtres désirés ici "*.png *.gif *.jpg *.jpeg".
    listFilter << "*.png";
    listFilter << "*.gif";
    listFilter << "*.jpeg";
    listFilter << "*.jpg";

    // On déclare un QDirIterator dans lequel on indique que l'on souhaite parcourir un répertoire et ses sous-répertoires.
    // De plus, on spécifie le filtre qui nous permettra de récupérer uniquement les fichiers du type souhaité.
    QDirIterator dirIterator(repertoire,listFilter ,QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);

    // Tant qu'on n'est pas arrivé à la fin de l'arborescence...
    while(dirIterator.hasNext())
    {
        // ...on va au prochain fichier correspondant à notre filtre
        fileList << dirIterator.next();
        finlist++;
    }
    labelimage->setPixmap(QPixmap(fileList[i])); // on affiche l'image d'indice i=0 soit le premier image de la liste(fileList)
}

void MaFenetre::diaporama()
{
        timer->start(2000);

}

void MaFenetre::suivant()
{

    if(i!=finlist)
    {
        i++;
       labelimage->setPixmap(QPixmap(fileList[i]));

    }
    fichierImage(); // on revient à la première image a la fin

}

void MaFenetre::precedent()
{

    if(i!=0)
    {
        i--;
        labelimage->setPixmap(QPixmap(fileList[i]));

    }
     fichierImage(); // On reste sur la premiere image si le pointeur est sur elle

}
void MaFenetre::rotationD()
{
    if(fileList[i]!="")
        {
            largeur=labelimage->pixmap()->width();
            hauteur=labelimage->pixmap()->height();

            QPixmap pixmap(*labelimage->pixmap());
            QMatrix rotation;
            rotation.rotate(90);
            pixmap = pixmap.transformed(rotation);
            pixmap.scaled(801, 701);
            labelimage->setPixmap(pixmap);
            redimensionner();
        }
}
void MaFenetre::rotationG()
{
    if(fileList[i]!="")
        {
            QPixmap pixmap(*labelimage->pixmap());
            QMatrix rotation;
            rotation.rotate(-90);
            pixmap = pixmap.transformed(rotation);
            pixmap.scaled(801, 701);
            labelimage->setPixmap(pixmap);
            redimensionner();

        }
}

void MaFenetre::reduire()
{
    labelimage->resize(labelimage->width()*2/3,labelimage->height()*2/3); //on reduire les dimensions du label qui contient l'image
}
void MaFenetre::agrandir()
{

    labelimage->resize(labelimage->width()*3/2,labelimage->height()*3/2);//on augmente les dimensions du label qui contient l'image
}

/* cette fonction permet d'adapter les dimentions de l'image à la zone d'affichage dès l'ouverture du dossier il sera appeler
  plus haut dans la fonction ouvrirDossier() */

void MaFenetre::redimensionner()
{

    if(largeur>1150 || hauteur>600)
        {
        // Lorsque cette option est activée(true) et que l'étiquette affiche un pixmap, le pixmap sera mis à l'echelle pour remplir l'espace disponible( s'adapte à la taille du label)
            labelimage->setScaledContents(true); // true si les dimensions de l'image respectent la condition sinon on corrige les dimensions
            if(largeur>1150 && hauteur>600)  labelimage->setGeometry(25,100,1150,600);
            else if(largeur<=1150 && hauteur>600)  labelimage->setGeometry((1200/2)-(largeur/2),100,largeur,600);
            else if(largeur>1150 && hauteur<=600)  labelimage->setGeometry(25,(900/2)-(hauteur/2),1150,hauteur);
        }
        else
        {
             labelimage->setScaledContents(false);
            labelimage->setGeometry((1200-largeur)/2,(900-hauteur)/2,largeur,hauteur);
        }
}

void MaFenetre::renommer()
{
    if(fileList[i]!="")
    {
        QString chemin = QFileInfo(fileList[i]).absolutePath(); //Permet de recuperer le chemin d'acces a l'image
        QString extension = QFileInfo(fileList[i]).suffix(); //Permet de recuperer l'extension de l'image
        QString nouveauNom = "";// La variable qui contiendra le nouveau nom, on l'initialise à vide
        nouveauNom = QInputDialog::getText(this, "Changer nom", "Renommer ?"); //Nouveau nom de l'image
        if(nouveauNom!="")
        {
            QMessageBox::information(this, "Fichier renommé","Fichier renommé en : " + nouveauNom + "." + extension);// Affiche le nouveau nom du fichier
            nouveauNom=chemin+"/"+nouveauNom+"."+extension; // sauvegarde le fichier renommer afin de ne pas le perdre
            QFile::rename(fileList[i],nouveauNom); // Applique le nouveau nom sur le fichier
        }
    }
}
void MaFenetre::deplacer()
{
    if(fileList[i]!="")
    {
        QFile file(fileList[i]); // On référence l'objet file au fichier

        QString str = file.fileName();

        QStringList parts = str.split("/");
        QString nom = parts.at(parts.size()-1);

        QString nouveauNom = "";

        nouveauNom = QFileDialog::getExistingDirectory(this,tr("Ouvrir un répertoire"),"",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
        nom=nouveauNom+"/"+nom;
        if(nouveauNom=="") {}
        else
        {
            if(fileList[i]==nom) QMessageBox::information(this, "Erreur","veuillez choisir un dossier différent");
            else
            {
                QMessageBox::information(this, "déplacer","Fichier déplacé dans: " + fileList[i]);
                QFile::rename(fileList[i],nom);
                fileList[i]=nom;
            }
        }
    }
}

void MaFenetre::stopdiapo()
{
    if(i) timer->stop();
}
