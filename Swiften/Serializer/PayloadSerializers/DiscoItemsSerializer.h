/*
 * Copyright (c) 2010 Kevin Smith
 * Licensed under the GNU General Public License v3.
 * See Documentation/Licenses/GPLv3.txt for more information.
 */

#pragma once

#include "Swiften/Serializer/GenericPayloadSerializer.h"
#include "Swiften/Elements/DiscoItems.h"

namespace Swift {
	class DiscoItemsSerializer : public GenericPayloadSerializer<DiscoItems> {
		public:
			DiscoItemsSerializer();

			virtual String serializePayload(boost::shared_ptr<DiscoItems>)  const;
	};
}

