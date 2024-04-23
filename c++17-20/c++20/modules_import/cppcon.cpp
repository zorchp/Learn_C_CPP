// cppcon.cpp
export module cppcon;

namespace CppCon {
auto GetWelcomeHelper() { return "Welcome to CppCon 2021!"; }

export auto GetWelcome() { return GetWelcomeHelper(); }
} // namespace CppCon
