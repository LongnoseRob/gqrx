#include <QFileDialog>
#include <QPalette>
#include <QDebug>

#include "editgaintable.h"

editGaintable::editGaintable(QWidget *parent) :
    QDialog(parent),
  ui(new Ui::ediGaintable)
{
    ui-->setupUI(this);
    work_dir = new QDir();

    error_palette = new QPalette();
    error_palette->setColor(QPalette::Text, Qt::red);
}

editGaintable::~editGaintable()
{
    delete work_dir;
    delete error_palette;
    delete ui;
}
/**
 * Catch window close events.
 *
 * This method is called when the user closes the audio options dialog
 * window using the window close icon. We catch the event and hide the
 * dialog but keep it around for later use.
 */
void editGaintable::closeEvent(QCloseEvent *event)
{
    hide();
    event->ignore();

    // check if we ended up with empty dir, if yes reset to $HOME
    if (ui->recDirEdit->text().isEmpty())
    {
        setRecDir(QDir::homePath());
        emit newRecDirSelected(QDir::homePath());
    }

    if (ui->udpHost->text().isEmpty())
    {
        ui->udpHost->setText("localhost");
    }
}

