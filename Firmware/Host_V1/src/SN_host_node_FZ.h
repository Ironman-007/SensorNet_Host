#pragma once

#include <Arduino.h>
#include <Wire.h>

#include "SN_host_comm_FZ.h"
#include "SN_host_system_FZ.h"

// define a class named SN_node
class SN_node
{
private:
    /* data */
public:
    SN_node(/* args */);
    ~SN_node();
};

SN_node::SN_node(/* args */)
{
}

SN_node::~SN_node()
{
}

extern void SN_host_scan_node(void);



