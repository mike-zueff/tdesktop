/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "platform/platform_notifications_manager.h"
#include "base/weak_ptr.h"

namespace Platform {
namespace Notifications {

class Manager
	: public Window::Notifications::NativeManager
	, public base::has_weak_ptr {
public:
	Manager(not_null<Window::Notifications::System*> system);
	void clearNotification(NotificationId id);
	~Manager();

protected:
	void doShowNativeNotification(
		not_null<PeerData*> peer,
		std::shared_ptr<Data::CloudImageView> &userpicView,
		MsgId msgId,
		const QString &title,
		const QString &subtitle,
		const QString &msg,
		bool hideNameAndPhoto,
		bool hideReplyButton) override;
	void doClearAllFast() override;
	void doClearFromHistory(not_null<History*> history) override;
	void doClearFromSession(not_null<Main::Session*> session) override;
	bool doSkipAudio() const override;
	bool doSkipToast() const override;
	bool doSkipFlashBounce() const override;

private:
	class Private;
	const std::unique_ptr<Private> _private;

};

} // namespace Notifications
} // namespace Platform
