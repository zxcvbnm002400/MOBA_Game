#include "Manager.h"

Manager * Manager::m_manager = NULL;

Manager * Manager::getInstance() {
	if (m_manager == NULL) {
		m_manager = new Manager();
	}
	return m_manager;
}

void Manager::freeInstance(void) {
	if (m_manager != NULL) {
		delete m_manager;
		m_manager = NULL;
	}
}