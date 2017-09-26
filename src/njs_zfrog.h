// njs_zfrog.h


#include <v8.h>
#include <node.h>
#include <nan.h>

#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>


using namespace node;
using namespace v8;


class njs_zFrog: public Nan::ObjectWrap
{
public:

    Nan::Persistent<v8::Object> jsZfrog;

    /* zFrog class */
    static void Init( v8::Handle<v8::Object> target );

private:

    /* Define zFrog Constructor */
    static Nan::Persistent<v8::FunctionTemplate> zfrogTemplate_s;

    static NAN_METHOD(New);

    /* Default constructor */
    njs_zFrog();
    /* Destructor */
    ~njs_zFrog();

    /* Create server Methods */
    static NAN_METHOD(createServer);


    /* Define Getter Accessors to Properties */
    static NAN_GETTER(GetWorkersCount);

    /* Define Setter Accessors to Properties */
    static NAN_SETTER(SetWorkersCount);

private:
    /* Number of worker count */
    uint8_t	worker_count;
};
