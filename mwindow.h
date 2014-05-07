#ifndef MWINDOW_H
#define MWINDOW_H

#include <QMainWindow>

namespace Ui {
class MWindow;
}

class MWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MWindow(QWidget *parent = 0);
    ~MWindow();

private slots:
    void on_lbNuevaTabla_linkActivated(const QString &link);

private:
    Ui::MWindow *ui;
};

#endif // MWINDOW_H
