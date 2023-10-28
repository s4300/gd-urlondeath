#include <Geode/Geode.hpp>
#include <Geode/utils/string.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/cocos/platform/CCApplicationProtocol.h>

using namespace geode::prelude;

class $modify(PlayerObject) {
	void playDeathEffect() {
		// Open link in browser
		auto link = Mod::get()->getSettingValue<std::string>("link-to-open");
		CCApplication::sharedApplication()->openURL(link.c_str());
		// Restart level, then pause
		PlayLayer::get()->resumeAndRestart();
		PlayLayer::get()->pauseGame(true);
	}
};
