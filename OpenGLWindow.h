#pragma once
#include <QWindow>
#include <QOpenGLFunctions>

class QOpenGLContext;

class OpenGLWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWindow *parent = nullptr);
    ~OpenGLWindow();

    virtual void render();

    virtual void initialize();

public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event) override;

    void exposeEvent(QExposeEvent *event) override;

private:
    QOpenGLContext *m_context = nullptr;
};
