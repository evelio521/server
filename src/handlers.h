/***************************************************************************
 * 
 * Copyright (c) 2016 evelio, Inc. All Rights Reserved
 *
 * *************************************************************************/

/**
 * @file:   handlers.h
 * @author: sunqiang(evelio@126.com)
 * @date:   2016-04-23 11:01:46
 * @brief
 *
 **/
#ifndef SERVER_SRC_HANDLERS_H_
#define SERVER_SRC_HANDLERS_H_

#include <string>

#include "base/marcos.h"
#include "base/basictypes.h"
#include "base/compat.h"
//#include "base/callback.h"

_START_SERVER_NAMESPACE_

class Request;
class Response;


class Handler {
 public:
  Handler(string regpath);
  virtual ~Handler();
  virtual string GetClassName();
  virtual string GetPathName() = 0;
  virtual bool HttpHandler(Request* request, Response* response) = 0;

 protected:
  string path;

 private:
  DISALLOW_COPY_AND_ASSIGN(Handler);
};

class DefaultHandler : public Handler {
 public:
  DefaultHandler(string regpath);
  virtual ~DefaultHandler();
  virtual string GetClassName();
  virtual string GetPathName();
  virtual bool Excute(Request* request, Response* response, const In &in) = 0;
  //  Call callback function, then send back response.
  virtual bool HttpHandler(Request* request, Response* response);

 private:
  DISALLOW_COPY_AND_ASSIGN(DefaultHandler);
};

class JsonHandler : public Handler {
 public:
  JsonHandler(string regpath);
  virtual ~JsonHandler();
  virtual string GetClassName();
  virtual string GetPathName();
  virtual bool Excute(Request* request, Response* response, const In &in) = 0;
  //  Call callback function, then send back response.
  virtual bool HttpHandler(Request* request, Response* response);

 private:
  DISALLOW_COPY_AND_ASSIGN(JsonHandler);
};

class BinaryHandler : public Handler {
 public:
  BinaryHandler(string regpath);
  virtual ~BinaryHandler();
  virtual string GetClassName();
  virtual string GetPathName();
  virtual bool Excute(Request* request, Response* response, const  In &in) = 0;
  //  Call callback function, then send back response.
  virtual bool HttpHandler(Request* request, Response* response);

 private:
  DISALLOW_COPY_AND_ASSIGN(BinaryHandler);
};

_END_SERVER_NAMESPACE_

#endif  // SERVER_SRC_HANDLERS_H_

