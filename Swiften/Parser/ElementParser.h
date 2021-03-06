/*
 * Copyright (c) 2010-2014 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <boost/shared_ptr.hpp>

#include <string>
#include <Swiften/Base/API.h>
#include <Swiften/Elements/ToplevelElement.h>
#include <Swiften/Parser/AttributeMap.h>

namespace Swift {
	class SWIFTEN_API ElementParser {
		public:
			virtual ~ElementParser();

			virtual void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) = 0;
			virtual void handleEndElement(const std::string& element, const std::string& ns) = 0;
			virtual void handleCharacterData(const std::string& data) = 0;

			virtual boost::shared_ptr<ToplevelElement> getElement() const = 0;
	};
}
