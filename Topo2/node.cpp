/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "edge.h"
#include "node.h"
#include "graphwidget.h"
#include "globaldefs.h"
#include "route.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

#include <QDebug>

extern NManager nodeInfoManager;
extern int buttonFlag;

//! [0]
Node::Node(GraphWidget *graphWidget)
    : graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    setAcceptHoverEvents(true);
    setSelectFlag(false);
}
//! [0]

//! [1]
void Node::addEdge(Edge *edge)
{
    edgeList << edge;
    edge->adjust();
}

QList<Edge *> Node::edges() const
{
    return edgeList;
}
//! [1]

//! [2]
void Node::calculateForces()
{
    if (!scene() || scene()->mouseGrabberItem() == this) {
        newPos = pos();
        return;
    }
//! [2]

//! [3]
    // Sum up all forces pushing this item away
    qreal xvel = 0;
    qreal yvel = 0;
    foreach (QGraphicsItem *item, scene()->items()) {
        Node *node = qgraphicsitem_cast<Node *>(item);
        if (!node)
            continue;

        QPointF vec = mapToItem(node, 0, 0);
        qreal dx = vec.x();
        qreal dy = vec.y();
        double l = 2.0 * (dx * dx + dy * dy);
        if (l > 0) {
            xvel += (dx * 150.0) / l;
            yvel += (dy * 150.0) / l;
        }
    }
//! [3]

//! [4]
    // Now subtract all forces pulling items together
    double weight = (edgeList.size() + 1) * 10;
    foreach (Edge *edge, edgeList) {
        QPointF vec;
        if (edge->sourceNode() == this)
            vec = mapToItem(edge->destNode(), 0, 0);
        else
            vec = mapToItem(edge->sourceNode(), 0, 0);
        xvel -= vec.x() / weight;
        yvel -= vec.y() / weight;
    }
//! [4]

//! [5]
    if (qAbs(xvel) < 0.1 && qAbs(yvel) < 0.1)
        xvel = yvel = 0;
//! [5]

//! [6]
    QRectF sceneRect = scene()->sceneRect();
    newPos = pos() + QPointF(xvel, yvel);
    newPos.setX(qMin(qMax(newPos.x(), sceneRect.left() + 10), sceneRect.right() - 10));
    newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 10), sceneRect.bottom() - 10));
}
//! [6]

//! [7]
bool Node::advance()
{
    if (newPos == pos())
        return false;

    setPos(newPos);
    return true;
}
//! [7]

//! [8]
QRectF Node::boundingRect() const
{
    qreal adjust = 6;
    return QRectF( -42 - adjust, -30 - adjust, 84 + adjust, 60 + adjust);
}
//! [8]

//! [9]
QPainterPath Node::shape() const
{
    QPainterPath path;
    path.addEllipse(-10, -10, 20, 20);
    return path;
}
//! [9]

//! [10]
/*void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7, -7, 20, 20);

    QRadialGradient gradient(-3, -3, 10);
    if (option->state & QStyle::State_Sunken) {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, QColor(Qt::yellow).light(120));
        gradient.setColorAt(0, QColor(Qt::darkYellow).light(120));
    } else {
        gradient.setColorAt(0, Qt::yellow);
        gradient.setColorAt(1, Qt::darkYellow);
    }
    painter->setBrush(gradient);

    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-10, -10, 20, 20);


    painter->drawText(-40,30,QString("10.0.0.100"));
}*/
//! [10]

QString Node::get_stripv4addr()
{
    char stripv4addr[16]={0};
    unsigned char *charipv4addr =  (unsigned char*)(&ipv4addr);
    //qDebug()<<"ipv4addr:"<<hex<<charipv4addr[0]<<endl;
    //qDebug()<<"ipv4addr:"<<hex<<charipv4addr[1]<<endl;
    //qDebug()<<"ipv4addr:"<<hex<<charipv4addr[2]<<endl;
    //qDebug()<<"ipv4addr:"<<hex<<charipv4addr[3]<<endl;

    sprintf(stripv4addr,"%d.%d.%d.%d/24",charipv4addr[3], charipv4addr[2], charipv4addr[1], charipv4addr[0]);
    //qDebug()<<stripv4addr<<endl;

    return QString(stripv4addr);
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    //painter->setPen(Qt::NoPen);
    //painter->setBrush(Qt::darkGray);
    //painter->drawEllipse(-7, -7, 20, 20);

    QPixmap pix;
    pix.load(":/images/node.png");

    painter->drawPixmap(-16,-16,pix);

    QString stripv4addr = get_stripv4addr();
    painter->drawText(-48,28,stripv4addr);

    if(CLICK_LINE_BUTTON == buttonFlag && getSelectFlag()){
        painter->setPen(Qt::green);
        painter->drawRect(-40, -30, 80, 60);
    }

}
//! [11]
QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, edgeList)
            edge->adjust();
        graph->itemMoved();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}
//! [11]

void Node::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug()<<"show the tool tip"<<endl;

    QString str = "route table:\n";
    route item;

    foreach (item, rt.routeItem) {
        str += iptostr(item.ipv4addr) + QString(" gw ") + iptostr(item.nexthop) + QString("\n");
    }

    this->setToolTip(str);
}

void Node::setSelectFlag(bool flag)
{
    selectFlag = flag;
}

bool Node::getSelectFlag()
{
    return selectFlag;
}

//! [12]
void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(CLICK_LINE_BUTTON == buttonFlag){
        qDebug()<<"Get the Node info!\r\n"<<endl;
        if(nodeInfoManager.curNode == NULL && nodeInfoManager.lasterNode == NULL){
            qDebug()<<"Get the Node info debug 1!\r\n"<<endl;
            nodeInfoManager.curNode = this;
            nodeInfoManager.curNode->setSelectFlag(true);

        }else if(nodeInfoManager.curNode != NULL && nodeInfoManager.lasterNode == NULL){
           qDebug()<<"Get the Node info debug 2!\r\n"<<endl;
           nodeInfoManager.lasterNode = this;

           nodeInfoManager.g_scene->addItem(new Edge(nodeInfoManager.curNode, nodeInfoManager.lasterNode));

           nodeInfoManager.curNode->setSelectFlag(false);
           nodeInfoManager.curNode->update();

           nodeInfoManager.curNode = NULL;
           nodeInfoManager.lasterNode = NULL;

        }else{
           qDebug()<<"Get the Node info debug 3!\r\n"<<endl;
           ;
        }
    }

    update();
    QGraphicsItem::mousePressEvent(event);

    if(CLICK_DELETE_BUTTON == buttonFlag){
        foreach (Edge *edge, edgeList)
            if(edge != NULL)
                nodeInfoManager.g_scene->removeItem(edge);

        nodeInfoManager.nodeList.removeOne(this);
        nodeInfoManager.g_scene->removeItem(this);
    }
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

void Node::setIPv4addr(quint32 addr)
{
    this->ipv4addr = addr;
}

void Node::setIPv4mask(quint32 addr)
{
    this->ipv4mask = addr;
}

void Node::setNodeNum(quint32 num)
{
    this->nodeNum = num;
}

quint32 Node::get_ipv4addr()
{
    return ipv4addr;
}

quint32 Node::get_nodeNum()
{
    return nodeNum;
}

rtable* Node::get_rtable()
{
    return &rt;
}

//! [12]
