#pragma once
#include "User.h"

class Administrator : public User {
private:
    static Administrator* instance;

    Administrator(const std::string& username,
        const std::string& password);

    Administrator(unsigned int id,
        const std::string& username,
        const std::string& password);

protected:
    void print(std::ostream& os) const override;

public:
    Administrator(const Administrator&) = delete;
    Administrator& operator=(const Administrator&) = delete;

    ~Administrator() override = default;

    static Administrator& getInstance();

    static Administrator& getInstance(unsigned int id,
        const std::string& username,
        const std::string& password);

    static void destroyInstance();

    bool canManageUsers() const override;
    bool canManageProjects() const override;
    bool canSaveLoadData() const override;
   
};