#pragma once

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp-test/UnitTest.hpp"

class PetDTOTest : public oatpp::test::UnitTest {
public:
    using ObjectMapper = oatpp::parser::json::mapping::ObjectMapper;

private:
    std::shared_ptr<ObjectMapper> objectMapper;

public:
    PetDTOTest();

    void onRun() override;
};
