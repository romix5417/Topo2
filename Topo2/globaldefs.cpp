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

            while(!queue.isEmpty()){
                qDebug()<<queue.dequeue()->get_nodeNum();
            }

            qDebug()<<endl;
        }


    }
}
