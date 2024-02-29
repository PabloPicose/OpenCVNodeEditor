//
// Created by pablo on 2/29/24.
//

#include "SizeVarModel.h"
#include "ui_SizeVarForm.h"

SizeVarModel::SizeVarModel() {
}

SizeVarModel::~SizeVarModel() {
}

QString SizeVarModel::caption() const {
    return QString("Size");
}

QString SizeVarModel::name() const {
    return QString("Size");
}

unsigned SizeVarModel::nPorts(QtNodes::PortType portType) const {
    switch (portType) {
        case QtNodes::PortType::In:
            return 1;
        case QtNodes::PortType::Out:
            return 3;
        default:
            return 0;
    }
}

QtNodes::NodeDataType SizeVarModel::dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const {
    switch (portType) {
        case QtNodes::PortType::In:
            return SizeData().type();
        case QtNodes::PortType::Out:
            switch (portIndex) {
                case 0:
                    return SizeData().type();
                case 1:
                    return NumericalData().type();
                case 2:
                    return NumericalData().type();
                default:
                    break;
            }
        default:
            return SizeData().type();
    }
}

void SizeVarModel::setInData(std::shared_ptr<QtNodes::NodeData> nodeData, const QtNodes::PortIndex portIndex) {
    m_inSizeData = std::dynamic_pointer_cast<SizeData>(nodeData);
    const auto lockSize = m_inSizeData.lock();
    if (lockSize) {
        setOutSize(lockSize->size());
        // disable the spinboxes
        m_ui->sb_width->setEnabled(false);
        m_ui->sb_height->setEnabled(false);
    } else {
        setOutSize(m_outSize);
        // enable the spinboxes
        m_ui->sb_width->setEnabled(true);
        m_ui->sb_height->setEnabled(true);
    }
}

std::shared_ptr<QtNodes::NodeData> SizeVarModel::outData(const QtNodes::PortIndex port) {
    switch (port) {
        case 0:
            return m_outSizeData;
        case 1:
            return m_outWidthData;
        case 2:
            return m_outHeightData;
        default:
            return nullptr;
    }
}

QWidget* SizeVarModel::embeddedWidget() {
    if (!m_widget) {
        m_ui = std::make_unique<Ui::SizeVarForm>();
        m_widget = new QWidget();
        m_ui->setupUi(m_widget);
        // sb_width and sb_height are QSpinBox
        connect(m_ui->sb_width, QOverload<int>::of(&QSpinBox::valueChanged), [this](int value) {
            setOutSize(QSize(value, m_outSize.height()));
        });
        connect(m_ui->sb_height, QOverload<int>::of(&QSpinBox::valueChanged), [this](int value) {
            setOutSize(QSize(m_outSize.width(), value));
        });
        setOutSize(QSize(0, 0));
    }
    return m_widget;
}

void SizeVarModel::setOutSize(const QSize& size) {
    // updates the size from incoming data
    m_outSize = size;
    m_outSizeData = std::make_shared<SizeData>(m_outSize);
    m_outWidthData = std::make_shared<NumericalData>(m_outSize.width());
    m_outHeightData = std::make_shared<NumericalData>(m_outSize.height());
    // block signals to avoid infinite loop
    QSignalBlocker blocker(m_ui->sb_width);
    QSignalBlocker blocker2(m_ui->sb_height);
    m_ui->sb_width->setValue(m_outSize.width());
    m_ui->sb_height->setValue(m_outSize.height());

    emit dataUpdated(0);
    emit dataUpdated(1);
    emit dataUpdated(2);
}
