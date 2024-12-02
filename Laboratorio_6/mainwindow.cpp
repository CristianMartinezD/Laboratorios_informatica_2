#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , escenaSimulacion(new QGraphicsScene(this))
    , simulacion(new Simulacion(escenaSimulacion, this))
{
    ui->setupUi(this);

    // Configurar la vista para la simulación
    ui->vistaSimulacion->setScene(escenaSimulacion);
    ui->vistaSimulacion->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Slot para cargar una nueva masa
void MainWindow::on_botonCargarMasa_clicked() {
    // Crear un nuevo cuerpo a partir de los datos ingresados
    Cuerpo nuevoCuerpo;
    nuevoCuerpo.posicionX = ui->entradaPosicionX->text().toDouble();
    nuevoCuerpo.posicionY = ui->entradaPosicionY->text().toDouble();
    nuevoCuerpo.velocidadX = ui->entradaVelocidadX->text().toDouble();
    nuevoCuerpo.velocidadY = ui->entradaVelocidadY->text().toDouble();
    nuevoCuerpo.masa = ui->entradaMasa->text().toDouble();

    // Agregar el cuerpo a la lista
    listaCuerpos.push_back(nuevoCuerpo);

    // Mostrar en la lista de cuerpos
    QString descripcion = QString("Masa: %1, X: %2, Y: %3, Vx: %4, Vy: %5")
                              .arg(nuevoCuerpo.masa)
                              .arg(nuevoCuerpo.posicionX)
                              .arg(nuevoCuerpo.posicionY)
                              .arg(nuevoCuerpo.velocidadX)
                              .arg(nuevoCuerpo.velocidadY);
    ui->listaCuerpos->addItem(descripcion);

    // Limpiar los campos de entrada
    ui->entradaPosicionX->clear();
    ui->entradaPosicionY->clear();
    ui->entradaVelocidadX->clear();
    ui->entradaVelocidadY->clear();
    ui->entradaMasa->clear();
}

// Slot para iniciar la simulación
void MainWindow::on_botonSimular_clicked() {
    // Configurar los cuerpos en la simulación
    simulacion->establecerCuerpos(listaCuerpos);

    // Iniciar la simulación
    simulacion->iniciarSimulacion();
}


void MainWindow::on_Detener_clicked()
{
    simulacion->detenerSimulacion();
    // Limpiar la lista de cuerpos en la interfaz
    listaCuerpos.clear();
    ui->listaCuerpos->clear();

    // Reconfigurar la escena (si necesario)
    ui->vistaSimulacion->setScene(escenaSimulacion);
    listaCuerpos.clear();
}

