#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QUrl>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(QGraphicsScene *scene, QWidget *parent = 0);
    GraphicsView(QWidget *parent = 0);
    void dragEnterEvent(QDragEnterEvent* event);
    void dragMoveEvent(QDragMoveEvent* event);
    void dropEvent(QDropEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void wheelEvent(QWheelEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void changeImage(QImage image);
    double getScaleFactor();
    
private:
    QGraphicsPixmapItem *currentImage;
    int prevImageWidth;
    int prevImageHeight;
    double wheelPosition;
    double scaleFactor;
    
    void init();
    void zoom(int wheelAngle);
    void fitImageInView();
    double calcScaleFactor(double wheelPos);
    double calcWheelPosition(double scaleFac);
    
signals:
    void singleImageDropped(QUrl url);
    void multipleImagesDropped(QList<QUrl> urls);
    void folderDropped(QUrl url);
    void keyLeftPressed();
    void keyRightPressed();
    void controlSPressed();
    void controlCPressed();
    void scaleChanged(double newScale);
};

#endif // GRAPHICSVIEW_H
