#include "homewindow.h"
#include "ui_homewindow.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include "appconstant.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    setWindowTitle("Home");
    setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    QWidget *scrollableWidget = new QWidget;

    // Create a vertical layout for the widget
    scrollableLayout = new QVBoxLayout(scrollableWidget);

    // Add a series of labels to the layout (these are the items that may not fit in the available space)
    for (int i = 1; i <= 5; i++) {
        if(i % 3 == 0) {
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
        else if(i % 3 == 1){
            QLabel *label = new QLabel("Question item for RadioButton: " + QString::number(i));
            // Create the group box for the first question
            QGroupBox *groupBox1 = new QGroupBox;

            // Create the radio buttons for the first question
            QRadioButton *radioButton1a = new QRadioButton("Option 1a");
            QRadioButton *radioButton1b = new QRadioButton("Option 1b");
            QRadioButton *radioButton1c = new QRadioButton("Option 1c");

            // Create a vertical layout for the first question's radio buttons
            QVBoxLayout *layout1 = new QVBoxLayout;
            layout1->addWidget(radioButton1a);
            layout1->addWidget(radioButton1b);
            layout1->addWidget(radioButton1c);

            // Set the layout for the first question's group box
            groupBox1->setLayout(layout1);

            QVBoxLayout *layout = new QVBoxLayout;
            layout->addWidget(label);
            layout->addWidget(groupBox1);

            scrollableLayout->addLayout(layout);
        }
         else if(i % 3 == 2){
            QLabel *label = new QLabel("Question item for CheckBox: " + QString::number(i));
            // Create the group box for the first question
            QGroupBox *groupBox1 = new QGroupBox;

            // Create the radio buttons for the first question
            QCheckBox *qcheckBox1a = new QCheckBox("CheckBox 1");
            QCheckBox *qcheckBox1b = new QCheckBox("CheckBox 2");
            QCheckBox *qcheckBox1c = new QCheckBox("CheckBox 3");

            // Create a vertical layout for the first question's radio buttons
            QVBoxLayout *layout1 = new QVBoxLayout;
            layout1->addWidget(qcheckBox1a);
            layout1->addWidget(qcheckBox1b);
            layout1->addWidget(qcheckBox1c);

            // Set the layout for the first question's group box
            groupBox1->setLayout(layout1);

            QVBoxLayout *layout = new QVBoxLayout;
            layout->addWidget(label);
            layout->addWidget(groupBox1);

            scrollableLayout->addLayout(layout);
        }

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

    qDebug() << "done Submit";
}

