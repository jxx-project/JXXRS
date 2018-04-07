#include "OS/Keystone/V3/Model/Error.h"

namespace OS { namespace Keystone { namespace V3 { namespace Model {

Error::Error()
{
}

Error::Error(const JXXON::Json &json) :
		OS::API::Model::Error(json),
		identity(json.get<decltype(identity)>("identity"))
{
}

JXXON::Json Error::toJson() const
{
	JXXON::Json json = API::Model::Error::toJson();
	json.set("identity", identity);
	return json;
}

}}}} // namespace OS::Keystone::V3::Model
