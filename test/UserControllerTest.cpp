#include "UserControllerTest.hpp"

#include "controller/UserController.hpp"

#include "app/MyApiTestClient.hpp"
#include "app/TestComponent.hpp"

#include "oatpp/web/client/HttpRequestExecutor.hpp"

#include "oatpp-test/web/ClientServerTestRunner.hpp"

void UserControllerTest::onRun() {

  /* Register test components */
  TestComponent component;

  /* Create client-server test runner */
  oatpp::test::web::ClientServerTestRunner runner;

  /* Add UserController endpoints to the router of the test server */
  runner.addController(std::make_shared<UserController>());

  /* Run test */
  runner.run([] {

    /* Get client connection provider for Api Client */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ClientConnectionProvider>, clientConnectionProvider);

    /* Get object mapper component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper);

    /* Create http request executor for Api Client */
    auto requestExecutor = oatpp::web::client::HttpRequestExecutor::createShared(clientConnectionProvider);

    /* Create Test API client */
    auto client = MyApiTestClient::createShared(requestExecutor, objectMapper);

    /* Call server API */
    auto dto = UserDTO::createShared();
    auto response = client->createUser(dto);

    /* Assert that server responds with 200 */
    OATPP_ASSERT(response->getStatusCode() == 200)

  }, std::chrono::minutes(10) /* test timeout */);

    OATPP_COMPONENT(std::shared_ptr<oatpp::async::Executor>, executor);
    executor->waitTasksFinished();
    executor->stop();
    executor->join();
    OATPP_ASSERT(executor->getTasksCount() == 0)

}
