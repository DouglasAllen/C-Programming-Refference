#include <QtCore>
#include <QtGui>

QMainWindow* CreateWindow()
{
	QMainWindow* window = new QMainWindow(0, Qt::Window);
  
	window->resize(250, 150);
	window->setWindowTitle("Qt Application");
	window->show();
	
	return window;
}
 
void CreateMsgButton(QMainWindow* window)
{
	QMessageBox* message = new QMessageBox(window);
	message->setText("Message text");
  
  	QPushButton* button = new QPushButton("Message", window);
	button->move(85, 40);
	button->resize(80, 25);
	button->show();
  	QObject::connect(button, SIGNAL(released()), message, SLOT(exec()));
}
 
void CreateQuitButton(QMainWindow* window, QApplication& application)
{
 	QPushButton* quit_button = new QPushButton("Quit", window);
	quit_button->move(85, 85);
	quit_button->resize(80, 25);
	quit_button->show();
	QObject::connect(quit_button, SIGNAL(released()), &application, SLOT(quit()));
}
 
int main(int argc, char* argv[])
{
	QApplication application(argc, argv);
  
	QMainWindow* window = CreateWindow();
	
	CreateMsgButton(window);
	
	CreateQuitButton(window, application);
  
	return application.exec();
}
