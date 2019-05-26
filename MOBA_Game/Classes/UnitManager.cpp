#include "UnitManager.h"

UnitManager * UnitManager::m_manager = NULL;

//在构造函数的初始化列表中初始化数组
UnitManager::UnitManager() : m_unitVector() { }

UnitManager * UnitManager::getInstance() {
	if (m_manager == NULL) {
		m_manager = new UnitManager();
	}
	return m_manager;
}

void UnitManager::freeInstance(void) {
	if (m_manager != NULL) {
		delete m_manager;
		m_manager = NULL;
	}
}