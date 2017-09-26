// njs_messages.h

#ifndef __NJS_MESSAGES_H__
#define __NJS_MESSAGES_H__

#include <string>
using namespace std;

typedef enum
{
  errSuccess = 0,
  errMissingCallback,
  errInvalidPool,
  errInvalidConnection,
  errInvalidPropertyValue,
  errInvalidParameterValue,
  errInvalidParameterType,
  errInvalidPropertyValueInParam,
  errInvalidPropertyTypeInParam,
  errInvalidNumberOfParameters,
  errUnsupportedDatType,
  errBindValueAndTypeMismatch,
  errInvalidBindDataType,
  errInvalidBindDirection,
  errReadOnly,
  errNoTypeForConversion,
  errInsufficientBufferForBinds,
  errBusyResultSet,
  errInvalidResultSet,
  errInvalidNonQueryExecution,
  errEmptyArrayForFetchAs,
  errInvalidTypeForConversion,
  errInvalidLob,
  errBusyLob,
  errInsufficientMemory,
  errResultsTooLarge,
  errInvalidmaxRows,
  errSQLSyntaxError,
  errBufferReturningInvalid,
  errInvalidJSObject,
  errBusyConnLOB,
  errBusyConnRS,
  errBusyConnDB,
  errInternalError,
  errInvalidTypeForArrayBind,
  errReqdMaxArraySize,
  errInvalidArraySize,
  errIncompatibleTypeArrayBind,
  errInvalidValueArrayBind,
  errEmptyArray,
  errConnRequestTimeout,
  errCannotConvertRsToStream,
  errCannotInvokeRsMethods,
  errResultSetAlreadyConverted,
  errNamedJSON,
  errCannotLoadBinary,
  errPoolWithAliasAlreadyExists,
  errPoolWithAliasNotFound,
  errLOBBindActive,
  errBusyConnTEMPLOB,
  errBindValueTooLarge,
  errMaxValueTooLarge,
  errIncompatibleTypeArrayIndexBind,

  // New ones should be added here

  errMaxErrors                // Max # of errors plus one
} NJSErrorType;

class NJSMessages
{
public:
  static string getErrorMsg ( NJSErrorType err, ... );
};



#endif   /* __NJS_MESSAGES_H__ */

