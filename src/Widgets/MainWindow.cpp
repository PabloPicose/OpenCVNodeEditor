//
// Created by pablo on 2/24/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QtNodes/DataFlowGraphicsScene>
#include <QtNodes/DataFlowGraphModel>
#include "Nodes/NodesInclude.h"

#include <QtNodes/GraphicsView>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto* model = new QtNodes::DataFlowGraphModel(registerDataModels());
    m_scene = new QtNodes::DataFlowGraphicsScene(*model);
    model->setParent(m_scene);

    ui->nodes_graphicsView->setScene(m_scene);
}

MainWindow::~MainWindow() {
    delete ui;
}

std::shared_ptr<QtNodes::NodeDelegateModelRegistry> MainWindow::registerDataModels() {
        auto ret = std::make_shared<QtNodes::NodeDelegateModelRegistry>();
    ret->registerModel<PiModel>("Constants");

    ret->registerModel<NumberSourceDataModel>("Sources");

    ret->registerModel<NumberDisplayDataModel>("Displays");

    ret->registerModel<AdditionModel>("Operators");

    ret->registerModel<SubtractionModel>("Operators");

    ret->registerModel<MultiplicationModel>("Operators");

    ret->registerModel<DivisionModel>("Operators");

    ret->registerModel<ImageLoaderModel>("Images");

    ret->registerModel<ImageShowModel>("Images");

    ret->registerModel<ColorCV>("OpenCV");

    ret->registerModel<BlurModel>("OpenCV");

    ret->registerModel<CannyModel>("OpenCV");

    ret->registerModel<GaussianBlurModel>("OpenCV");

    ret->registerModel<HoughLinesP>("OpenCV");

    return ret;
}