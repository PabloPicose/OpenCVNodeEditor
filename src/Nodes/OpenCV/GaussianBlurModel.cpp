//
// Created by pablo on 2/26/24.
//
#include <QtConcurrent/QtConcurrent>
#include <QElapsedTimer>

#include "GaussianBlurModel.h"
#include "Nodes/Data/DataInclude.h"
#include "ui_GaussianBlurForm.h"

#include "Nodes/Conversor/MatQt.h"

#include <opencv2/opencv.hpp>

GaussianBlurModel::GaussianBlurModel() {

    connect(&m_watcher, &QFutureWatcher<std::tuple<QPixmap, quint64>>::finished, this, &GaussianBlurModel::processFinished);
}

GaussianBlurModel::~GaussianBlurModel() {
}

QString GaussianBlurModel::caption() const {
    return "Gaussian Blur";
}

QString GaussianBlurModel::name() const {
    return "GaussianBlur";
}

unsigned GaussianBlurModel::nPorts(QtNodes::PortType portType) const {
    return 1;
}

QtNodes::NodeDataType GaussianBlurModel::dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const {
    return PixmapData().type();
}

void GaussianBlurModel::setInData(std::shared_ptr<QtNodes::NodeData> nodeData, const QtNodes::PortIndex portIndex) {
    switch (portIndex) {
        case 0: {
            m_inPixmapData = std::dynamic_pointer_cast<PixmapData>(nodeData);
            if (m_inPixmapData) {
                m_inPixmap = m_inPixmapData->pixmap();
            }
            break;
        }
        default:
            break;
    }
    requestProcess();
}

std::shared_ptr<QtNodes::NodeData> GaussianBlurModel::outData(const QtNodes::PortIndex port) {
    return std::make_shared<PixmapData>(m_outPixmap);
}

QWidget* GaussianBlurModel::embeddedWidget() {
    if (!m_widget) {
        m_ui = std::make_unique<Ui::GaussianBlurForm>();
        m_widget = new QWidget();
        m_ui->setupUi(m_widget);
        // width and height should be odd and positive
        connect(m_ui->sb_size_w, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int value) {
            if (value % 2 == 0) {
                m_ui->sb_size_w->setValue(value + 1);
                return;
            }
            if (m_inPixmapData) {
                m_inPixmap = m_inPixmapData->pixmap();
                requestProcess();
            }
        });
        connect(m_ui->sb_size_h, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int value) {
            if (value % 2 == 0) {
                m_ui->sb_size_h->setValue(value + 1);
                return;
            }
            if (m_inPixmapData) {
                m_inPixmap = m_inPixmapData->pixmap();
                requestProcess();
            }
        });
        connect(m_ui->sigmaXSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, [this]() {
            if (m_inPixmapData) {
                m_inPixmap = m_inPixmapData->pixmap();
                requestProcess();
            }
        });
        connect(m_ui->sigmaYSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, [this]() {
            if (m_inPixmapData) {
                m_inPixmap = m_inPixmapData->pixmap();
                requestProcess();
            }
        });
    }
    return m_widget;
}

void GaussianBlurModel::processFinished() {
    const auto tuple = m_watcher.result();
    m_outPixmap = std::get<0>(tuple);
    const quint64 time = std::get<1>(tuple);
    m_ui->sb_time->setValue(time);
    Q_EMIT dataUpdated(0);
    requestProcess();
}

void GaussianBlurModel::requestProcess() {
    if (m_watcher.isRunning()) {
        return;
    }
    if (m_inPixmap.isNull()) {
        return;
    }
    const auto future = QtConcurrent::run(processImage, m_inPixmap, QSize(m_ui->sb_size_w->value(),
                                                                          m_ui->sb_size_h->value()),
                                          m_ui->sigmaXSpinBox->value(), m_ui->sigmaYSpinBox->value());
    m_inPixmap = QPixmap();
    m_watcher.setFuture(future);
}

std::tuple<QPixmap, quint64> GaussianBlurModel::processImage(const QPixmap pixmap, const QSize& size,
                                        const double sigmaX,
                                        const double sigmaY) {
    QElapsedTimer timer;
    timer.start();
    const cv::Mat src = QPixmapToMat(pixmap);
    cv::Mat dst;
    try {
        cv::GaussianBlur(src, dst, cv::Size(size.width(), size.height()), sigmaX, sigmaY);
    } catch (cv::Exception& e) {
        qDebug() << e.what();
        return std::make_tuple(QPixmap(), timer.elapsed());
    }
    const QPixmap result = MatToQPixmap(dst);
    return std::make_tuple(result, timer.elapsed());
}
