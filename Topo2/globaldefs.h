#ifndef GLOBALDEFS_H
#define GLOBALDEFS_H

#include <QGraphicsView>
#include <QList>
#include <node.h>

typedef struct nodeManager{
    Node *lasterNode;
    Node *curNode;
    QGraphicsScene *g_scene;
    QList<Node *> nodeList;
}NManager;

#define CLICK_ARROW_BUTTON 0
#define CLICK_NODE_BUTTON 1
#define CLICK_LINE_BUTTON 2
#define CLICK_DELETE_BUTTON 3
#define CLICK_CONFIG_BUTTON 4


#endif // GLOBALDEFS_H
