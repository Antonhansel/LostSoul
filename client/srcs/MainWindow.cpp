# include "MainWindow.hpp"

MainWindow::MainWindow() : QWidget()
{
    _login = new Login(this);
    _network = new Network(this);
}

MainWindow::~MainWindow()
{

}

void 	MainWindow::initHandShake(QString username, QString password)
{
	_network->tryNetsoul(username, password);
}

void 	MainWindow::setStatus(int status)
{
	
}

// QString		MainWindow::parsUser(QString input)
// {
//   QStringList		list;

//   list = input.split(":");
//   input.clear();
//   input += "<strong>";
//   input += list.at(3);
//   input += "</strong>";
//   return (input);
// }

// void		MainWindow::parsData(QString input)
// {
//   std::string           sub;
//   std::istringstream	iss(input.toUtf8().constData());
//   QUrl                  url;

//   while (iss)
//     {
//       sub = "";
//       iss >> sub;
//       if (sub == "msg")
//         {
//             iss >> sub;
//             input = parsUser(input);
//             input += ": ";
//             input += QString(sub.c_str());
//             addInput(url.fromPercentEncoding(input.toUtf8()));
//         }
//     }
// }