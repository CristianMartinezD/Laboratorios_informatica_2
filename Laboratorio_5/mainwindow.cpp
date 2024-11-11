#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setBackgroundBrush(QBrush(QColor(0, 128, 0)));
    ui->graphicsView->setGeometry(0, 0,width()*0.5,height()*0.5);

    escenaLaberinto = new QGraphicsScene();
    crearLaberinto();
    ui->graphicsView->setScene(escenaLaberinto);

}




int ITEM = 1;
// MÉTODO QUE DETECTA CUANDO SE PRECIONAN TECLAS //
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    int cantidad = 10;
    QPointF previaPos = imagenActual->pos();
    bool TeclaValida = true;

    switch (e->key()) {
    case Qt::Key_D:  // Mover a la derecha
        if (ITEM < 3 || ITEM > 5) ITEM = 3;
        imagenActual->setPos(previaPos.x() + cantidad, previaPos.y());
        if (tocarPared()) {
            imagenActual->setPos(previaPos.x() - cantidad, previaPos.y());
        }
        break;

    case Qt::Key_A:  // Mover a la izquierda
        if (ITEM > 2) ITEM = 0;
        imagenActual->setPos(previaPos.x() - cantidad, previaPos.y());
        if (tocarPared()) {
            imagenActual->setPos(previaPos.x() + cantidad, previaPos.y());
        }
        break;

    case Qt::Key_W:  // Mover hacia arriba
        if (ITEM < 6 || ITEM > 8) ITEM = 6;
        imagenActual->setPos(previaPos.x(), previaPos.y() - cantidad);
        if (tocarPared()) {
            imagenActual->setPos(previaPos.x(), previaPos.y() + cantidad);
        }
        break;

    case Qt::Key_Z:  // Mover hacia abajo
        if (ITEM < 9 || ITEM > 11) ITEM = 9;
        imagenActual->setPos(previaPos.x(), previaPos.y() + cantidad);
        if (tocarPared()) {
            imagenActual->setPos(previaPos.x(), previaPos.y() - cantidad);
        }
        break;

    case Qt::Key_S:{colocarBomba();break;}

    default:
        TeclaValida = false;
        break;
    }

    // actualizar la imagen si la tecla es válida
    if (TeclaValida) {
        spritesBom[ITEM]->setPos(imagenActual->pos());
        escenaLaberinto->removeItem(imagenActual);
        escenaLaberinto->addItem(spritesBom[ITEM]);
        imagenActual = spritesBom[ITEM];
        ++ITEM;
    }
}






void MainWindow::crearLaberinto()
{
    int configLab[11][21] = {
        {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,2,2,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
        {1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    for (int i = 0; i < 11; ++i){
        for (int j = 0; j < 21; ++j){

            if (configLab[i][j] == 1) {
                BloquesSolidos.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/solido.png").scaled(67, 67, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
                BloquesSolidos.back()->setPos(j*67,i*67);
                escenaLaberinto->addItem(BloquesSolidos.back());
            }
            else if(configLab[i][j] == 0){
                if ((QRandomGenerator::global()->bounded(1, 101))%2 == 0){ // Genera un número entre 1 y 100 y le saco %2
                    BloquesDestruibles.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/destruible.png").scaled(67, 67, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
                    BloquesDestruibles.back()->setPos(j*67,i*67);
                    escenaLaberinto->addItem(BloquesDestruibles.back());
                }
            }
            else if(configLab[i][j] == 5){
                escenaLaberinto->addRect(j * 67, i * 67, 67, 77, QPen(Qt::NoPen), QBrush(QColor(101, 67, 33)));
            }
        }
    }

    QGraphicsTextItem *texto1 = escenaLaberinto->addText("CRONOM", QFont("Arial", 20, QFont::Bold));
    texto1->setDefaultTextColor(Qt::white);
    texto1->setPos(80, 18);
    QGraphicsTextItem *texto2 = escenaLaberinto->addText("VIDAS", QFont("Arial", 20, QFont::Bold));
    texto2->setDefaultTextColor(Qt::green);
    texto2->setPos(690, 18);
    QGraphicsTextItem *texto3 = escenaLaberinto->addText("PUNTOS", QFont("Arial", 20, QFont::Bold));
    texto3->setDefaultTextColor(Qt::yellow);
    texto3->setPos(1200, 18);



    // Crear Enemigos
    for (int i = 0; i < 3; ++i) {
        QGraphicsPixmapItem* Enemigo = new QGraphicsPixmapItem();

        QPixmap pixmap(":/imagenes/rueda.png");
        if (i == 0){
            Enemigo->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            Enemigo->setPos(90, 344);
        }
        if (i == 1){
            Enemigo->setPixmap(pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            Enemigo->setPos(950, 210);
        }
        if (i == 2){
            Enemigo->setPixmap(pixmap.scaled(45, 45, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            Enemigo->setPos(745, 267);
        }

        escenaLaberinto->addItem(Enemigo);
        Enemigos.append(Enemigo);
    }


    // Configurar el temporizador para mover los enemigos
    timerEnemigos = new QTimer(this);
    connect(timerEnemigos, &QTimer::timeout, this, &MainWindow::moverEnemigos);
    timerEnemigos->start(50);



    // Cargar los sprites del personaje principal
    spritesBom.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/i0.png").scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    spritesBom.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/i1.png").scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    spritesBom.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/i2.png").scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)));

    spritesBom.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/d0.png").scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    spritesBom.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/d1.png").scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    spritesBom.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/d2.png").scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)));

    spritesBom.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/a0.png").scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    spritesBom.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/a1.png").scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    spritesBom.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/a2.png").scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)));


    spritesBom.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/f0.png").scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    spritesBom.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/f1.png").scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    spritesBom.append(new QGraphicsPixmapItem(QPixmap(":/imagenes/f2.png").scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation)));

    spritesBom[3]->setPos(80,145);
    escenaLaberinto->addItem(spritesBom[3]);
    imagenActual = spritesBom[3];

}






bool MainWindow::tocarPared()
{
    bool tocoLaPared = false;
    for(auto iter = BloquesSolidos.begin(); iter < BloquesSolidos.end(); ++iter){
        if(imagenActual->collidesWithItem(*iter)){
            tocoLaPared = true;
        }
    }
    for(auto iter = BloquesDestruibles.begin(); iter < BloquesDestruibles.end(); ++iter){
        if(imagenActual->collidesWithItem(*iter)){
            tocoLaPared = true;
        }
    }

    return tocoLaPared;
}



int contador = 0;
void MainWindow::moverEnemigos()
{

    for (int i = 0; i < Enemigos.size(); ++i) {
        static bool cambiarDireccionDelMovimiento;
        if (contador <= 0) cambiarDireccionDelMovimiento = true;
        else if (contador >= 300) cambiarDireccionDelMovimiento = false;
        if (cambiarDireccionDelMovimiento){
            contador += 5;
            Enemigos[0]->setPos(Enemigos[0]->x()+5, Enemigos[0]->y());
            Enemigos[1]->setPos(Enemigos[1]->x()+5, Enemigos[1]->y());
            Enemigos[2]->setPos(Enemigos[2]->x(), Enemigos[2]->y()+2.6);
        }
        else{
            contador -= 5;
            Enemigos[0]->setPos(Enemigos[0]->x()-5, Enemigos[0]->y());
            Enemigos[1]->setPos(Enemigos[1]->x()-5, Enemigos[1]->y());
            Enemigos[2]->setPos(Enemigos[2]->x(), Enemigos[2]->y()-2.6);
        }
    }
}






void MainWindow::colocarBomba() {
    if (bombasActivas.size() >= maxBombas) { // Verificamos si se alcanzó el límite de bombas activas
        return;
    }

    // Creamos la bomba
    QGraphicsPixmapItem* bomba = new QGraphicsPixmapItem(QPixmap(":/imagenes/bomba.png").scaled(50, 50));
    bomba->setPos(imagenActual->pos());
    escenaLaberinto->addItem(bomba);
    bombasActivas.append(bomba);

    // Configuramos un temporizador para hacer que la bomba explote después de 2 segundos
    QTimer::singleShot(2000, this, [=]() {
        // Creamos un área de explosión alrededor de la bomba
        QRectF areaExplosion(bomba->x() - 50, bomba->y() - 50, 150, 150);
        QList<QGraphicsItem*> itemsAfectados = escenaLaberinto->items(areaExplosion);

        // Recorremos los elementos afectados para aplicar la lógica de explosión
        for (QGraphicsItem* item : itemsAfectados) {
            if (BloquesDestruibles.contains(static_cast<QGraphicsPixmapItem*>(item))) {
                escenaLaberinto->removeItem(item);
                BloquesDestruibles.removeOne(static_cast<QGraphicsPixmapItem*>(item));
                delete item;
            }
            else if (Enemigos.contains(static_cast<QGraphicsPixmapItem*>(item))) {
                escenaLaberinto->removeItem(item);
                Enemigos.removeOne(static_cast<QGraphicsPixmapItem*>(item));
                delete item;
            }
            else if (item == imagenActual) {
                qDebug() << "El personaje ha sido afectado por la explosión.";
            }
        }



        // Removemos la bomba después de la explosión
        escenaLaberinto->removeItem(bomba);
        bombasActivas.removeOne(bomba);
        delete bomba;
    });
}








MainWindow::~MainWindow()
{
    delete ui;
}
