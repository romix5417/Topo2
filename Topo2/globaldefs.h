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
    quint32 nodePool;
    quint32 ipv4addrPool;
    quint32 ipv4addrMask;
    quint32 mode_flag;
}NManager;


quint32 get_ipv4addr(quint32 number);

quint32 get_nodenumber();

quint32 get_ipv4mask();

QString iptostr(quint32 ipv4addr);

void route_resolving();

void calculate_route();

#define CLICK_ARROW_BUTTON 0
#define CLICK_NODE_BUTTON 1
#define CLICK_LINE_BUTTON 2
#define CLICK_DELETE_BUTTON 3
#define CLICK_CONFIG_BUTTON 4

#define DYNAMIC_MODE 0
#define STATIC_MODE  1

#define gVersion "0.0.2"


#endif // GLOBALDEFS_H
