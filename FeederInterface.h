//
// Created by  ScaleTrade on 02.03.2026.
//
#pragma once
#include "string"
#include <rapidjson/document.h>
#include "Structures.h"
using namespace rapidjson;

inline int FEEDER_VERSION_API = 128;

enum FeederState {
    DISCONNECTED = 0,
    CONNECTED = 1,
    STREAMING = 2
};

struct StateFeeder {
    time_t   last_tick= 0;
    time_t   last_ping= 0;
    int      state = 0;
};

class FeederInterface {
public:
    virtual ~FeederInterface() = default;
    virtual int getApiVersion() const { return FEEDER_VERSION_API; }
    virtual std::string feeder_name() const { return "Demo feeder"; };
    virtual std::string feeder_description() const { return "Demo feeder"; }
    virtual int CustomAction(Value& req, Value& res, Document::AllocatorType& allocator) { return RET_OK_NONE; }
    virtual int GetState(StateFeeder *state) { return RET_OK_NONE; }
};