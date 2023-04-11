#pragma once

#include "dto/UserDTO.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/core/async/Coroutine.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UserController : public oatpp::web::server::api::ApiController {
    typedef UserController __ControllerType;

public:
    explicit UserController(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(objectMapper) {}

    ENDPOINT_INFO(createUser) {
        info->summary = "Create user";
        info->addConsumes < Object < UserDTO >> ("application/json");
    };

    ENDPOINT_ASYNC("POST", "/user", createUser) {

    ENDPOINT_ASYNC_INIT(createUser)

        Action act() override {
            return request->readBodyToDtoAsync<oatpp::Object<UserDTO>>(
                    controller->getDefaultObjectMapper()
            ).callbackTo(&createUser::returnResponse);
        }

        Action returnResponse(const oatpp::Object<UserDTO> &dto) {
            return _return(controller->createResponse(Status::CODE_200, "OK"));
        }
    };
};

#include OATPP_CODEGEN_END(ApiController)