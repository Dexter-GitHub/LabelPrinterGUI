#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define MAIN_WINDOW_SIZE            QSize(570, 420)
#define MAIN_MIN_SIZE               QSize(210, 200)
#define MENU_BAR_HEIGHT             30

#define MINUS_ICON_PATH             QIcon(":/Resources/Icon/minus_icon.png/")

#define CORRE_MENU_TEXT             "위치보정(&C)"
#define SAVE_MENU_TEXT              "저장(&S)"
#define MENU_ACTION_CORRE_TEXT      "보정(&C)..."
#define MENU_ACTION_SAVE_TEXT       "저장(&S)..."
#define SYSTEM_BAR_LOGO_LABLE_TEXT  "Layer System"

class QPushButton;
class QHBoxLayout;
class QLabel;
class Worksheet;
class QStackedWidget;
class QMenuBar;
class QAction;
class CorrectionDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    CorrectionDialog *m_pCorreDialog;

private:
    Worksheet *m_worksheet;

private:
    bool m_bMoving;
    QPoint m_pointLastMousePos;

private:
    QWidget *m_pSysTemWidget;
    QWidget *m_pMeunBarWidget;
    QStackedWidget *m_pStackWidget;
    QMenuBar *m_pMenuBar;
    QAction *m_pSlotCorre;
    QAction *m_pSlotSave;

private:
    void setWindoswSize(void);
    void setSystemMenu(void);
    void setMenuBarWidget(void);

private Q_SLOTS:
    void slotCorreAction(void);
    void slotSaveAction(void);

protected:
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void resizeEvent(QResizeEvent *);
    virtual bool nativeEvent(const QByteArray &, void *, long *) Q_DECL_OVERRIDE;
};

#endif // MAINWINDOW_H
