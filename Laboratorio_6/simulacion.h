#ifndef SIMULACION_H
#define SIMULACION_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QList>
#include <QTimer>
#include <vector>

// Estructura para representar un cuerpo en la simulación
struct Cuerpo {
    double posicionX, posicionY;       // Posición del cuerpo
    double velocidadX, velocidadY;    // Velocidad del cuerpo
    double aceleracionX, aceleracionY; // Aceleración del cuerpo
    double masa;                      // Masa del cuerpo
};

class Simulacion : public QObject {
    Q_OBJECT

public:
    explicit Simulacion(QGraphicsScene* escena, QObject* padre = nullptr);

    // Métodos públicos
    void establecerCuerpos(const std::vector<Cuerpo>& nuevosCuerpos);
    void iniciarSimulacion();
    void guardarDatosEnArchivo();
    void detenerSimulacion();

private slots:
    void actualizarCuerpos(); // Actualiza las posiciones y velocidades de los cuerpos

private:
    QGraphicsScene* escena;                      // Escena donde se visualiza la simulación
    QTimer* temporizador;                        // Temporizador para los pasos de la simulación
    std::vector<Cuerpo> cuerpos;                 // Lista de cuerpos en la simulación
    std::vector<QGraphicsEllipseItem*> itemsCuerpos; // Representación gráfica de los cuerpos
    double tiempo = 0.0;  // Inicializamos el tiempo de simulación
    QList<QGraphicsEllipseItem*> huellas; // Lista de huellas
};

#endif // SIMULACION_H

