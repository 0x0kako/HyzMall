#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "initializer\client_initializer.h"
#include "http\requester.h"
#include "task\task_manager.h"

#include <thread>

int main(){

	// Faz a requisição confirmando o check_alive.
	initializer::client_initializer::get()->run();

	// Faz a requisição com o servidor e adiciona as tasks
	http::requester::get()->run();

	// Executa classe com base nas tasks adicionadas
	task_manager::get()->run();


	std::this_thread::sleep_for(
		std::chrono::milliseconds((uint32_t)-1)
	);
    return 0;
}

