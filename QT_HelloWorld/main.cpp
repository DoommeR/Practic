#include <QtGui>
#include <QApplication>
#include <QTextEdit>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

int main(int argv, char **args)
{
    QApplication app(argv, args);
 	QLabel lbl("Hello!");
	QPushButton quitButton("Выход");
	QPushButton *pcmdNormal= new QPushButton("&Normal Button");

	QObject::connect(&quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	QObject::connect(pcmdNormal, SIGNAL(clicked()), qApp,SLOT(slotButtonClicked()));
	QVBoxLayout layout;
	layout.addWidget(&lbl);
	layout.addWidget(pcmdNormal);
	layout.addWidget(&quitButton);

	QWidget window;
	window.setLayout(&layout);

    	window.show();

    return app.exec();
}

void slotButtonClicked()
{

}

