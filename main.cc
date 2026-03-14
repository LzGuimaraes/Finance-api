#include <drogon/drogon.h>

using namespace drogon;

int main() {
    app().loadConfigFile("../config.json");

    LOG_INFO << "Servidor iniciado";

    app().run();
}