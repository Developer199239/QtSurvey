#include "homewindow.h"
#include "ui_homewindow.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    setFixedSize(400, 400);

    QWidget *scrollableWidget = new QWidget;

    // Create a vertical layout for the widget
    QVBoxLayout *scrollableLayout = new QVBoxLayout(scrollableWidget);

    // Add a series of labels to the layout (these are the items that may not fit in the available space)
    for (int i = 1; i <= 20; i++) {
        // Create the label and line edit widgets
        QLabel *label = new QLabel("Question item: " + QString::number(i));
        QLineEdit *lineEdit = new QLineEdit;
        lineEdit->setPlaceholderText("Answer for question "+QString::number(i));

        // Add the label and line edit widgets to a new vertical layout
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(label);
        layout->addWidget(lineEdit);

        // Add the new vertical layout to the main scrollable layout
        scrollableLayout->addLayout(layout);
    }

    // Create a button and add it to a vertical layout
    QPushButton *submitButton = new QPushButton(tr("Submit"));
    connect(submitButton, &QPushButton::clicked, this, &HomeWindow::submitAnswers);
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(submitButton);

    // Set up the main layout and add the scrollable widget and the button layout to it
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(scrollableWidget);
    mainLayout->addLayout(buttonLayout);

    // Set up the scroll area and set the main layout as the widget for the scroll area
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    QWidget *scrollAreaWidget = new QWidget;
    scrollAreaWidget->setLayout(mainLayout);
    scrollArea->setWidget(scrollAreaWidget);

    // Set the scroll area as the central widget for the main window
    setCentralWidget(scrollArea);


}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::submitAnswers()
{
    qDebug() << "Submit";
}

