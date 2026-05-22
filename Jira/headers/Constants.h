#pragma once

namespace Constants {

    namespace User {
        constexpr size_t MIN_USERNAME_LENGTH = 3;
        constexpr size_t MAX_USERNAME_LENGTH = 30;

        constexpr size_t MIN_PASSWORD_LENGTH = 6;
        constexpr size_t MAX_PASSWORD_LENGTH = 64;
    }

    namespace Task {
        constexpr size_t MAX_TITLE_LENGTH = 100;

        constexpr int MIN_POINTS = 0;

        constexpr double MIN_GRADE = 2.0;
        constexpr double MAX_GRADE = 6.0;
    }

    namespace Project {
        constexpr size_t MAX_NAME_LENGTH = 100;
        constexpr size_t MAX_DESCRIPTION_LENGTH = 500;
    }

    namespace Stage {
        constexpr size_t MAX_NAME_LENGTH = 100;
    }
}