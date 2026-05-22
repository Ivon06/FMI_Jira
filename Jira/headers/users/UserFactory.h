#include "User.h"
#include <string>
#include <memory>

class UserFactory {
public:
	static std::unique_ptr<User> createUser(const std::string& username, const std::string& password, const std::string& roleStr);

	static std::unique_ptr<User> restoreUser(unsigned int id, const std::string& username, const std::string& password, const std::string& roleStr);
};