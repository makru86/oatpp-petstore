#pragma once

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp-test/UnitTest.hpp"

class ApiResponseDTOTest : public oatpp::test::UnitTest {
public:
    using ObjectMapper = oatpp::parser::json::mapping::ObjectMapper;

private:
    std::shared_ptr<ObjectMapper> objectMapper;

public:
    ApiResponseDTOTest();

    void onRun() override;
};
