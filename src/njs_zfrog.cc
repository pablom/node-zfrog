// njs_zfrog.cc

#include <node.h>
#include <uv.h>
#include <sstream>
#include "njs_zfrog.h"
#include "njs_messages.h"
#include "njs_utils.h"

/* peristent njs_zFrog class handle */
Nan::Persistent<v8::FunctionTemplate> njs_zFrog::zfrogTemplate_s;

/*****************************************************************************
*   DESCRIPTION
*     Constructor for the njs_zFrog class
 *****************************************************************************/
njs_zFrog::njs_zFrog()
{
    int cpu_count = 0;
    uv_cpu_info_t* cpu_infos = nullptr;

    if( !uv_cpu_info( &cpu_infos, &cpu_count) )
        worker_count = cpu_count;

    /* Delete allocated structure */
    if( cpu_infos )
        uv_free_cpu_info(cpu_infos, cpu_count);
}
/*****************************************************************************
*   DESCRIPTION
*     Destructor for the njs_zFrog class
*****************************************************************************/
njs_zFrog::~njs_zFrog()
{
}
/*****************************************************************************
*   DESCRIPTION
*     Init function of the Oracledb class.
*     Initiates and maps the functions and properties of Oracledb class.
*****************************************************************************/
void njs_zFrog::Init( v8::Handle<v8::Object> target )
{
    Nan::HandleScope scope;

    v8::Local<v8::FunctionTemplate> temp = Nan::New<v8::FunctionTemplate>(New);
    temp->InstanceTemplate()->SetInternalFieldCount(1);
    temp->SetClassName(Nan::New<v8::String>("zFrog").ToLocalChecked());

    //Nan::SetPrototypeMethod(temp, "getConnection", GetConnection);
    Nan::SetPrototypeMethod(temp, "createServer", createServer);

    Nan::SetAccessor( temp->InstanceTemplate(), Nan::New<v8::String>("workers").ToLocalChecked(), njs_zFrog::GetWorkersCount, njs_zFrog::SetWorkersCount );

    zfrogTemplate_s.Reset(temp);
    Nan::Set(target, Nan::New<v8::String>("zFrog").ToLocalChecked(),temp->GetFunction());
}
/*****************************************************************************
*   DESCRIPTION
*     Invoked when new of njs_zFrog is called from JS
*****************************************************************************/
NAN_METHOD(njs_zFrog::New)
{
    njs_zFrog *obj = new njs_zFrog();

    obj->Wrap(info.Holder());
    obj->jsZfrog.Reset( info.Holder() );
    info.GetReturnValue().Set(info.Holder());
}
/*****************************************************************************
*   DESCRIPTION
*     Invoked when require on zfrog is called
*
*   PARAMETERS:
*     Target Object
*****************************************************************************/
extern "C"
{
   static void init( v8::Handle<v8::Object> target )
   {
      njs_zFrog::Init(target);
   }

   NODE_MODULE(zfrog, init)
}
/*****************************************************************************
*   DESCRIPTION
*     Get Accessor of worker count property
*****************************************************************************/
NAN_GETTER(njs_zFrog::GetWorkersCount)
{
    njs_zFrog* obj = Nan::ObjectWrap::Unwrap<njs_zFrog>(info.Holder());
    NJS_CHECK_OBJECT_VALID2(obj, info);
    info.GetReturnValue().Set(obj->worker_count);
}
/*****************************************************************************
*   DESCRIPTION
*     Set Accessor of worker count property
*****************************************************************************/
NAN_SETTER(njs_zFrog::SetWorkersCount)
{
    njs_zFrog* obj = Nan::ObjectWrap::Unwrap<njs_zFrog>(info.Holder());
    NJS_CHECK_OBJECT_VALID(obj);
    NJS_SET_PROP_UINT(obj->worker_count, value, "workers");
}
/*****************************************************************************
*   DESCRIPTION
*     createServer method on zFrog class
*
*   PARAMETERS:
*     Arguments - server attributes as JSON object,
*                 Callback
*****************************************************************************/
NAN_METHOD(njs_zFrog::createServer)
{
    Nan::HandleScope scope;

    v8::Local<v8::Function> callback;
    v8::Local<v8::Object> serverProps;
    NJS_GET_CALLBACK ( callback, info );

    njs_zFrog* obj = Nan::ObjectWrap::Unwrap<njs_zFrog> ( info.Holder() );
}
