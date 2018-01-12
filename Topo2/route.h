#ifndef ROUTE_H
#define ROUTE_H

#include <QList>

typedef struct Route{
    quint32 ipv4addr;
    quint32 nexthop;
}route;

typedef struct RouteTable{
    QList<route> routeItem;
}rtable;

#endif // ROUTE_H
