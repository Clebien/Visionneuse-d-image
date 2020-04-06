#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QMainWindow>
#include <QtWidgets>

class MaFenetre : public QMainWindow
{
    Q_OBJECT
private:

    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAffichage;

    QAction *actionDossier;
    QAction *actionQuitter;
    QAction *actionSuivant;
    QAction *actionPrecedent;
    QAction *actionAgrandir;
    QAction *actionReduire;
    QAction *actionRotateD;
    QAction *actionRotateG;
    QAction *actionSupprimer;
    QAction *actionDiaporama;
    QAction *actionRenomer;
    QAction *actionDeplacer;
    QAction *actionStop;

    QToolBar *toolBarQuitter;
    QToolBar *toolBarDossier;
    QToolBar *toolBarAgrandir;
    QToolBar *toolBarReduire;
    QToolBar *toolBarSuivant;
    QToolBar *toolBarPrecedent;
    QToolBar *toolBarRotateD;
    QToolBar *toolBarRotateG;
    QToolBar *toolBarSupprimer;
    QToolBar *toolBarDiaporama;
    QToolBar *toolBarRenommer;
    QToolBar *toolBarDeplacer;
    QToolBar *toolBarStop;

    QStringList fileList; // Variable qui contiendra tous les fichiers correspondant à notre recherche
    int i;
    int finlist;

    QLabel *labelimage; //Label contenant l'image
    QWidget *zoneAffichage;
    QGridLayout *grid;
    int hauteur;
    int largeur;
    QString repertoire;
    QTimer *timer;


public:
    MaFenetre();



public slots:
    void ouvrirDossier();
    void suivant();
    void precedent();
    void rotationD();
    void rotationG();
    void diaporama();
    void redimensionner();
    void agrandir();
    void reduire();
    void supprimer();
    void fichierImage();
    void deplacer();
    void renommer();
    void stopdiapo();

};

#endif // MAFENETRE_H
