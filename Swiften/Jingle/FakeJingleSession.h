/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

/*
 * Copyright (c) 2013-2015 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>
#include <boost/variant.hpp>

#include <Swiften/Base/API.h>
#include <Swiften/Base/SimpleIDGenerator.h>
#include <Swiften/Base/boost_bsignals.h>
#include <Swiften/Base/Override.h>
#include <Swiften/JID/JID.h>
#include <Swiften/Elements/JinglePayload.h>
#include <Swiften/Jingle/JingleSession.h>
#include <Swiften/Jingle/JingleContentID.h>

namespace Swift {
	class JingleContentID;

	class SWIFTEN_API FakeJingleSession : public JingleSession {
		public:
		struct InitiateCall {
			InitiateCall(JingleContentID contentId, JingleDescription::ref desc, JingleTransportPayload::ref payL) : id(contentId), description(desc), payload(payL) {}
			JingleContentID id;
			JingleDescription::ref description;
			JingleTransportPayload::ref payload;
		};

		struct  TerminateCall {
			TerminateCall(JinglePayload::Reason::Type r) : reason(r) {}
			JinglePayload::Reason::Type reason;
		};

		struct InfoCall {
			InfoCall(boost::shared_ptr<Payload> info) : payload(info) {}
			boost::shared_ptr<Payload> payload;
		};

		struct AcceptCall {
			AcceptCall(JingleContentID contentId, JingleDescription::ref desc, JingleTransportPayload::ref payL) : id(contentId), description(desc), payload(payL) {}
			JingleContentID id;
			JingleDescription::ref description;
			JingleTransportPayload::ref payload;
		};

		struct InfoTransportCall {
			InfoTransportCall(JingleContentID contentId, JingleTransportPayload::ref payL) : id(contentId), payload(payL) {}
			JingleContentID id;
			JingleTransportPayload::ref payload;
		};

		struct AcceptTransportCall {
			AcceptTransportCall(JingleContentID contentId, JingleTransportPayload::ref payL) : id(contentId), payload(payL) {}
			JingleContentID id;
			JingleTransportPayload::ref payload;
		};

		struct RejectTransportCall {
			RejectTransportCall(JingleContentID contentId, JingleTransportPayload::ref payL) : id(contentId), payload(payL) {}
			JingleContentID id;
			JingleTransportPayload::ref payload;
		};
		
		struct ReplaceTransportCall {
			ReplaceTransportCall(JingleContentID contentId, JingleTransportPayload::ref payL) : id(contentId), payload(payL) {}
			JingleContentID id;
			JingleTransportPayload::ref payload;
		};

		typedef boost::variant<InitiateCall, TerminateCall, AcceptCall, InfoCall, InfoTransportCall, AcceptTransportCall, RejectTransportCall, ReplaceTransportCall> Command;

		public:
			typedef boost::shared_ptr<FakeJingleSession> ref;

			FakeJingleSession(const JID& initiator, const std::string& id);
			virtual ~FakeJingleSession();

			virtual void sendInitiate(const JingleContentID&, JingleDescription::ref, JingleTransportPayload::ref) SWIFTEN_OVERRIDE;
			virtual void sendTerminate(JinglePayload::Reason::Type reason) SWIFTEN_OVERRIDE;
			virtual void sendInfo(boost::shared_ptr<Payload>) SWIFTEN_OVERRIDE;
			virtual void sendAccept(const JingleContentID&, JingleDescription::ref, JingleTransportPayload::ref = JingleTransportPayload::ref()) SWIFTEN_OVERRIDE;
			virtual std::string sendTransportInfo(const JingleContentID&, JingleTransportPayload::ref) SWIFTEN_OVERRIDE;
			virtual void sendTransportAccept(const JingleContentID&, JingleTransportPayload::ref) SWIFTEN_OVERRIDE;
			virtual void sendTransportReject(const JingleContentID&, JingleTransportPayload::ref) SWIFTEN_OVERRIDE;
			virtual void sendTransportReplace(const JingleContentID&, JingleTransportPayload::ref) SWIFTEN_OVERRIDE;

			void handleSessionTerminateReceived(boost::optional<JinglePayload::Reason>);
			void handleSessionAcceptReceived(const JingleContentID&, boost::shared_ptr<JingleDescription>, boost::shared_ptr<JingleTransportPayload>);
			void handleSessionInfoReceived(boost::shared_ptr<JinglePayload>);

			void handleTransportReplaceReceived(const JingleContentID&, JingleTransportPayload::ref);
			void handleTransportAcceptReceived(const JingleContentID&, boost::shared_ptr<JingleTransportPayload>);
			void handleTransportInfoReceived(const JingleContentID&, boost::shared_ptr<JingleTransportPayload>);
			void handleTransportRejectReceived(const JingleContentID&, boost::shared_ptr<JingleTransportPayload>);
			void handleTransportInfoAcknowledged(const std::string& id);

		public:
			std::vector<Command> calledCommands;
			SimpleIDGenerator idGenerator;
	};
}
