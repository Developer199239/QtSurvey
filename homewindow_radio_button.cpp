#include "homewindow.h"
#include "ui_homewindow.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QCheckBox>
#include <QWidget>
#include "appconstant.h"

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    setWindowTitle("Home");
    setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    scrollableWidget = new QWidget;

    // Create a vertical layout for the widget
    scrollableLayout = new QVBoxLayout(scrollableWidget);

    // Add a series of labels to the layout (these are the items that may not fit in the available space)
    for (int i = 1; i <= 5; i++) {
        QLabel *label = new QLabel("Question item for RadioButton: " + QString::number(i));
                    // Create the group box for the first question
                    QGroupBox *groupBox1 = new QGroupBox;

                    // Create the radio buttons for the first question
                    QRadioButton *radioButton1a = new QRadioButton("Option 1a");
                    QRadioButton *radioButton1b = new QRadioButton("Option 1b");
                    QRadioButton *radioButton1c = new QRadioButton("Option 1c");

                    radioButton1a->setObjectName("question1");
                        radioButton1b->setObjectName("question1");
                        radioButton1c->setObjectName("question1");

                    // Create a vertical layout for the first question's radio buttons
                    QVBoxLayout *layout1 = new QVBoxLayout;
                    layout1->addWidget(radioButton1a);
                    connect(radioButton1a, &QRadioButton::clicked, this, &HomeWindow::radioButtonClicked);

                    layout1->addWidget(radioButton1b);
                    connect(radioButton1b, &QRadioButton::clicked, this, &HomeWindow::radioButtonClicked);

                    layout1->addWidget(radioButton1c);
                    connect(radioButton1c, &QRadioButton::clicked, this, &HomeWindow::radioButtonClicked);

                    // Set the layout for the first question's group box
                    groupBox1->setLayout(layout1);

                    QVBoxLayout *layout = new QVBoxLayout;
                    layout->addWidget(label);
                    layout->addWidget(groupBox1);

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


void HomeWindow::radioButtonClicked() {
   qDebug() << "Radio button clicked";
//   QRadioButton *clickedRadioButton = qobject_cast<QRadioButton *>(sender());
//       if (clickedRadioButton) {
//           QString groupName = clickedRadioButton->parentWidget()->parentWidget()->title();
//           QString radioButtonValue = clickedRadioButton->text();
//           qDebug() << "Group box:" << groupName << "Radio button:" << radioButtonValue;
//       }

   QRadioButton *button = qobject_cast<QRadioButton*>(sender());
       if (button) {
           QString groupName = button->parent()->objectName();
           QString option = button->text();
//           selectedOptions[groupName] = option;
           qDebug() << groupName<<option;
       }
}

void HomeWindow::submitAnswers()
{
    qDebug() << "Submit";
    // Iterate over the child widgets of the scrollableWidget
        QList<QWidget *> childWidgets = scrollableWidget->findChildren<QWidget *>();
        qDebug() << "childWidgets count"<<childWidgets.size();
        for (int i = 0; i < childWidgets.size(); ++i) {
            // Check if the child widget is a line edit
            QLineEdit *lineEdit = qobject_cast<QLineEdit *>(childWidgets[i]);
            if (lineEdit) {
                int questionID = lineEdit->property("questionID").toInt();
                // Retrieve the text entered in the line edit
                QString answer = lineEdit->text();
                qDebug() << "Answer for question AnswerId" << questionID << ": " << answer;
            }
        }
    qDebug() << "done Submit";
}

