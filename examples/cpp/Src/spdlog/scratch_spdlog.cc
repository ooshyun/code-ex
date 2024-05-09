#include <iostream>
#include <spdlog/spdlog.h>

void check_type(const std::type_info& type) {
    if (type == typeid(int)) {
        std::cout << "Argument type is int" << std::endl;
    } else if (type == typeid(double)) {
        std::cout << "Argument type is double" << std::endl;
    } else if (type == typeid(const char*)) {
        std::cout << "Argument type is const char*" << std::endl;
    } else {
        std::cout << "Unknown argument type" << std::endl;
    }
}

// Parse spdlog format string and print using printf
void _log_printf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    std::string formated;
    const char* p = fmt;
    while (*p) {
        if (*p == '{') {
            const char* end = strchr(p, '}');
            if (end) {
                // Determine the type and print accordingly
                std::string token(p + 1, end);
                // int ascii = static_cast<int>(token[0]);
                // if (token == "}") {
                //     // printf("}");
                // } else if (ascii >= 48 && ascii <= 57) {
                //     printf("%s", token.c_str());
                // } else if (token == "s") {
                if (token == "s") {
                    const char* str = va_arg(args, const char*);
                    printf("%s", str);
                    formated += str;
                } else if (token == "d") {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    formated += std::to_string(num);
                }
                p = end + 1;
            }
        } else {
            putchar(*p);
            formated += *p;
            p++;
        }
    }
    va_end(args);
    printf("\n");
    spdlog::info("Formatted: {}", formated);
}

template<typename FormatString,
  // typename std::enable_if<fmt::detail::is_compile_string<FormatString>::value, int>::type = 0,
  typename... Args>
void log_printf(const FormatString& fmt, const Args&... args)  {
    const char* fmt_str;
    printf("Type of fmt: %s\n", typeid(fmt).name());
    if (typeid(fmt) == typeid(std::string)) {
        printf("String type of fmt: %s\n", typeid(fmt).name());
        // fmt_str = fmt.c_str();
    } else {
        printf("Char type of fmt: %s\n", typeid(fmt).name());
        // fmt_str = fmt;
    }
    // _log_printf(fmt_str, args...);
}

void test_spdlog_scratch(void) {
    spdlog::info("This is a test message with {} and {}", "spdlog", 123);
    log_printf("This is a test message with {s} and {d}", "printf", 123);

    std::string fmt = "This is a test message";
    log_printf(fmt.c_str());
    log_printf(fmt);
}