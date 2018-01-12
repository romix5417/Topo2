#include "globaldefs.h"
#include "node.h"
#include "edge.h"

#include <QQueue>
#include <QDebug>

NManager nodeInfoManager;


quint32 get_ipv4addr(quint32 number)
{
    return nodeInfoManager.ipv4addrPool+number;
}

quint32 get_nodenumber()
{
    nodeInfoManager.nodePool +=1;
    return nodeInfoManager.nodePool;
}

quint32 get_ipv4mask()
{
    return nodeInfoManager.ipv4addrMask;
}

QString iptostr(quint32 ipv4addr)
{
    char stripv4addr[16]={0};
    unsigned char *charipv4addr =  (unsigned char*)(&ipv4addr);
    //qDebug()<<"ipv4addr:"<<hex<<charipv4addr[0]<<endl;
    //qDebug()<<"ipv4addr:"<<hex<<charipv4addr[1]<<endl;
    //qDebug()<<"ipv4addr:"<<hex<<charipv4addr[2]<<endl;
    //qDebug()<<"ipv4addr:"<<hex<<charipv4addr[3]<<endl;

    sprintf(stripv4addr,"%d.%d.%d.%d",charipv4addr[3], charipv4addr[2], charipv4addr[1], charipv4addr[0]);
    //qDebug()<<stripv4addr<<endl;

    return QString(stripv4addr);
}

void node_recur(QQueue<Node *> &queue, Node *node)
{
    QList<Edge *> edgeList;
    Edge *edge = NULL;
    Node *tempNode = NULL;

    edgeList = node->edges();

    foreach (edge, edgeList) {
        tempNode = edge->destNode();
        if(tempNode != node){
            if(queue.indexOf(tempNode) != -1){
                continue;
            }
            queue.enqueue(tempNode);
        }else{
            tempNode = edge->sourceNode();
            if(queue.indexOf(tempNode) != -1){
                continue;
            }
            queue.enqueue(tempNode);
        }

        node_recur(queue, tempNode);
    }
}

void route_resolving(QQueue<Node *> &queue)
{
    Node *firstNode = NULL, *secNode = NULL, *tempNode = NULL;
    route routeItem;
    quint32 addr, gwaddr;
    rtable *rt = NULL;

    if(!queue.isEmpty()){
        firstNode = queue.dequeue();
        rt = firstNode->get_rtable();
    }

    if(!queue.isEmpty()){
        secNode = queue.dequeue();
        addr = secNode->get_ipv4addr();
        gwaddr = addr;
        routeItem.ipv4addr = addr;
        routeItem.nexthop = gwaddr;


        rt->routeItem << routeItem;
    }

    while(!queue.isEmpty()){
        tempNode = queue.dequeue();
        addr = tempNode->get_ipv4addr();

        routeItem.ipv4addr = addr;
        routeItem.nexthop = gwaddr;

        rt->routeItem << routeItem;
    }

}

void calculate_route()
{
    QList<Node *> nodeList = nodeInfoManager.nodeList;
    Node *node = NULL, *tempNode = NULL;
    Edge *edge = NULL;
    QQueue<Node *> queue;
    QList<Edge *> edgeList;

    foreach (node, nodeList) {

        edgeList = node->edges();

        foreach (edge, edgeList) {
            queue.enqueue(node);
            tempNode = edge->destNode();
            if( tempNode != node){
                queue.enqueue(tempNode);
            }else{
                tempNode = edge->sourceNode();
                queue.enqueue(tempNode);
            }

            node_recur(queue, tempNode);

            route_resolving(queue);
        }
    }
}
