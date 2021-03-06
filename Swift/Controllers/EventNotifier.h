/*
 * Copyright (c) 2010 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <boost/shared_ptr.hpp>

#include "SwifTools/Notifier/Notifier.h"
#include "Swiften/Base/boost_bsignals.h"
#include "Swift/Controllers/XMPPEvents/StanzaEvent.h"
#include "Swiften/JID/JID.h"

namespace Swift {
	class EventController;
	class Notifier;
	class AvatarManager;
	class NickResolver;
	class JID;
	class UIEventStream;
	class SettingsProvider;

	class EventNotifier {
		public:
			EventNotifier(EventController* eventController, Notifier* notifier, AvatarManager* avatarManager, NickResolver* nickResolver);
			~EventNotifier();

			boost::signal<void (const JID&)> onNotificationActivated;

		private:
			void handleEventAdded(boost::shared_ptr<StanzaEvent>);
			void handleNotificationActivated(JID jid);

		private:
			EventController* eventController;
			Notifier* notifier;
			AvatarManager* avatarManager;
			NickResolver* nickResolver;
	};
}
