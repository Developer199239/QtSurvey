#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QRadioButton>

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

private slots:
    void submitAnswers();
//    void radioButtonClicked();
private:
    Ui::HomeWindow *ui;
    QList<QLineEdit *> m_answerFields;
    QVBoxLayout *scrollableLayout;
    QWidget *scrollableWidget;
};

#endif // HOMEWINDOW_H
