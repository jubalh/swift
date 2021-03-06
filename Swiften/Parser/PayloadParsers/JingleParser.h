/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

/*
 * Copyright (c) 2015 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <Swiften/Base/API.h>
#include <Swiften/Elements/JinglePayload.h>
#include <Swiften/Parser/GenericPayloadParser.h>
#include <Swiften/Parser/PayloadParserFactoryCollection.h>

namespace Swift {

class SWIFTEN_API JingleParser : public GenericPayloadParser<JinglePayload> {
		public:
			JingleParser(PayloadParserFactoryCollection* factories);

			virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
			virtual void handleEndElement(const std::string& element, const std::string&);
			virtual void handleCharacterData(const std::string& data);
		
		private:
			JinglePayload::Action stringToAction(const std::string &str) const;
			
		private:
			PayloadParserFactoryCollection* factories;
			int level;
			boost::shared_ptr<PayloadParser> currentPayloadParser;
};

}

