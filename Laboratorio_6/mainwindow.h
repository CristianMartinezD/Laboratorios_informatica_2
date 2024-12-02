#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "simulacion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_botonCargarMasa_clicked();   // Slot para agregar un cuerpo
    void on_botonSimular_clicked();     // Slot para iniciar la simulación

    void on_Detener_clicked();

private:
    Ui::MainWindow* ui;
    QGraphicsScene* escenaSimulacion;       // Escena para la simulación

    Simulacion* simulacion;                 // Clase de simulación
    std::vector<Cuerpo> listaCuerpos;       // Lista de cuerpos cargados
};

#endif // MAINWINDOW_H


