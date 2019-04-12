#ifndef HTTP_SERVER_09_HTTP_STATUS_H
#define HTTP_SERVER_09_HTTP_STATUS_H

#include "http_string.h"

#define HTTP_STATUS_OK                      200
#define HTTP_STATUS_CREATED                 201
#define HTTP_STATUS_ACCEPTED                202
#define HTTP_STATUS_NO_CONTENT              204

#define HTTP_STATUS_MOVED_PERMANENTLY       301
#define HTTP_STATUS_MOVED_TEMPORARELY       302
#define HTTP_STATUS_NOT_MODIFIED            304

#define HTTP_STATUS_BAD_REQUEST             400
#define HTTP_STATUS_UNAUTHORIZED            401
#define HTTP_STATUS_FORBIDDEN               403
#define HTTP_STATUS_NOT_FOUND               404

#define HTTP_STATUS_INTERNAL_SERVER_ERROR   500
#define HTTP_STATUS_NOT_IMPLEMENTED         501
#define HTTP_STATUS_BAD_GATEWAY             502
#define HTTP_STATUS_SERVICE_UNAVAILABLE     503



/**
 * Returns a string, containing the status code and the human readable description.
 * For example "200 OK".
 *
 * @param statusCode Rhe status code to generate string for.
 * @return The status string.
 */
string *getStatusString(int statusCode);


#endif //HTTP_SERVER_09_HTTP_STATUS_H