#ifndef MyApiTestClient_hpp
#define MyApiTestClient_hpp

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "dto/UserDTO.hpp"

/* Begin Api Client code generation */
#include OATPP_CODEGEN_BEGIN(ApiClient)

/**
 * Test API client.
 * Use this client to call application APIs.
 */
class MyApiTestClient : public oatpp::web::client::ApiClient {

API_CLIENT_INIT(MyApiTestClient)

    API_CALL("GET", "/hello", getHello)
l
    API_CALL("GET", "/", getRoot)

    API_CALL("POST", "/user", createUser, BODY_DTO(Object<UserDTO>, dto))
};

/* End Api Client code generation */
#include OATPP_CODEGEN_END(ApiClient)

#endif // MyApiTestClient_hpp
