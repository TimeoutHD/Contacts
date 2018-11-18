#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>

class Notepad : public QWidget {

    Q_OBJECT
    
public:
    Notepad();
    
private slots:
    void quit();
    
private:
    QTextEdit *textEdit;
    QPushButton *quitButton;
};

Notepad::Notepad() {
    textEdit = new QTextEdit;
    quitButton = new QPushButton(tr("Quit"));
    
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    layout->addWidget(quitButton);
    
    setLayout(layout);
    setWindowTitle(L"Notepad");
}

void Notepad::quit()
{
    qApp->quit();
}

