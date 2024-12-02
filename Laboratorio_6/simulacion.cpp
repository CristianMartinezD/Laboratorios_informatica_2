#include "simulacion.h"
#include <QFile>
#include <QTextStream>
#include <cmath>

// Constructor
Simulacion::Simulacion(QGraphicsScene* escena, QObject* padre)
    : QObject(padre), escena(escena) {}

// Establece los cuerpos iniciales para la simulación
void Simulacion::establecerCuerpos(const std::vector<Cuerpo>& nuevosCuerpos) {
    cuerpos = nuevosCuerpos;
}

// Inicia la simulación
void Simulacion::iniciarSimulacion() {
    // Limpiar la escena
    escena->clear();
    // Crear un punto para cada cuerpo en la escena
    for (auto& cuerpo : cuerpos) {
        itemsCuerpos.push_back(escena->addEllipse(cuerpo.posicionX - 2, cuerpo.posicionY - 2, 4, 4, QPen(), QBrush(Qt::SolidPattern)));
    }

    // Configurar el temporizador para la simulación
    temporizador = new QTimer(this);
    connect(temporizador, &QTimer::timeout, this, &Simulacion::actualizarCuerpos);
    temporizador->start(50); // Intervalo de 50 ms
}


void Simulacion::detenerSimulacion()
{
    temporizador->stop();
    // Vaciar las listas
    cuerpos.clear();
    itemsCuerpos.clear();
    delete temporizador; // Liberar memoria del temporizador
    tiempo = 0.0;
}

// Guarda los datos de la simulación en un archivo
void Simulacion::guardarDatosEnArchivo() {

    // Iteramos sobre todos los cuerpos
    for (size_t i = 0; i < cuerpos.size(); ++i) {
        // Crear un archivo para cada cuerpo, con un nombre único basado en el índice
        QString nombreArchivo = QString("cuerpo_%1.txt").arg(i);
        QFile archivo(nombreArchivo);

        // Verificar si el archivo ya existe
        bool archivoExistente = archivo.exists();

        // Abrir el archivo en modo de append si ya existe, o en modo de escritura si es nuevo
        if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text | (archivoExistente ? QIODevice::Append : QIODevice::WriteOnly))) {
            continue;  // Si no se puede abrir, continuamos con el siguiente cuerpo
        }

        QTextStream salida(&archivo);

        // Si el archivo es nuevo, escribir encabezados
        if (!archivoExistente) {
            salida << "Tiempo\tPosX\tPosY\tVelX\tVelY\n";
        }

        salida << tiempo << "\t"
               << cuerpos.at(i).posicionX << "\t"
               << cuerpos.at(i).posicionY << "\t"
               << cuerpos.at(i).velocidadX << "\t"
               << cuerpos.at(i).velocidadY << "\n";
    }
}




// Actualiza las posiciones, velocidades y acelera los cuerpos
void Simulacion::actualizarCuerpos() {
    double constanteGravitacional = 1.0; // G simplificada
    double intervaloTiempo = 1.0; // ∆t simplificado

    // Calcular aceleraciones
    for (auto& cuerpo : cuerpos) {
        cuerpo.aceleracionX = cuerpo.aceleracionY = 0.0; // Reiniciar aceleración

        for (const auto& otroCuerpo : cuerpos) {
            if (&cuerpo != &otroCuerpo) {
                double distanciaX = otroCuerpo.posicionX - cuerpo.posicionX;
                double distanciaY = otroCuerpo.posicionY - cuerpo.posicionY;
                double distanciaCuadrada = distanciaX * distanciaX + distanciaY * distanciaY;
                double distancia = std::sqrt(distanciaCuadrada);

                double fuerza = constanteGravitacional * otroCuerpo.masa / distanciaCuadrada;
                cuerpo.aceleracionX += fuerza * distanciaX / distancia;
                cuerpo.aceleracionY += fuerza * distanciaY / distancia;
            }
        }
    }

    // Actualizar posiciones y velocidades
    for (auto& cuerpo : cuerpos) {
        cuerpo.velocidadX += cuerpo.aceleracionX * intervaloTiempo;
        cuerpo.velocidadY += cuerpo.aceleracionY * intervaloTiempo;
        cuerpo.posicionX += cuerpo.velocidadX * intervaloTiempo;
        cuerpo.posicionY += cuerpo.velocidadY * intervaloTiempo;
    }

    // Actualizar gráficamente los cuerpos y agregar huellas
    for (size_t i = 0; i < cuerpos.size(); ++i) {
        // Actualizar la posición gráfica del cuerpo
        itemsCuerpos[i]->setRect(cuerpos[i].posicionX - 2, cuerpos[i].posicionY - 2, 4, 4);

        // Crear y agregar una nueva huella en la posición actual del cuerpo
        QGraphicsEllipseItem* huella = escena->addEllipse(
            cuerpos[i].posicionX - 2,
            cuerpos[i].posicionY - 2,
            4, 4,
            QPen(Qt::gray), QBrush(Qt::red, Qt::SolidPattern)
            );

        // Agregar la huella a la lista de huellas
        huellas.append(huella);
    }

    guardarDatosEnArchivo(); // Guardar los datos después de cada ciclo

    tiempo += 1.0; // Incrementar el tiempo después de cada iteración
}
