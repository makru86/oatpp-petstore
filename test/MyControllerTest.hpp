//
// Created by Leonid  on 2019-06-07.
//

#ifndef MyControllerTest_hpp
#define MyControllerTest_hpp

#include "oatpp-test/UnitTest.hpp"

class MyControllerTest : public oatpp::test::UnitTest {
public:

  MyControllerTest() : UnitTest("TEST[MyControllerTest]"){}
  void onRun() override;

};

#endif // MyControllerTest_hpp
