#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QSettings>
#include <QMenu>
#include <QScreen>
#include <QDateTime>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();    


private slots:
    void backgroundLoop();
    void foregroundLoop();
    void on_actionEditNotesTriggered();
    void on_actionSkipBreakTriggered();
    void on_actionExit_triggered();
    void initForegroundCycle();
    void on_ForegroundCycleDurationChanged();
    void on_BackgroundCycleDurationChanged();
    void on_plainTextEdit_textChanged();
    void on_pushButtonClicked();
    void on_btnIconClicked();
    void on_btnGo_clicked();
    void on_btnRestart_clicked();
    void on_ScreenIndexChanged();

private:
    Ui::MainWindow *ui;
    QTimer *tmrBg;
    QTimer *tmrFg;

    void initBackgroundCycle();
    void foregroundLoopNotification();

    void initTrayMenu();
    void setWindowSizeAndLocation();
    void UpdatTrayMenuCheckStatus();
    void loadSettings();
    QString secondsToString(qint64 seconds);

    QSystemTrayIcon *trayIcon;

    QMediaPlayer *player;

    int BgCount, foreground_sec_count;
    int background_cycle_duration_min = 20;
    int foreground_cycle_duration_sec = 5;
    bool IsBreakSkipped;
    bool IsMouseReleased;
    int InitWindowWidth, InitWindowHeight;

    int screenIdx;

    QMenu *menuTray;
    QMenu *menuFgLengthSettings, *menuBreakInverval, *menuScreenSelection;
    QAction *actionEditNotes, *actionSkipBreak, *actionExit;
    QActionGroup *actiongroupBackgroundCycleDurationMin;
    QAction *actionBgLen1, *actionBgLen15, *actionBgLen20;
    QActionGroup *actiongroupForegroundCycleDurationSec;
    QActionGroup *actiongroupScreenSelection;
    QAction *actionFgLen20, *actionFgLen40, *actionFgLen60, *actionFgLen120;
    std::vector<QAction *> actionScreens;
};

#endif // MAINWINDOW_H
